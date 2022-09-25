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
#define endl '\n'
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

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

vector<int> kmp(string s){
	vector<int> res={0};

	int curr=0;
	rep(x,1,sz(s)){
		while (curr>0 && s[x]!=s[curr]) curr=res[curr-1];
		if (s[x]==s[curr]) curr++;
		res.push_back(curr);
	}
	
	return res;
}

bool exists[1000005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	string s;
	cin>>s;
	
	auto ss=kmp(s);
	//for (auto &it:ss) cout<<it<<" ";
	//cout<<endl;
	
	rep(x,0,sz(s)-1) exists[ss[x]]=true;
	
	int curr=ss[sz(s)-1];
	int ans=0;
	
	while (curr>0){
		if (exists[curr]){
			ans=curr;
			break;
		}
		else{
			curr=ss[curr-1];
		}
	}
	
	if (ans==0) cout<<"Just a legend"<<endl;
	else cout<<s.substr(0,ans);
}