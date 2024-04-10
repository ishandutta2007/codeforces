// Super Idol
//    
//  
//    
//  105C
// 

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ii,ll>
#define fi first
#define se second
#define endl '\n'
#define debug(x) cout << #x << ": " << x << endl

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

int n,m,k;
string s,t;

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n>>m>>k;
		cin>>s>>t;
		
		sort(all(s));
		sort(all(t));
		
		int i=0,j=0;
		int curr=0;
		bool flag=false;
		
		string ans;
		while (i<sz(s) && j<sz(t)){
			if ((s[i]<t[j] && (flag || curr<k)) || (flag && curr==k)){
				ans+=s[i];
				i++;
				if (flag){
					curr=1;
					flag=false;
				}
				else{
					curr++;
				}
			}
			else{
				ans+=t[j];
				j++;
				if (!flag){
					curr=1;
					flag=true;
				}
				else{
					curr++;
				}
			}
		}
		
		cout<<ans<<endl;
	}
}