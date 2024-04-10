#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int maxn=1e6+100;
typedef long long ll;
int _,n,d[maxn];
ll w[maxn];
bool cmp(int x,int y){return x>y;}
int main(){
	scanf("%d",&_);
	while (_--){
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%lld",&w[i]);
		ll ans=0;
		for (int i=1;i<=n;i++) d[i]=0,ans+=w[i];
		for (int i=1;i<n;i++){
			int u,v;scanf("%d%d",&u,&v);
			d[u]++; d[v]++;
		}
		vector<ll> res; res.clear();
		for (int i=1;i<=n;i++)
			for (int j=1;j<d[i];j++)
				res.pb(w[i]);
		sort(res.begin(),res.end(),cmp);
        printf("%lld",ans);
        for (auto x:res){
			ans+=x;
			printf(" %lld",ans);
        }
        puts("");
	}
	return 0;
}