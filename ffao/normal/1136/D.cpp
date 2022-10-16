#include <string>
#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <queue>
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#include <cstring> 

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define all(v) (v).begin(), (v).end()
#define sz(x) (int)(x).size()
#define trav(a, x) for(auto& a : x)
//#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define rep(i, a) for(int i = 0; i < (a); ++i)

int n,m;
int p[310000];
set<int> sw[310000];

vector<int> block;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> p[i];
    for (int i = 0; i < m; i++) {
        int u,v;
        cin >> u >> v;
        sw[u].insert(v);
    }

    int cur = 0;
    for (int i = n-2; i >= 0; i--) {
        bool ok = sw[p[i]].count(p[n-1]);

        if (ok) {
            for (int k : block) {
                if (!sw[p[i]].count(k)) {
                    ok = false;
                    break;
                }
            } 
        }

        if (!ok) block.push_back(p[i]);
        else cur++;
    }

    cout << n-1 - (int)block.size();
}