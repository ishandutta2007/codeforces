    #pragma GCC optimize("Ofast")
    #pragma GCC optimize("unroll-loops")
    #include<bits/stdc++.h>
    #define speedX ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
    using namespace std;
    // #define ONLINE_JUDGE
    #ifndef ONLINE_JUDGE
    template<typename T>
    void __p(T a) { cout << a << " "; }
    template<typename T, typename F>
    void __p(pair<T, F> a) { cout << "{ "; __p(a.first); __p(a.second); cout << "}"; }
    template<typename T>
    void __f(const char* s, T t) { cout << s << " : "; __p(t); }
    template<typename T>
    void __t(const char* s, const T &x) { cout << s << " : { "; for (auto it : x) __p(it); cout << "} ";}
    template<typename T, typename ... F>
    void __f(const char* s, T t, F ... f) {
    	int i = 0; for (;; ++i) if (s[i] == ',') break;
    	cout.write(s, i) << " : "; __p(t); cout << " | "; __f(s + i + 1, f...);
    }
    #define trace(...) { cout<<"LINE: "<<__LINE__<<" || "; __f(#__VA_ARGS__,__VA_ARGS__); cout<<"\n\n"; }
    #define debug(...) { cout<<"LINE: "<<__LINE__<<" || "; __t(#__VA_ARGS__,__VA_ARGS__); cout<<"\n\n"; }
    int begtime = clock();
    #define end_time() cout << "\n\nTime of execution: " << (clock() - begtime)*1000/CLOCKS_PER_SEC << " ms\n\n";
    #else
    #define trace(...)
    #define debug(...) 
    #define end_time()
    #endif
     
    typedef complex<double> point;
    #define int long long 
    typedef long long ll;
    typedef long double ld;
    typedef pair<int, int> pii;
    typedef pair<pii, int> piii;
    typedef vector<int> vi;
    typedef vector<pii> vii;
     
    inline bool equals(ld a, ld b) {return fabs(a - b) < 1e-2;}
    inline int gcd(int a, int b) { a=abs(a); b=abs(b); while(a>0 && b>0) (a>b?a%=b:b%=a); return (a==0?b:a); } 
    inline int power(int x, int n, int m = LLONG_MAX)
        {  int res=1; x = (x%m + m)%m;
           while(n) { if(n&1) res=(res*x)%m;  x=(x*x)%m;  n >>= 1; }  return res;
        }
    #define pb push_back
    #define mp make_pair
    #define mt make_tuple
    #define ff first
    #define ss second
    #define uset unordered_set
    #define umap unordered_map
    #define all(x) x.begin(), x.end()
    #define mod 1000000007
    #define PI_2 1.5707963267948966
    bool isSquare(point p1, point p2, point p3, point p4){ 
        ld d2 = norm(p1-p2); 
        ld d3 = norm(p1-p3); 
        ld d4 = norm(p1-p4); 
        if (equals(d2,0) || equals(d3,0) || equals(d4,0)) return false; 
     
        if (equals(d2,d3) && equals(2*d2,d4) 
            && equals(2*norm(p2-p4),norm(p2-p3))) { 
            return true; 
        } 
        if (equals(d3,d4) && equals(2*d3,d2) 
            && equals(2*norm(p3-p2),norm(p3-p4))) { 
            return true; 
        } 
        if (equals(d2,d4) && equals(2*d2,d3) 
            && equals(2*norm(p2-p3),norm(p2-p4))) { 
            return true; 
        } 
      
        return false; 
    } 
     
    void solve(){
    	vector<point> pl;
    	vector<point> hm;
    	for(int i = 0; i<4; i++){
    		ld x,y,a,b;
    		cin>>x>>y>>a>>b;
    		point p(x,y);
    		point q(a,b);
    		pl.pb(p);
    		hm.pb(q);
    	}
    	int ans = 20;
    	for(int w = 0; w<4; w++){
    		for(int x = 0; x<4; x++){
    			for(int y = 0; y<4; y++){
    				for(int z = 0; z<4; z++){
    					if(isSquare(pl[0],pl[1],pl[2],pl[3])) {
    						ans = min(ans,w+x+y+z);
    					}
    					pl[3] = ((pl[3]-hm[3])*polar(1.0,PI_2))+hm[3];
    				}
    				pl[2] = ((pl[2]-hm[2])*polar(1.0,PI_2))+hm[2];
    			}
    			pl[1] = ((pl[1]-hm[1])*polar(1.0,PI_2))+hm[1];
    		}
    		pl[0] = ((pl[0]-hm[0])*polar(1.0,PI_2))+hm[0];
    	}
    	if(ans==20) ans = -1;
    	cout<<ans<<"\n";
    }
    signed main(){
    	speedX;
    	#ifndef ONLINE_JUDGE
            freopen("input.txt", "r", stdin);
            freopen("output.txt", "w", stdout);
        #endif
    	int t=1;
    	cin>>t;
    	for(int i=1;i<=t;++i) {
    		//cout<<"Case #"<<i<<": ";
    		solve();
    	}
    	end_time();
    	return 0;
    }