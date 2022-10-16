    #include<bits/stdc++.h>
    #include<ext/pb_ds/assoc_container.hpp>
    #include<ext/pb_ds/tree_policy.hpp>
    #include<unistd.h>
    #pragma GCC optimize("Ofast")
    #pragma GCC target("avx,avx2,fma")
    #pragma GCC optimization ("unroll-loops")
    #define ST first
    #define ND second
    #define ll long long
    #define ld long double
    #define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
    using namespace std;
    using namespace __gnu_pbds;
    #define M_PIl 3.141592653589793238462643383279502884L
     
    // replace ll  with pair if multiset needed
    typedef tree<ll, null_type, greater<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
    ordered_set secik;
     
    const ll  INF = 1e9 + 9;
    const ll  MOD = 1e9 + 7;
    const long long LINF = (ll)1e18 + 3;
     
    // secik.insert({x, t++});
    // secik.erase(secik.lower_bound({x,-1}));
    // *secik.find_by_order(x)).first << "\n";
    // secik.order_of_key(x)
     
    //random_device device;
    //mt19937 gener(device());
    //uniform_int_distribution<ll > gen(0,n-1);
    //gen(gener); // generate random number
     
    const int SIZE = 1e3 + 3;
     
    struct circle{
    	ll x,y,r;
    	circle(ll xx, ll yy, ll rr){
    		x = xx, y = yy, r = rr;
    	}
    };
     
    int n;
    vector<circle> circles;
    int ile[SIZE];
     
    int main(){
    	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
     
    	cin >> n;
    	for(int i = 1; i <= n; i++){
    		ll x,y,r; cin >> x >> y >> r;
    		circles.push_back(circle(x,y,r));
    	}
    	
    	for(int i = 0; i < n; i++){
    		for(int j = 0; j < n; j++){
    			if(i == j) continue;
    			ll x1 = circles[i].x, x2 = circles[j].x, y1 = circles[i].y, y2 = circles[j].y;
    			if((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) <= circles[i].r * circles[i].r && circles[i].r > circles[j].r) ile[j]++;
    		}
    	}
     
    	ll ans = 0;
    	for(int i = 0; i < n; i++){
    		if(ile[i] == 0){
    			ans += circles[i].r * circles[i].r;
    		} else if(ile[i] % 2 == 1){
    			ans += circles[i].r * circles[i].r;
    		} else {
    			ans -= circles[i].r * circles[i].r;
    		}
    	}
    	
    	cout << fixed << setprecision(17) << M_PIl * ans;
     
    	return 0;
    }