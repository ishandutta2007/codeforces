#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second

vector<int>adj[100005];
int n,m,a[100005];

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d",&a[i]);
	}
	ll res = 0, dec = 0;
	for(int i=0;i<m;i++)
	{
		if(i && a[i-1] != a[i]) adj[a[i]].pb(a[i-1]);
		if(i!=m-1&& a[i+1] != a[i]) adj[a[i]].pb(a[i+1]);
	}
	for(int i=1;i<m;i++)
	{
		res += 1LL*abs(a[i]-a[i-1]);
	}
	for(int i=1;i<=n;i++)
	{
		if(adj[i].empty()) continue;
		sort(adj[i].begin(),adj[i].end());
		ll gen = 0;
		int aa = lower_bound(adj[i].begin(),adj[i].end(),i)-adj[i].begin();
		for(int j=0;j<=aa-1;j++) gen+=1LL*adj[i][j];
		gen = 1LL*aa*i-gen;
		ll gen2 = 0;
		for(int j=aa;j<adj[i].size();j++) gen2+=1LL*adj[i][j];
		gen2 = gen2 - 1LL*(adj[i].size()-aa)*i;
		gen+=gen2;
		
		ll gen3 = 0;
		int ab = adj[i].size()/2;
		for(int j=0;j<=ab-1;j++) gen3+=1LL*adj[i][j];
		gen3 = 1LL*ab*adj[i][ab]-gen3;
		ll gen4 = 0;
		for(int j=ab;j<adj[i].size();j++) gen4+=1LL*adj[i][j];
		gen4 = gen4 - 1LL*(adj[i].size()-ab)*adj[i][ab];
		gen3+=gen4;
		
		dec = max(dec,gen-gen3);
	}
	cout << res-dec << endl;
	
}