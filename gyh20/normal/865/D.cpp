#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#include<cstdio>
#include<queue>
#define re register
using namespace std;
const int Mxdt=100000;	// 
inline char gc(){
	static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline int read(){
	re int t=0;re char v=gc();
	while(v<'0')v=gc();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=gc();
	return t;
}
int t,n,m,a[300002],v[300002],ans2,mn;
struct node{
	int id,val;
	bool operator <(const node x)const{return val==x.val?v[id]<v[x.id]:val>x.val;}
};
priority_queue<node>q;
long long ans1;
signed main(){
//	freopen("sky.in","r",stdin);
//	freopen("sky.out","w",stdout);
	t=1;
	while(t--){
		n=read();
		for(re int i=1;i<=n;++i)a[i]=read(),v[i]=0;
		while(!q.empty())q.pop();ans1=ans2=0;
		for(re int i=1;i<=n;++i){
			if((!q.empty())&&a[i]>q.top().val){
				ans1+=a[i]-q.top().val;
				re node tmp=q.top();
				if(!v[q.top().id])ans2+=2,q.pop();
				else v[q.top().id]=0,q.pop(),q.push(tmp);
				v[i]=1;
			}
			q.push((node){i,a[i]});
		}
		printf("%lld\n",ans1);
	}
}