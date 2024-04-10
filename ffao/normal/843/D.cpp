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


#include <tuple>


typedef pair<int, int> pii;


int n, m, qq;

vector< pii > g[110000];
pii e[110000];
long long d1[110000];
long long dist[110000];
int used[110000];

vector<int> vs[110000];

void solve()
{
    scanf("%d %d %d", &n, &m, &qq);

    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c); a--; b--;
        e[i] = {a, g[a].size()};
        g[a].push_back({b, c});
    }

    for (int i = 0; i < n; i++) d1[i] = 1000000000000000000LL;
    
    set< pair<long long, int> > q;
    d1[0] = 0;
    q.insert({d1[0], 0});

    while (!q.empty()) {
        int cur = q.begin()->second;
        q.erase(q.begin());

        for (auto p : g[cur]) {
            long long nd = p.second + d1[cur];
            if (d1[p.first] > nd) {
                q.erase({d1[p.first], p.first});
                d1[p.first] = nd;
                q.insert({d1[p.first], p.first});
            }
        }
    }

    for (; qq; qq--) {
        int op, v;
        scanf("%d %d", &op, &v);

        if (op == 1) {
            printf("%lld\n", d1[v-1] == 1000000000000000000LL ? -1 : d1[v-1]);
            continue;
        }

        for (int j = 0; j < v; j++) {
            int ei; scanf("%d", &ei); ei--;
            g[e[ei].first][e[ei].second].second++;
        }

        for (int j = 0; j < n; j++) {
            used[j] = 0;
            dist[j] = n+1;
        }
        dist[0] = 0;
        vs[0].push_back(0);

        for (int i = 0; i < n; i++) {
            while (!vs[i].empty()) {
                int cur = vs[i].back();
                vs[i].pop_back();
                
                if (used[cur]) continue;
                used[cur] = 1;

                for (auto p : g[cur]) {
                    long long nd = dist[cur] + p.second - (d1[p.first] - d1[cur]);
                    if (nd < dist[p.first] && nd < n) {
                        dist[p.first] = nd;
                        vs[nd].push_back(p.first);
                    } 
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (d1[i] < 1000000000000000000LL) d1[i] += dist[i];
        }
    }
}


int main() {


    solve();
}