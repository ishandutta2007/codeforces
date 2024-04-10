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
int dp[7005][2];
int cnt[7005][2];
vector<int>a[2];
int n;
int main(){
	cin>>n;
	int x; cin>>x; rep(i,x){int e;cin>>e;a[0].pb(e);}
	cin>>x; rep(i,x){int e;cin>>e;a[1].pb(e);}
	memset(dp,-1,sizeof(dp));
	dp[1][0] = 1; dp[1][1] = 0;
	queue<P>que;
	que.push(mp(1,0)); que.push(mp(1,1));
	while(!que.empty()){
		P p = que.front(); que.pop();
		for(int i=0;i<a[1-p.sc].size();i++){
			int num = (p.fi-a[1-p.sc][i]);
			if(num <= 0) num += n;
			if(num > n) num -= n;
			if(num == 1) continue;
			cnt[num][1-p.sc] ++;
			if(dp[p.fi][p.sc] == 1-p.sc){
				if(dp[num][1-p.sc] == -1){
					dp[num][1-p.sc] = 1-p.sc;
					que.push(mp(num,1-p.sc));
				}
			}
			else{
				if(cnt[num][1-p.sc] == a[1-p.sc].size() && dp[num][1-p.sc] == -1){
					dp[num][1-p.sc] = p.sc;
					que.push(mp(num,1-p.sc));
				}
			}
		}
	}
	for(int i=2;i<=n;i++){
		if(dp[i][0] == 0) cout<<"Win ";
		else if(dp[i][0] == 1) cout << "Lose ";
		else cout << "Loop " ;
	}
	cout << endl;
	for(int i=2;i<=n;i++){
		if(dp[i][1] == 1) cout<<"Win ";
		else if(dp[i][1] == 0) cout << "Lose ";
		else cout << "Loop " ;
	}
	cout << endl;
	return 0;
}