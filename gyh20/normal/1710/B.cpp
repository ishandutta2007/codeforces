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
const int M=998244353;
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
inline int Mod(re int x){return x>=M?x-M:x;}
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return s;
}
int t,n,m,a[1000002],ans[200002],sum,A[200002],num,lmt1,lmt2;
char s[1000002];
struct node{
	int x,y,id;
	bool operator <(const node A)const{return x<A.x;}
}p[200002];
signed main(){
	t=read();
	while(t--){
		n=read(),m=read(),lmt1=1e18,lmt2=-1e18;
		for(re int i=1;i<=n;++i)p[i].x=read(),p[i].y=read(),p[i].id=i,ans[i]=A[i]=0;
		sort(p+1,p+n+1),sum=num=0;
		priority_queue<int>Q;
		for(re int i=1;i<=n;++i){
			while(Q.size()&&-Q.top()<=p[i].x)sum-=-Q.top()-p[i-1].x,--num,Q.pop();
			sum-=(p[i].x-p[i-1].x)*num;
			++num,sum+=p[i].y,Q.push(-p[i].x-p[i].y),A[i]+=sum;
		}sum=num=0;
		while(Q.size())Q.pop();
		for(re int i=n;i;--i){
			while(Q.size()&&Q.top()>=p[i].x)sum-=p[i+1].x-Q.top(),--num,Q.pop();
			sum-=(p[i+1].x-p[i].x)*num;
			++num,sum+=p[i].y,Q.push(p[i].x-p[i].y),A[i]+=sum;
		}
		for(re int i=1;i<=n;++i)A[i]-=p[i].y;
		for(re int i=1;i<=n;++i)
			if(A[i]>m){
				lmt1=min(lmt1,p[i].x-(A[i]-m));
				lmt2=max(lmt2,p[i].x+(A[i]-m));
			}
		for(re int i=1;i<=n;++i){
			if(p[i].x+p[i].y>=lmt2&&p[i].x-p[i].y<=lmt1)ans[p[i].id]=1;
		}
		for(re int i=1;i<=n;++i)putchar(ans[i]+'0');
		puts("");
		
	}
}