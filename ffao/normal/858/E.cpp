    #include<bits/stdc++.h>
    #include <ext/pb_ds/assoc_container.hpp> 
    #include <ext/pb_ds/tree_policy.hpp> 
     
    using namespace __gnu_pbds; 
    using namespace std;
     
    #define TRACE
     
    #ifdef TRACE
    #define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template <typename Arg1>
    void __f(const char* name, Arg1&& arg1){
        cerr << name << " : " << arg1 << std::endl;
    }
    template <typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
    }
    #else
    #define trace(...)
    #endif
     
    #define ll long long
    #define ld long double
    #define all(v) v.begin(),v.end()
    #define pi pair<ll,ll>
    #define pb push_back
    #define S second
    #define F first
    #define die() return 0;
     
     
    #define md          998244353
    #define fmd         998244353 
    #define M           200011
    #define N            18
     
    #define i32 int32_t
     
    #define RBTTYPE int
    #define ordered_set tree<RBTTYPE, null_type, less<RBTTYPE>, rb_tree_tag,tree_order_statistics_node_update> 
     
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
     
    ll exp(ll a,ll b){ll r=1;while(b){if(b&1)r=r*a%md,r%=md;a=a*a%md;b/=2;}return r;}
    ll gcd(ll a,ll b){if(a<b)swap(a,b);if(b==0)return a;return gcd(b,a%b);}
     
    inline ll rand(ll l,ll r) {
        return (l+uniform_int_distribution<ll>(0, r-l)(rng));
    }
    string getStr(int n){
    	stringstream ss;
    	ss<<n;
    	return ss.str();
    }
    int solve(){
        ll n,i,j,k,m,x,y,z;
        cin>>n;
        m=0;
        set<string> eg,rg;
        for(i=0;i<n;++i){
        	string s;
        	cin>>s>>x;
        	m+=x;
        	if(x)
        		eg.insert(s);
        	else
        		rg.insert(s);
        }
        set<string> feg,frg;
        for(i=1;i<=m;++i)feg.insert(getStr(i));
        for(i=m+1;i<=n;++i)frg.insert(getStr(i));
     
        set<string> se,sr;
        for(i=1;i<=m;++i){
        	string g=getStr(i);
        	if(eg.count(g)){
        		eg.erase(eg.find(g));
        		feg.erase(feg.find(g));
        	}
        	if(rg.count(g)){
        		rg.erase(rg.find(g));
        		feg.erase(feg.find(g));
        		sr.insert(g);
        	}
        }
        for(i=m+1;i<=n;++i){
        	string g=getStr(i);
        	if(rg.count(g)){
        		rg.erase(rg.find(g));
        		frg.erase(frg.find(g));
        	}
        	if(eg.count(g)){
        		eg.erase(eg.find(g));
        		frg.erase(frg.find(g));
        		se.insert(g);
        	}
        }
        vector<pair<string,string>> moves;
        if(se.size()||sr.size()){
        	if(!feg.size()&&!frg.size()){
        		if(se.size()){
        			string oi=*se.begin();
        			se.erase(se.begin());
        			moves.pb({oi,"pppdda"});
        			eg.insert("pppdda");
        			frg.insert(oi);
        		}
        		else{
        			string oi=*sr.begin();
        			sr.erase(sr.begin());
        			moves.pb({oi,"pppdda"});
        			rg.insert("pppdda");
        			feg.insert(oi);
        		}
        	}
        	while(se.size()||sr.size()){
        		if(se.size()&&feg.size()){
        			string oi=*se.begin();
        			se.erase(se.begin());
        			moves.pb({oi,*feg.begin()});
        			feg.erase(feg.begin());
        			frg.insert(oi);
        		}
        		if(sr.size()&&frg.size()){
        			string oi=*sr.begin();
        			sr.erase(sr.begin());
        			moves.pb({oi,*frg.begin()});
        			frg.erase(frg.begin());
        			feg.insert(oi);
        		}
        	}
        }
        while(eg.size()){
        	moves.pb({*eg.begin(),*feg.begin()});
        	feg.erase(feg.begin());
        	eg.erase(eg.begin());
        }
        while(rg.size()){
        	moves.pb({*rg.begin(),*frg.begin()});
        	frg.erase(frg.begin());
        	rg.erase(rg.begin());
        }
        cout<<moves.size()<<"\n";
        for(auto p:moves){
        	cout<<"move "<<p.F<<" "<<p.S<<"\n";
        }
    	die();
    }
    void prec(){
     
     
    }     
     
    int main(){
     
     
    #ifndef ONLINE_JUDGE
        double _tBeg=clock();
    #endif
     
         
        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
     
        int t;
        t=1;;
        prec();
        // cin>>t;
     
        while(t--){
     
            solve();
        }
     
     
     
     
     
     
    #ifndef ONLINE_JUDGE
        double _tEnd=clock();
        // printf("\ntotal time %.6f\n",(_tEnd-_tBeg)/CLOCKS_PER_SEC);
    #endif
     
        die();
    }