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

int n;
bool exists[100005];
int sf=-1;
vector<int> pf;
vector<int> cand;

const int BLOCK=100;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n;
	
	rep(x,1,n+1) exists[x]=true;
	
	rep(x,1,n+1) if (isPrime(x)){
		cout<<"B "<<x<<endl;
		int temp;
		cin>>temp;
		
		int cnt=0;
		for (int y=x;y<100005;y+=x){
			cnt+=exists[y];
			exists[y]=false;
		}
		
		if (temp!=cnt) pf.push_back(x);
		
		if (sf==-1) cand.push_back(x);
		
		if (sz(cand)==BLOCK){
			cnt=0;
			rep(x,1,n+1) cnt+=exists[x];
			
			cout<<"A "<<1<<endl;
			cin>>temp;
			if (temp!=cnt){
				for (auto &it:cand){
					cout<<"A "<<it<<endl;;
					cin>>temp;
					if (temp==1){
						sf=it;
						pf.push_back(it);
						break;
					}
				}
			}
			cand.clear();
		}
	}
	
	if (!cand.empty()){
		int cnt=0;
		rep(x,1,n+1) cnt+=exists[x];
		
		int temp;
		cout<<"A "<<1<<endl;
		cin>>temp;
		if (temp!=cnt){
			//cout<<"ohayo!"<<endl;
			for (auto &it:cand){
				cout<<"A "<<it<<endl;
				cin>>temp;
				if (temp==1){
					sf=it;
					pf.push_back(it);
					break;
				}
			}
		}
		cand.clear();
	}
	
	//for (auto &it:pf) cout<<it<<" "; cout<<endl;
	
	ll ans=1;
	for (auto &it:pf){
		for (ll y=it;y<=n;y*=it){
			cout<<"A "<<y<<endl;
			int temp;
			cin>>temp;
			if (temp==1) ans*=it;
		}
	}
	
	cout<<"C "<<ans<<endl;
}