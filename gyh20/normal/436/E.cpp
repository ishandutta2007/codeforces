#include<bits/stdc++.h>
#define re register
#define int long long
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,a[300002],b[300002],inf=1e14;
char Z[300002];
long long ans;
struct node{
	int x,y;
	bool operator <(const node A)const{return y==A.y?x<A.x:y<A.y;}
	bool operator ==(const node A)const{return x==A.x;}
};
struct heap{
	priority_queue<node>Q,D;
	inline void ins(re node x){Q.push(x);}
	inline void del(re node x){D.push(x);}
	inline node first(){
		while(!D.empty()&&Q.top().x==D.top().x)Q.pop(),D.pop();
		return Q.top();
	}
}Q1,Q2,Q3,Q4,Q5;
signed main(){
	n=read(),m=read();
	for(re int i=1;i<=n;++i)a[i]=-read(),b[i]=-read();
	Q1.ins((node){0,-inf}),Q2.ins((node){0,-inf}),Q3.ins((node){0,-inf}),Q4.ins((node){0,-inf}),Q5.ins((node){0,-inf});
	for(re int i=1;i<=n;++i)Q1.ins((node){i,a[i]}),Q2.ins((node){i,b[i]});
	for(re int i=1;i<=m;++i){
		re int x=Q2.first().y+Q3.first().y,y=Q1.first().y,z=Q1.first().x,zz=Q4.first().y,zzz=Q2.first().y+Q5.first().y;
		if(y>x&&y>zz&&y>zzz)ans+=y,Z[z]=1,Q2.del((node){z,b[z]}),Q3.ins((node){z,-a[z]}),Q1.Q.pop(),Q4.ins((node){z,b[z]-a[z]});
		else if(x>zz&&x>zzz){
			ans+=x;
			re node A=Q2.first(),B=Q3.first();Q2.Q.pop(),Q3.Q.pop();
			Z[A.x]=2,Z[B.x]=0,Q1.del((node){A.x,a[A.x]}),Q1.ins((node){B.x,a[B.x]}),Q2.ins((node){B.x,b[B.x]}),Q4.del((node){B.x,b[B.x]-a[B.x]});
			Q5.ins((node){A.x,a[A.x]-b[A.x]});
		}
		else if(zz>zzz){
			ans+=zz;
			node A=Q4.first();Q4.Q.pop();Z[A.x]=2;
			Q3.del((node){A.x,-a[A.x]}),Q5.ins((node){A.x,a[A.x]-b[A.x]});
		}
		else{
			ans+=zzz;
			re node A=Q2.first(),B=Q5.first();
			Q2.Q.pop(),Q5.Q.pop(),Z[A.x]=2,Z[B.x]=1;
			Q1.del((node){A.x,a[A.x]}),Q5.ins((node){A.x,a[A.x]-b[A.x]});
			Q3.ins((node){B.x,-a[B.x]}),Q4.ins((node){B.x,b[B.x]-a[B.x]});
		}
		assert(Z[0]==0);
	}
	printf("%lld\n",-ans);
	for(re int i=1;i<=n;++i)putchar(Z[i]+'0');
}