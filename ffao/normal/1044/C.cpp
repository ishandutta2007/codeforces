    #include <iostream>
    #include <vector>
    #include <cmath>
    #include <string>
    #include <algorithm>
    #include <iomanip>
    #include <map>
    #include <set>
    #include <bitset>
    #include <fstream>
    #include <unordered_set>
    #include <unordered_map>
    #include <ext/pb_ds/assoc_container.hpp>
             
                     
    using namespace std;
    using namespace __gnu_pbds;
            
             
            
    /*#pragma GCC optimize("Ofast")
    #pragma GCC optimize("no-stack-protector")
    #pragma GCC optimize("unroll-loops")
    #pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
    #pragma GCC optimize("fast-math")*/
                 
    #define int long long
    #define eb emplace_back
    #define pb push_back
    #define ld long double
    #define mp make_pair
    #define f first
    #define s second
    #define deb(a) cerr << #a << " = " << a << '\n';
    #define fast() { \
        ios_base::sync_with_stdio(0); \
        cin.tie(0); \
        cout << fixed << setprecision(20); \
        cerr << fixed << setprecision(11); \
    }
            
    template < typename firstType, typename secondType = null_type, class compare = less < firstType > >
    struct sett {
        typedef tree <
            firstType,
            secondType,
            compare,
            rb_tree_tag,
            tree_order_statistics_node_update
        > _ ;
    };
            
             
    const int INF = 1e9 + 7;
    const ld EPS = 1e-8;
    const int MAXI = 350;
    const int MOD = 998244353;
    const int MOD1 = 1e9 + 7;
    const int MAXST = 2000000;
    const int P = 31;
    const int P1 = 37;
    const ld PI = 3.14159265358979323;
           
                   
    ostream &operator<<(ostream &stream, const pair <int, int> &p) {
        stream << p.first << ' ' << p.second << ' ';
        return stream;
    }
     
    int ax[310000], ay[310000];
     
     
    signed main(){
        fast();
        srand(time(0));
        //#ifdef _LOCAL               
            //freopen("inverse.in", "r", stdin);
            //freopen("inverse.out", "w", stdout);
        //#endif
        #ifdef _LOCAL               
            freopen("input.txt", "r", stdin);
            freopen("output.txt", "w", stdout);
        #endif
       	int n;
       	cin >> n;
       	for (int i = 0; i < n; i++){
       		cin >> ax[i] >> ay[i];
       	}
       	int mnx = INF, mxx = -INF, mny = INF, mxy = -INF;
       	for (int i = 0; i < n; i++){
       		mnx = min(mnx, ax[i]);
       		mxx = max(mxx, ax[i]);
       		mny = min(mny, ay[i]);
       		mxy = max(mxy, ay[i]);
       	}
       	int ans1 = 0, ans2 = mxx - mnx + mxy - mny;
       	for (int i = 0; i < n; i++){
       		int tmp = max(abs(ax[i] - mnx), abs(ax[i] - mxx)) + max(abs(ay[i] - mny), abs(ay[i] - mxy));
       		ans1 = max(ans1, tmp);
       	}
       	ans1 *= 2;
       	ans2 *= 2;
       	cout << ans1 << ' ';
       	for (int i = 4; i < n + 1; i++)
       		cout << ans2 << ' ';
        return 0;               
    }