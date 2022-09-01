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
#define mod 998244353
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())

int n,k;
int a[100005];
int cur[100005];
ll dp[100005];
vector<int>pos[100005];
ll cnt[1705][705];
int lazy[1705];
vector<int>za;

int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		pos[i].pb(0);
		pos[i].pb(0);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		pos[a[i]].pb(i);
	}
	dp[0] = 1;
	for(int i=1;i<=n;i+=334){
		//dp[L...R]
		int L = i, R = min(n,i+333);
		rep(x,1705)rep(y,705){
			cnt[x][y] = lazy[x] = 0;
		}
		za.clear();
		for(int j=L;j<=R;j++){
			int x = POSL(pos[a[j]],j);
			za.pb(j); za.pb(pos[a[j]][x-1]+1); za.pb(pos[a[j]][x-2]+1);
		}
		za.pb(1);
		SORT(za); ERASE(za);
		za.pb(R+1);
		for(int i=0;i<za.size()-1;i++){
			for(int x=za[i];x<za[i+1];x++){
				if(abs(k-cur[x]) > 350) continue;
				cnt[i][k-cur[x]+350]+=dp[x-1];
				if(cnt[i][k-cur[x]+350] >= mod) cnt[i][k-cur[x]+350]-=mod;
			}
		}
		for(int i=0;i<za.size()-1;i++){
			if(za[i] < L) continue;
			if(za[i] == 1) dp[za[i]] = 1; else dp[za[i]] = 2LL*dp[za[i]-1]%mod;
			int val = a[za[i]];
			int V = POSL(pos[val],za[i]);
			int A = POSL(za,pos[val][V-2]+1);
			int B = POSL(za,pos[val][V-1]+1);
			int C = POSL(za,pos[val][V]);
			//cout << A << B << C << endl;
			for(int x=A;x<B;x++){
				if(k-(k+1-lazy[x])+350 >= 0 && k-(k+1-lazy[x])+350 <= 700) dp[za[i]] += cnt[x][k-(k+1-lazy[x])+350];
				lazy[x]--;
			}
			for(int x=B;x<C;x++){
				if(k-(k-lazy[x])+350 >= 0 && k-(k-lazy[x])+350 <= 700) {dp[za[i]] -= cnt[x][k-(k-lazy[x])+350];}
				lazy[x]++;
			}
			dp[za[i]] %= mod; //cout << dp[za[i]] << endl;
			if(dp[za[i]]<0) dp[za[i]]+=mod;
			if(k+350 >= 0 && k+350 <= 700) {cnt[i+1][k+350] += dp[za[i]]; cnt[i+1][k+350] %= mod; }
			lazy[i]++;
		}
		for(int i=0;i<za.size()-1;i++){
			for(int x=za[i];x<za[i+1];x++){
				cur[x] += lazy[i];
			}
		}
	}
	cout << (dp[n]%mod+mod)%mod << endl;
}