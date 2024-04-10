#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ii,ll>
#define fi first
#define se second
#define debug(x) cout << #x << " is " << x << endl;
 
#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
 
ll MAX(ll a){return a;}
ll MIN(ll a){return a;}
template<typename... Args>
ll MAX(ll a,Args... args){return max(a,MAX(args...));}
template<typename... Args>
ll MIN(ll a,Args... args){return min(a,MIN(args...));}
 
#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
 
int n;
int cnt[55][26];
string val[55];

char ans[105];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	if (n==1){
		cout<<"? 1 1"<<endl;
		string s;
		cin>>s;
		cout<<"! "<<s<<endl;
		return 0;
	}
	
	int hn=(n+1)/2; //half n
	
	cout<<"? 1 "<<hn<<endl;
	rep(x,0,hn*(hn+1)/2){
		string s;
		cin>>s;
		
		rep(y,0,sz(s)){
			cnt[sz(s)][s[y]-'a']++;
		}
	}
	
	if (n!=2){
		cout<<"? 2 "<<hn<<endl;
		rep(x,0,hn*(hn-1)/2){
			string s;
			cin>>s;
			
			rep(y,0,sz(s)){
				cnt[sz(s)][s[y]-'a']--;
			}
		}
	}
	
	rep(x,0,hn){
		rep(y,0,26){
			if (cnt[x][y]!=cnt[x+1][y]) ans[x]=y+'a';
		}
	}
	
	memset(cnt,0,sizeof(cnt));
	
	cout<<"? 1 "<<n<<endl;
	rep(x,0,n*(n+1)/2){
		string s;
		cin>>s;
		
		if (sz(s)<=hn) rep(y,0,sz(s)) cnt[sz(s)][s[y]-'a']++;
		
	}
	
	rep(x,hn+1,1) rep (y,0,26) cnt[x][y]-=cnt[x-1][y];
	rep(x,1,hn+1) rep(y,0,26){
		cnt[x][y]-=cnt[x+1][y];
		
		rep(z,0,cnt[x][y]) val[x]+=(char)(y+'a');
	}
	
	//rep(x,1,n/2+1) cout<<val[x]<<endl;
	
	rep(x,1,n/2+1){
		if (ans[x-1]==val[x][0]) ans[n-x]=val[x][1];
		else ans[n-x]=val[x][0];
	}
	
	cout<<"! "<<ans<<endl;
}