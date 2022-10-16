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

#define INF 1000000000
#define pb push_back 
#define itr iterator 
#define sz size() 
#define mp make_pair

int n, m, k;

int killed[110000];
int neigh[110000];
int good[110000];
int fort[110000];
vector<int> adj[110000];

struct compara {
    bool operator() (int a, int b) const {
        long long aa = good[a] * 1ll * neigh[b];
        long long bb = good[b] * 1ll * neigh[a];
        if (aa < bb) return true;
        else if (bb < aa) return false;
        else return a < b;
    }
};

set<int, compara> ss;
vector<int> rem;

int main() {
    scanf("%d %d %d", &n, &m, &k);

    for (int i = 0; i < k; i++) {
        int c;
        scanf("%d", &c); c--;
        fort[c]=1;
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b); a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
        neigh[a]++;
        neigh[b]++;
        good[a] += (!fort[b]);
        good[b] += (!fort[a]);
    }

    for (int i = 0; i < n; i++) {
        if (!fort[i]) ss.insert(i);
    }

    double ans = 0;

    while (!ss.empty()) {
        int weakest = *ss.begin();
        ss.erase(ss.begin());

        double th = good[weakest] / (neigh[weakest] + 0.0);
        
        if (th > ans) {
            ans = th;
            rem.clear();
        }

        rem.push_back(weakest);
        killed[weakest]=1;

        for (int a : adj[weakest]) {
            if (!fort[a] && !killed[a]) {
                ss.erase(a);
                good[a]--;
                ss.insert(a);
            }
        }
    }

    printf("%d\n", rem.size());
    for (int city : rem) {
        printf("%d ", city+1);
    }
}