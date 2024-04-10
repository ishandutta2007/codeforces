//
//
//
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

int n,q;
int arr[200005];
vector<int> ans[205];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n>>q;
		rep(x,0,n) cin>>arr[x];
		
		vector<int> d;
		rep(x,1,n) if (n%x==0 && isPrime(n/x)) d.pub(x);
		
		rep(y,0,sz(d)) ans[y]=vector<int>(d[y],0);
		
		rep(y,0,sz(d)){
			rep(x,0,n) ans[y][x%d[y]]+=arr[x];
		}
		
		priority_queue<int> ins,del;
		
		rep(y,0,sz(d)){
			rep(x,0,d[y]) ins.push(ans[y][x]*d[y]);
		}
		
		cout<<ins.top()<<endl;
		
		int a,b;
		while (q--){
			cin>>a>>b;
			a--;
			
			rep(y,0,sz(d)){
				del.push(ans[y][a%d[y]]*d[y]);
				ans[y][a%d[y]]-=arr[a];
			}
			arr[a]=b;
			rep(y,0,sz(d)){
				ans[y][a%d[y]]+=arr[a];
				ins.push(ans[y][a%d[y]]*d[y]);
			}
			
			while (ins.top()==del.top()) ins.pop(),del.pop();
			
			cout<<ins.top()<<endl;
		}
	}
}