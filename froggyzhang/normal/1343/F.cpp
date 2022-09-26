#include<bits/stdc++.h>
using namespace std;
#define N 233
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int T,n,p[N],cnt[N],z[N],vis[N];
vector<int> a[N];
void calc(){
	for(int i=1;i<=n;++i)cnt[i]=0;
	for(int i=1;i<n;++i){
		if(vis[i])continue;
		for(auto x:a[i])++cnt[x];
	}
}
bool Solve(int fir){
	for(int i=1;i<=n;++i)z[i]=p[i]=0;
	z[fir]=1;
	p[1]=fir;
	for(int i=1;i<n;++i)vis[i]=0;
	for(int i=n;i>=2;--i){
		calc();
		for(int j=1;j<=n;++j){
			if(z[j])continue;
			if(cnt[j]==1){
				if(p[i])return false;
				p[i]=j;
			}
		}
		if(!p[i])return false;
		z[p[i]]=1;
		for(int j=1;j<n;++j){
			if(vis[j])continue;
			for(auto x:a[j]){
				if(x==p[i]){
					vis[j]=1;break;
				}	
			}
		}
	}
	for(int i=2;i<=n;++i){
		vector<int> v(1,p[i]);
		bool ok=false;
		for(int j=i-1;j>=1;--j){
			v.insert(lower_bound(v.begin(),v.end(),p[j]),p[j]);
			for(int k=1;k<n;++k){
				if(v==a[k]){ok=true;break;}
			}
		}	
		if(!ok)return false;
	}
	return true;
}
void Solve(){
	n=read();
	for(int i=1;i<=n;++i)vis[i]=0;
	for(int i=1;i<n;++i){
		a[i].clear();
		int t=read();
		while(t--)a[i].push_back(read());
	}
	for(int i=1;i<=n;++i){
		if(Solve(i))break;
	}
	for(int i=1;i<=n;++i){
		printf("%d ",p[i]);
	}
	printf("\n");
} 
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}