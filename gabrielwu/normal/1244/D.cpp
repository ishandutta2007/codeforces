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

//2 147 483 647 int max
//9 223 372 036 854 775 807 ll max
void fast_io(){
   ios_base::sync_with_stdio(0);
   cin.tie(NULL);
   cout.tie(NULL);
}

int main(){
    fast_io();
    int n;
    cin >> n;
    vector<vl> cost(n,vl(3));
    vector<vl> out(n,vl(6));
    vector<bool> visited(n,false);
    vector<vi> conn(n);
    forn(i,3){
        forn(j,n){
            cin >> cost[j][i];
        }
    }
    forn(i,n-1){
        int x, y;
        cin >> x >> y;
        conn[x-1].pb(y-1);
        conn[y-1].pb(x-1);
    }
    forn(i,n){
        if(conn[i].size() > 2){
            cout << -1 << endl;
            return 0;
        }
    }
    int start = 0;
    while(conn[start].size()==2){
        start++;
    }

    ll tot0 = 0, tot1=0, tot2=0, tot3=0, tot4=0, tot5=0;
    int curr = start;
    vi seq;
    forn(i,n){
        seq.pb(curr);
        visited[curr] = true;
        if(conn[curr].size()==2){
            if(visited[conn[curr][0]]){
                curr = conn[curr][1];
            }else{
                curr = conn[curr][0];
            }
        }else{
            curr = conn[curr][0];
        }
    }

    forn(i,n){
        curr = seq[i];
        tot0 += cost[curr][(i+0)%3];
        out[curr][0] = (i+0)%3+1;
        tot1 += cost[curr][(i+1)%3];
        out[curr][1] = (i+1)%3+1;
        tot2 += cost[curr][(i+2)%3];
        out[curr][2] = (i+2)%3+1;
        tot3 += cost[curr][(-i+3000000)%3];
        out[curr][3] = (-i+3000000)%3+1;
        tot4 += cost[curr][(-i+1+3000000)%3];
        out[curr][4] = (-i+1+3000000)%3+1;
        tot5 += cost[curr][(-i+2+3000000)%3];
        out[curr][5] = (-i+2+3000000)%3+1;
    }

    ll best = min(min(min(tot0,tot1),tot2),min(min(tot3,tot4),tot5));
    //cout << seq << endl;
    //cout << tot0 << tot1 << tot2 << tot3<<tot4<<tot5<<endl;
   cout << best << endl;
    if(tot0==best){
        forn(i,n){
            cout << out[i][0] << " ";
        }cout << endl;
    }else if(tot1==best){
        forn(i,n){
            cout << out[i][1] << " ";
        }cout << endl;
    }else if(tot2==best){
        forn(i,n){
            cout << out[i][2] << " ";
        }cout << endl;
    }else if(tot3==best){
        forn(i,n){
            cout << out[i][3] << " ";
        }cout << endl;
    }else if(tot4==best){
        forn(i,n){
            cout << out[i][4] << " ";
        }cout << endl;
    }else if(tot5==best){
        forn(i,n){
            cout << out[i][5] << " ";
        }cout << endl;
    }

}