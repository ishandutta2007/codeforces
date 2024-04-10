#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define rrep(i, a, b) for(int i = (a) - 1; i >= int(b); --i)
#define trav(it, v) for(auto &it : (v))
#define all(v) (v).begin(), (v).end()
#define what_is(x) cerr << #x << " is " << x << endl;
#define sz(x) (int)(x).size()

typedef double fl;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;

unordered_map<int, int> pCount[32];

int main(){
	ios::sync_with_stdio(0);
    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> P(N);
    rep(i,0,N)
        cin >> A[i];
    rep(i,0,N)
        cin >> P[i];
    rep(j,0,30) {
        int bits = (1<<30)-(1<<j);
        rep(i,0,N) {
            pCount[j][P[i]&bits]++;
        }
    }
    rep(i,0,N) {
        int bits = 0;
        rrep(j,30,0) {
            if (A[i]&(1<<j))
                bits ^= (1<<j);
            auto it = pCount[j].find(bits);
            if (it == pCount[j].end() || !it->second) {
                bits ^= (1<<j);
                it = pCount[j].find(bits);
            }
            --it->second;
        }
        cout << (A[i]^bits) << " ";
    }
    cout << endl;
}