/**
TASK:
USER: gabriel90
LANG: C++
**/
#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for(int i=0; i<(n); i++)
#define printVec(v) for(auto e: v){cout << e << " ";} cout << endl;
#define pb push_back
#define MOD 1000000007
#define f first
#define s second

typedef long long ll;
typedef double ld;
typedef long double lld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;
typedef vector<vi> vii;

//Printing pairs and vectors
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
  cout << "["; for(int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]";
}

void fast_io(){
   ios_base::sync_with_stdio(0);
   cin.tie(NULL);
   cout.tie(NULL);
}
void file_io(string taskname){
   string fin = taskname + ".in";
   string fout = taskname + ".out";
   const char* FIN = fin.c_str();
   const char* FOUT = fout.c_str();
   freopen(FIN, "r", stdin);
   freopen(FOUT, "w", stdout);
   fast_io();
}

vl u(300000);
int c1n, c2n, cbn;
ll x, y;

ll query(int x){
    if(x==-1){
        return 0;
    }
    return u[x];
}
ll query(int a, int b){
    return query(b)-query(a-1);
}

ll tot(){
    ll ans = 0;
    int strt = 0;
    if(cbn>0){
        ans += query(0,cbn-1)*(x+y)/100;
        strt = cbn;
    }
    if(x>y){
        ans += query(strt,strt+c1n-1)*(x)/100;
        strt += c1n;
        ans += query(strt,strt+c2n-1)*(y)/100;
    }else{
        ans += query(strt,strt+c2n-1)*(y)/100;
        strt += c2n;
        ans += query(strt,strt+c1n-1)*(x)/100;
    }
    return ans;
}

int main(){
    fast_io();
    int q;
    cin >> q;
    forn(qi,q){
        int n;
        cin >> n;
        vl v(n);
        forn(i,n){
            cin >> v[i];
        }
        sort(v.begin(),v.end());
        u[0] = v[n-1];
        for(int i=1; i<n; i++){
            u[i] = v[n-1-i]+u[i-1];
        }
        ll a, b, k;
        cin >> x >> a >> y >> b >> k;

        int c1 = -1;
        int c2 = -1;
        c1n = 0;
        c2n = 0;
        cbn = 0;
        //cout << u;
        while(true){
            if(c1+a >= n){
                if(c2+b >= n){
                    break;
                }else{
                    c2 += b;
                    c2n++;
                    if(tot() >= k){
                        break;
                    }
                }
            }else{
                if(c2+b >= n){
                    c1 += a;
                    c1n++;
                    if(tot() >= k){
                        break;
                    }
                }else{
                    if(c2+b==c1+a){
                        c1+=a;
                        c2+=b;
                        cbn++;
                        if(tot() >= k){
                            break;
                        }
                    }else{
                        if(c1+a<c2+b){
                            c1 += a;
                            c1n++;
                            if(tot() >= k){
                                break;
                            }
                        }else{
                            c2 += b;
                            c2n++;
                            if(tot() >= k){
                                break;
                            }
                        }
                    }
                }
            }
            //cout << c1 << " " << c2 << " " << c1n << " " << c2n << " " << cbn << " " << tot() << endl;
        }

        if(tot()<k){
            cout << -1 << endl;
        }else{
            cout << max(c1,c2) + 1 << endl;
        }

    }
}