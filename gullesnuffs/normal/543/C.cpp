#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define rrep(i, a, b) for(int i = (a) - 1; i >= int(b); --i)
#define trav(it, v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define all(v) (v).begin(), (v).end()
#define what_is(x) cerr << #x << " is " << x << endl;

typedef double fl;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;

char s[25][25];
int a[25][25];
int dp[3000000];
int cheapest[25];

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	rep(i,0,n){
		scanf("%s", s[i]);
	}
	rep(i,0,n){
		cheapest[i]=100000000;
		rep(j,0,m){
			scanf("%d", a[i]+j);
			cheapest[i]=min(cheapest[i], a[i][j]);
		}
	}

	rep(i,0,3000000)
		dp[i]=1000000000;
	/*rep(i,0,(1<<n))
		rep(j,0,n){
			if(i&(1<<j))
				continue;
			int newi=i|(1<<j);
			dp[newi]=min(dp[newi], dp[i]+cheapest[i]);
		}*/
	dp[(1<<n)-1]=0;
	rep(j,0,m){
		vector<int> v[256];
		rep(i,0,n)
			v[s[i][j]].push_back(i);
		rep(k,0,256){
			if(v[k].empty())
				continue;
			int sum=0;
			int Max=0;
			int bit=0;
			rep(i,0,v[k].size()){
				bit|=(1<<v[k][i]);
				Max=max(Max, a[v[k][i]][j]);
				sum += a[v[k][i]][j];
			}
			int cost=sum-Max;
			//int ni=((1<<n)-1)^bit;
			for(int i=0; i < (1<<n); ++i)
				if(dp[i|bit]+cost < dp[i])
					dp[i]=dp[i|bit]+cost;
			//for(int i=0; i < (1<<n); i=((i+1)|bit))
			//		dp[i^bit]=min(dp[i^bit],dp[i]+cost);
		}
	}
	int ans=1000000000;
	rep(i,0,(1<<n)){
		int tot=dp[i];
		rep(j,0,n){
			if(!(i&(1<<j)))
				continue;
			tot += cheapest[j];
		}
		ans=min(ans, tot);
	}
	printf("%d\n", ans);
	/*rep(i,0,(1<<n)){
		rep(j,0,n){
			if(i&(1<<j))
				continue;
			int newi=i|(1<<j);
			dp[newi]=min(dp[newi], dp[i]+cheapest[i]);
		}
	}*/
}