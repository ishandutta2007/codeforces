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
int t,n,m,a[1000002],ans,A,B,d[200002];
long long S[22][200002];
char s[1000002];
struct heap{
	priority_queue<int>q,d;
	inline void clr(){while(!q.empty())q.pop();while(!d.empty())d.pop();}
	inline void insert(re int x){q.push(x);}
	inline void del(re int x){d.push(x);}
	inline int first(){
		while(!d.empty()&&q.top()==d.top())q.pop(),d.pop();
		return q.top();
	}
}H;
signed main(){
	n=2e5;
	for(re int i=2;i<=n;++i){
		for(re int j=i+i;j<=n;j+=i)d[j]=1;
	}
	t=read();
	while(t--){
		n=read(),m=read(),ans=0,H.clr();
		for(re int i=1;i<=n;++i)a[i]=read();
		vector<int>tmp;
		for(re int i=2;i<=n;++i)if(n%i==0&&d[i]==0)tmp.push_back(n/i);
		for(re int i=0;i<tmp.size();++i)
			for(re int j=0;j<tmp[i];++j)
				S[i][j]=0;
		for(re int i=1;i<=n;++i)
			for(re int j=0;j<tmp.size();++j)
				S[j][i%tmp[j]]+=a[i];
		for(re int i=0;i<tmp.size();++i)
			for(re int j=0;j<tmp[i];++j)
				H.insert(S[i][j]*tmp[i]);
		printf("%lld\n",H.first());
		while(m--){
			re int x=read(),y=read();
			for(re int i=0;i<tmp.size();++i){
				re int z=x%tmp[i];
				H.del(S[i][z]*tmp[i]);
				S[i][z]+=y-a[x];
				H.insert(S[i][z]*tmp[i]);
			}a[x]=y;
		printf("%lld\n",H.first());
		}
	}
}