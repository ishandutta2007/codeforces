#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,a[100002],mu[100002];
long long ans;
vector<int>G[100002],D[100002],V[100002];
inline void Ins(re int x,re int y){for(auto z:D[x])V[z].push_back(y);}
inline bool ck(re int x,re int y){
	re int s=0;
	for(auto z:D[x])s+=mu[z]*(upper_bound(V[z].begin(),V[z].end(),y)-V[z].begin());
	return s!=0;
}
int main(){
	n=read();while(n--)a[read()]=1;n=1e5;
	for(re int i=1;i<=n;++i){
		mu[i]+=(i==1);
		for(re int j=i+i;j<=n;j+=i)mu[j]-=mu[i];
	}
	for(re int i=1;i<=n;++i)for(re int j=i;j<=n;j+=i)D[j].push_back(i);
	for(re int i=n;i;--i){
		for(re int j=1;j<=n/i;++j)V[j].clear();
		vector<int>tmp;
		for(re int j=i;j<=n;j+=i)if(a[j])tmp.push_back(j);
		reverse(tmp.begin(),tmp.end());
		re int pos=-1;
		for(re int j=0;j<tmp.size();++j){
			Ins(tmp[j]/i,j);
			if(ck(tmp[j]/i,n+1)){
				if(pos==-1)pos=j;
				while(pos&&ck(tmp[j]/i,pos-1))--pos;
				if(ck(tmp[j]/i,pos))ans=max(ans,1ll*tmp[j]*tmp[pos]/i);
			}
		}
	}printf("%lld",ans);
}