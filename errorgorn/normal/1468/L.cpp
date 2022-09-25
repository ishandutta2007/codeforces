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

ll qexp(ll b,ll p,int m){
	ll res=1;
    while (p){
        if (p&1) res=(res*b)%m;
        b=(b*b)%m;
        p>>=1;
    }
    return res;
}

const int witness[]={2,7,61};
bool isPrime(int i){
    ///check for the simple cases
    if (i==1) return false;
    if (i==2) return true;
    if (!(i&1)) return false;
    for (auto &it:witness) if (it==i) return true;

    int s=__builtin_ctz(i-1);
    int k=(i>>s);
    
    long long res;
    for (auto &it:witness){
        res=qexp(it,k,i);
        
        if (res==1 || res==i-1) goto pass;
        for (int x=0;x<s-1;x++){
            res=(res*res)%i;
            if (res==i-1) goto pass;
        }
        return false;
        pass:;
    }
    return true;
}

map<ll,ll> ppow;

int n,k;
ll arr[1005];
map<ll,vector<ll> > pstore;
map<ll,vector<ll> > ptup;
vector<ll> comp;
vector<ii> comp2;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	rep(x,2,31630) if (isPrime(x)){
		ll curr=(ll)x*x*x*x;
		
		while (true){
			ppow[curr]=x;
			if ((double)curr*x>1e18+100) break;
			curr*=x;
		}
	}
	
	cin>>n>>k;
	rep(x,0,n) cin>>arr[x];
	
	rep(x,0,n){
		if (ppow.count(arr[x])){
			pstore[ppow[arr[x]]].push_back(arr[x]);
			continue;
		}
		if (arr[x]<1e9 && isPrime(arr[x])){
			pstore[arr[x]].push_back(arr[x]);
			continue;
		}
		
		ll temp=round(sqrt(arr[x]));
		if (temp*temp==arr[x] && isPrime(temp)){
			pstore[temp].push_back(arr[x]);
			continue;
		}
		
		temp=round(cbrt(arr[x]));
		if (temp*temp*temp==arr[x] && isPrime(temp)){
			pstore[temp].push_back(arr[x]);
			continue;
		}
		
		comp.push_back(arr[x]);
	}
	
	for (auto &it:pstore){
		if (sz(it.se)<2) continue;
		//cout<<it.fi<<" "<<sz(it.se)<<endl;
		while (sz(it.se)>2) comp.push_back(it.se.back()),it.se.pop_back();
		ptup.insert(it);
	}
	
	for (auto &it:comp){
		ll curr=it;
		int cnt=0;
		for (auto &it2:ptup){
			if (curr%it2.fi==0){
				cnt++;
				while (curr%it2.fi==0) curr/=it2.fi;
			}
		}
		if (curr==1) comp2.push_back(ii(it,cnt));
	}
	
	//for (auto &it:comp2) cout<<it.fi<<"_"<<it.se<<" "; cout<<endl;
	
	if (k>=2*sz(ptup)){
		if (k>2*sz(ptup)+sz(comp2)){
			cout<<0<<endl;
		}
		else{
			for (auto &it:ptup){
				for (auto &it2:it.se) cout<<it2<<" ";
			}
			rep(x,0,k-2*sz(ptup)) cout<<comp2[x].fi<<" ";
		}
	}
	else if (k%2==0){
		int cnt=0;
		for (auto &it:ptup){
			for (auto &it2:it.se) cout<<it2<<" ";
			cnt+=2;
			if (cnt==k) break;
		}
	}
	else{
		ll val;
		ll mn=1e9;
		for (auto &it:comp2){
			if (it.se<mn){
				mn=it.se;
				val=it.fi;
			}
		}
		
		if (k<2*mn+1){
			cout<<0<<endl;
			return 0;
		}
		
		cout<<val<<" ";
		
		set<int> fac;
		for (auto &it2:ptup){
			if (val%it2.fi==0) fac.insert(it2.fi);
		}
		
		int cnt=1;
		for (auto &it:fac){
			for (auto &it2:ptup[it]) cout<<it2<<" ";
			cnt+=2;
		}
		
		if (cnt==k) return 0;
		
		for (auto &it:ptup){
			if (fac.count(it.fi)) continue;
			for (auto &it2:it.se) cout<<it2<<" ";
			cnt+=2;
			if (cnt==k) break;
		}
	}
}