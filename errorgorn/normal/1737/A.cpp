#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ii pair<int,int>
#define iii tuple<int,int,int>
#define fi first
#define se second
#define endl '\n'

#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define lb lower_bound
#define ub upper_bound

#define rep(x,start,end) for(int x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int n,k;
string s;
int cnt[26];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n>>k;
		cin>>s;
		rep(x,0,26) cnt[x]=0;
		rep(x,0,n) cnt[s[x]-'a']++;
		
		rep(x,0,k){
			int curr=0;
			rep(y,0,n/k){
				if (cnt[y]==0) break;
				cnt[y]--;
				curr++;
			}
			
			cout<<(char)('a'+curr);
		}
		cout<<endl;
	}
}