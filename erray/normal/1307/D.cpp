#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define umap unordered_map
#define flush fflush(stdout)
#define For(ii,aa,bb) for(int ii = aa; ii < bb; ii++) 
#define st first
#define nd second 
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define ln "\n"
#define all(v) v.begin(),v.end()
#define MAX 1000000009
#define MOD 1000000007
#define mid (start + end) / 2 
#define R(ii) (ii + ii + 1)
#define L(ii) (ii + ii)
#define N 500005
using namespace std;
typedef pair<ll,ll> pp;
typedef vector<ll> vi; 
ll n, t, x, a, b, c, k, path[N][2];
vector <ll> edge[N]; 
int main(){
    #ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    queue <pp> q;
    memset(path, -1, sizeof path);
    cin >> n >> t >> k;
    vi spec;
    while(k--){
    	cin >> x;
    	spec.pb(x);
    } 
    while(t--){
    	cin >> a >> b;
    	edge[a].pb(b);
    	edge[b].pb(a);
    }
    
    q.push(mp(1, 0));
    while(!q.empty()){
    	ll node = q.front().st, val = q.front().nd;
    	q.pop();
    //	cout << node << " ";
    	if(path[node][0] != -1){
    		continue;
    	}

    	path[node][0] = val;
    	for(auto a : edge[node]){
    		if(path[a][0] == -1){
    			q.push(mp(a, val + 1));
    		}
    	}
    }
     q.push(mp(n, 0));
    while(!q.empty()){
    	ll node = q.front().st, val = q.front().nd;
    	q.pop();
    	if(path[node][1] != -1){
    		continue;
    	}
    	path[node][1] = val;
    	for(auto a : edge[node]){
    		if(path[a][1] == -1){
    			q.push(mp(a, val + 1));
    		}
    	}
    }
    
    vector <pp> fark;
    for(auto a : spec){
    	fark.pb(mp(path[a][0] - path[a][1], a));
    }
    sort(all(fark));
    ll best = -1, ans = -1;
    for(auto a : fark){
    	if(best == -1){
    		best = path[a.nd][0];
    		continue;
    	}
    	ans = max(ans, best + path[a.nd][1]);
    	best = max(a.st, path[a.nd][0]);

    }
   	cout << min(ans + 1, path[1][1]);
   	//cout << ln << path[1][1];
    return 0;
	
}