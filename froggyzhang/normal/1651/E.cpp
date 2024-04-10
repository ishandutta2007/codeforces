#include<bits/stdc++.h>
using namespace std;
#define N 3030
typedef long long ll;
int n,vis[N];
vector<int> G[N];
int calc1(int l,int r,int k){
	if(k>=l&&k<=r)return 0;
	if(l>n)l-=n,r-=n,k-=n;
	if(k<l)return (l-k)*(n-r+1);
	return l*(k-r);
}
int calc2(int l,int r){
	if(l>n)l-=n,r-=n;
	return l*(n-r+1);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=(n<<1);++i){
		int u,v;
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	ll ans=0;
	for(int i=1;i<=n;++i){
		if(vis[i])continue;
		vector<int> a;
		for(int u=i;;){
			a.push_back(u);
			vis[u]=1;
			int ok=0;
			for(auto v:G[u]){
				if(!vis[v]){
					u=v;ok=1;
					break;
				}
			}
			if(!ok)break;
		}
		int sz=a.size();
		for(int j=0;j<sz;++j){
			int l1=a[j],r1=a[j],l2=a[(j+1)%sz],r2=a[(j+1)%sz];
			for(int k=2;k<sz;k+=2){
				ans+=1LL*calc1(l1,r1,a[(j+k)%sz])*calc2(l2,r2);
				l1=min(l1,a[(j+k)%sz]);
				r1=max(r1,a[(j+k)%sz]);
				l2=min(l2,a[(j+k+1)%sz]);
				r2=max(r2,a[(j+k+1)%sz]);
			}
			if(l1<=n)ans+=1LL*calc2(l1,r1)*calc2(l2,r2);
		}
	}
	cout<<ans<<'\n';
	return 0;
}