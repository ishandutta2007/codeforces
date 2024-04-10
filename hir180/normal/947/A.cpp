#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int go[1000005];
vector<int>D[1000005];
int main(){
	for(int i=2;i<=1000002;i++){
		if(D[i].size()) continue;
		for(int j=2;j*i<=1000002;j++){
			D[i*j].pb(i);
		}
	}
	int n; cin>>n;
	assert(D[n].size());
	{
		{
			int p = D[n][D[n].size()-1];
			int pre = n-p+1;
			//[pre,n]
			int ans = INF;
			for(int i=pre;i<=n;i++){
				for(int j=0;j<D[i].size();j++){
					int q = D[i][j];
					ans = min(ans,i+1-q);
				}
			}
			cout<<ans<<endl;
			return 0;
		}
	}
	assert(0);
}