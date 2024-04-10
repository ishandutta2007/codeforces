    #include <bits/stdc++.h>
    using namespace std;
     
    using ll = long long;
     
    #define pb push_back
    #define ff first
    #define ss second
    #define all(a) a.begin(), a.end()
    #define sz(a) (int)(a.size())
    #define clr(a, b) memset(a, b, sizeof(a))
    #define REP(i, a, b) for(int i=(int)(a); i<(int)(b); ++i)
    #define REPD(i, a, b) for(int i=(int)(a)-1; i>=(int)(b); --i)
     
    template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
    template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
     
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
     
    int n, m;
     
    int sq(int a) {
    	return a * a;
    }
     
    int dist(pair<int, int> a, pair<int, int> b) {
    	return sq(a.ff - b.ff) + sq(a.ss - b.ss);
    }
     
    int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cin >> n >> m;
        if(n == 0) {
        	cout << 0 << " " << 1 << "\n";
        	cout << 0 << " " << m << "\n";
        	cout << 0 << " " << 0 << "\n";
        	cout << 0 << " " << m-1 << "\n";
        } else if(m == 0) {
        	cout << 1 << " " << 0 << "\n";
        	cout << n << " " << 0 << "\n";
        	cout << 0 << " " << 0 << "\n";
        	cout << n-1 << " " << 0 << "\n";
        } else {
        	vector<pair<int, int>> v;
        	v.pb({0, 0});
        	v.pb({n, m});
        	v.pb({0, m});
        	v.pb({n, 0});
        	v.pb({n-1, 0});
        	v.pb({0, m-1});
        	v.pb({n, m-1});
        	v.pb({n-1, m});
        	v.pb({1, 0});
        	v.pb({n, 1});
        	v.pb({0, 1});
        	v.pb({n-1, 0});
        	v.pb({n-1, m});
        	v.pb({1, m});
        	v.pb({0, m-1});
        	
        	sort(all(v));
        	v.erase(unique(all(v)), v.end());
     
        	int res = 0;
     
        	vector<pair<int, int>> ans;
     
        	REP(a, 0, sz(v)) {
        		REP(b, 0, sz(v)) {
        			REP(c, 0, sz(v)) {
        				REP(d, 0, sz(v)) {
        					set<int> st;
        					st.insert(a);
        					st.insert(b);
        					st.insert(c);
        					st.insert(d);
        					if(sz(st) == 4) {
        						if(dist(v[a], v[b]) + dist(v[b], v[c]) + dist(v[c], v[d]) > res) {
        							res = dist(v[a], v[b]) + dist(v[b], v[c]) + dist(v[c], v[d]);
        							ans.clear();
        							ans.pb(v[a]);
        							ans.pb(v[b]);
        							ans.pb(v[c]);
        							ans.pb(v[d]);
        						}  
        					}
        				}
        			}
        		}
        	}
        	assert(sz(ans) == 4);
        	for(auto x: ans)
        		cout << x.ff << " " << x.ss << "\n";
        }
        return 0;
    }