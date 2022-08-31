#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
const ll mod = 1000000007;
int n,m,k;
string S;
char s[105][105];
char ans[105][105];
void solve(){
	scanf("%d%d%d",&n,&m,&k);
	rep(i,n) scanf("%s",&s[i]);
	int cnt = 0;
	rep(i,n){
		rep(j,m){
			cnt += s[i][j] == 'R';
		}
	}
	vector<int>need;
	rep(x,k) need.pb(cnt/k);
	rep(x,cnt%k) need[x]++;
	int cur = 0;
	rep(i,n){
		if(i%2 == 0){
			rep(j,m){
				need[cur] -= s[i][j] == 'R';
				ans[i][j] = S[cur];
				if(need[cur] == 0 && cur < k-1){
					cur++;
				}
			}
		}
		else{
			for(int j=m-1;j>=0;j--){
				need[cur] -= s[i][j] == 'R';
				ans[i][j] = S[cur];
				if(need[cur] == 0 && cur < k-1){
					cur++;
				}
			}
		}
	}
	rep(i,n) {
		rep(j,m) printf("%c",ans[i][j]);
		puts("");
	}
}
int main(){
	for(int i=0;i<26;i++) S.pb('a'+i);
	for(int i=0;i<26;i++) S.pb('A'+i);
	for(int i=0;i<10;i++) S.pb('0'+i);

	int t; scanf("%d",&t);
	while(t--) solve();
}