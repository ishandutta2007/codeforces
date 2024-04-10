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

const int SQRTN=300;
const int BUFFER=60000000;

int n;
string s;
int pre[200005];
int cnt[70000005];

vector<int> zeros;
vector<int> pzeros;

ll eval(int div,int len,int extra){
	//cout<<div<<" "<<len<<" "<<extra<<endl;
	
	int min_len=max(div*SQRTN,(int)ceil((double)len/div)*div)-len;
	
	if (min_len<=extra){
		return (extra-min_len)/div+1;
	}
	else{
		return 0;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>s;
	n=sz(s);
	
	s="$"+s;
	
	ll ans=0;
	
	rep(x,1,n+1){
		pre[x]=pre[x-1]+(s[x]=='1');
	}
	
	rep(k,1,SQRTN){ //[1,SQRTN)
		rep(x,0,n+1) ans+=cnt[x-k*pre[x]+BUFFER]++;
		rep(x,0,n+1) cnt[x-k*pre[x]+BUFFER]--;
	}
	
	//cout<<ans<<endl;
	
	zeros.push_back(0),pzeros.push_back(0); //dummy element
	rep(x,1,n+1) if (s[x]=='1') zeros.push_back(x);
	zeros.push_back(n+1);
	
	rep(x,sz(zeros),1) zeros[x]-=zeros[x-1]+1;
	rep(x,1,sz(zeros)) pzeros.push_back(pzeros.back()+zeros[x]);
	
	//cout<<sz(zeros)<<" "<<sz(pzeros)<<endl;
	
	rep(ones,1,200000/SQRTN+5){
		//the number of ones we are taking
		//ensure that SQRTN<=k
		
		for (int x=1;x<sz(zeros)-ones;x++){
			//cout<<x<<" "<<x+ones<<endl;
			rep(y,0,zeros[x]+1) ans+=eval(ones,pzeros[x+ones-1]-pzeros[x]+ones+y,zeros[x+ones]);
			//cout<<x<<" "<<x+ones-1<<endl;
		}		
		
	}
	
	cout<<ans<<endl;
	
}