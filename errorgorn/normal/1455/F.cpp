//
//

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
#define debug(x) cout << #x << " is " << x << endl

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int n,k;
string s;
int arr[505];
int pref[505];
int cval[505];
int pp[505];

void upd(int pos,int pval,int val,int par){
	if (pref[pos]>pval){
		pref[pos]=pval;
		cval[pos]=100;
	}
	if (pref[pos]==pval && cval[pos]>val){
		cval[pos]=val;
		pp[pos]=par;
	}
}

int opt(int i){
	if (i==0 || i==k-1) return 0;
	else return i-1;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		rep(x,0,505){
			pref[x]=728;
			cval[x]=100;
		}
		
		cin>>n>>k;
		cin>>s;
		rep(x,0,n) arr[x]=s[x]-'a';
		
		cval[0]=26;
		pp[0]=-1;
		
		rep(x,0,sz(s)){
			int y=cval[x];
			//cout<<"debug: "<<y<<endl;
			//cout<<(char)('a'+pref[x]/27)<<(char)('a'+pref[x]%27)<<(char)('a'+y)<<endl;
			
			if (y==26 && x!=0) continue;
			
			//cout<<arr[x]<<" "<<opt(arr[x])<<endl;
			upd(x+1,pref[x]%27*27+y,opt(arr[x]),x);
			
			if (x!=0){
				upd(x+1,pref[x]%27*27+arr[x],y,x);
			}
			if (x!=sz(s)-1){
				upd(x+1,pref[x]%27*27+y,26,-1); //destroy
				upd(x+2,y*27+opt(arr[x+1]),arr[x],x);
			}
			if (x!=0 && x!=sz(s)-1){
				upd(x+1,pref[x]%27*27+arr[x+1],26,-1); //destroy
				upd(x+2,arr[x+1]*27+y,arr[x],x);
			}
			
		}
		
		string ans;
		int px=n;
		
		ans.push_back('a'+cval[n]);
		while (px!=-1){
			//cout<<px<<" "<<pp[px]<<endl;
			
			if (pp[px]+2==px){
				ans.push_back('a'+pref[px]%27);
				ans.push_back('a'+pref[px]/27);
				px=pp[px];
			}
			else{
				ans.push_back('a'+pref[px]%27);
				px=pp[px];
			}
		}
		
		rep(x,sz(ans)-2,0) cout<<ans[x]; cout<<endl;
	}
}