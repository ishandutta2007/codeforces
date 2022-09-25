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
#define debug(x) cout << #x << ": " << x << endl

#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define lb lower_bound
#define ub upper_bound

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
    if (i==1) return true; //:trolleh:
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

int n;
ll arr[100005];

map<ll,ll> sum1;

map<ii,ll> memo;
ll ask(int i,int j){
	if (i>j) swap(i,j);
	if (memo.count(ii(i,j))) return memo[ii(i,j)];
	
	cout<<"? "<<i<<" "<<j<<endl;
	
	ll temp;
	cin>>temp;
	//temp=arr[i]*arr[j]/__gcd(arr[i],arr[j]);
	return memo[ii(i,j)]=temp;
}

vector<int> sort(vector<int> v){
	ll mx=-1;
	int a,b,c;
	
	rep(x,0,sz(v)) rep(y,x+1,sz(v)){
		if (mx<ask(v[x],v[y])){
			mx=ask(v[x],v[y]);
			a=v[x],b=v[y];
		}
	}
	
	ll nxt=sum1[mx];
	nxt=(nxt-1)*(nxt);
	
	rep(x,0,sz(v)) rep(y,x+1,sz(v)){
		if (nxt==ask(v[x],v[y])){
			if (a==v[x] || a==v[y]) swap(a,b);
			
			if (b==v[x]) c=v[y];
			else c=v[x];
		}
	}
	
	vector<int> ans={a,b,c};
	
	set<int> s;
	rep(x,0,sz(v)) if (v[x]!=a && v[x]!=b && v[x]!=c) s.insert(v[x]);
	
	ll curr=sum1[mx]-2;
	while (!s.empty()){
		int idx=-1;
		for (auto &it:s){
			if (ask(it,ans.back())==curr*(curr+1)) idx=it;
		}
		
		ans.pub(idx);
		
		s.erase(idx);
		curr--;
	}
	
	reverse(all(ans));
	
	return ans;
}

int ans[200005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	rep(x,1LL,200005LL) sum1[x*(x+1)]=x;
	
	int TC;
	cin>>TC;
	while (TC--){
		memo.clear();
		cin>>n;
		//rep(x,1,n+1) cin>>arr[x];
		
		if (n<=100){
			vector<int> temp;
			rep(x,1,n+1) temp.pub(x);
			temp=sort(temp);
			
			ll a0=sum1[ask(temp[0],temp[1])];
			
			rep(x,0,sz(temp)) ans[temp[x]]=x+a0;
			
			cout<<"! "; rep(x,1,n+1) cout<<ans[x]<<" "; cout<<endl;
		}
		else{
			vector<int> temp;
			rep(x,1,n+1) temp.pub(x);
			shuffle(all(temp),rng);
			
			//we be safe and use 25 random numbers for each shot
			//we do 175 shots
			
			int p=-1,idx;
			
			rep(xx,0,min(sz(temp),175)){
				int x=temp[xx];
				ll g=0;
				
				rep(y,0,25){
					int pos=rng()%n+1;
					if (pos!=x) g=__gcd(g,ask(x,pos));
				}
				
				if (isPrime(g) && g>p){
					p=g;
					idx=x;
				}
			}
			
			//cout<<p<<" "<<idx<<endl;
			
			if (p==-1) continue;
			
			ans[idx]=p;
			
			ll known=-1;
			rep(x,1,n+1) if (x!=idx){
				ll temp=ask(x,idx);
				ans[x]=temp/p;
			}
			
			cout<<"! "; rep(x,1,n+1) cout<<ans[x]<<" "; cout<<endl;
		}
	}
}