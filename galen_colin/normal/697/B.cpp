#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld; 
typedef double db; 
typedef string str; 

typedef pair<int, int> pi;
typedef pair<ll,ll> pl; 
typedef pair<ld,ld> pd; 

typedef vector<int> vi; 
typedef vector<ll> vl;
typedef vector<ld> vd; 
typedef vector<str> vs; 
typedef vector<pi> vpi;
typedef vector<pl> vpl; 

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)

#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound 
#define ub upper_bound 

const int MOD = 998244353;
const ll INF = 1e18;
const int MX = 1000001;

str S, T, U, V = "";

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
    bool flag = false;
    cin >> S;
    F0R(i, sz(S)) {
        if (S[i] == 'e') flag = true;
        if (S[i] != '.' && S[i] != 'e') {
            if (!flag) T += S[i];
            else U += S[i];
        }
    }

    while(T.back() == '0') {
        T.pop_back();
    }


    flag = false;
    int a = stoi(U);
    F0R(i, a + 1) {
        if (i < sz(T)) V += T[i];
        else { 
            flag = true;
            V += '0';
        }
        if (i == sz(T) - 1) flag = true;
    }

    if (!flag) {
        V += '.';
        FOR(i, a + 1, sz(T)) {
            V += T[i];
        }
    }
    
    flag = false;
    F0R(i, sz(V)) {
        if (i == sz(V) - 1 || V[i + 1] != '0' || V[i] != '0') {
            flag = true;
        }
        if (flag) cout << V[i];
    }
    return 0;
    // You should actually read the stuff at the bottom
}

/* Stuff to Look For
 * -----------------
 * Int overflow, array bounds
 * Initializing all variables, avoid weird behavior
 * Edge cases(n = 0, n = 1)
 * Just return 0 after result
 */