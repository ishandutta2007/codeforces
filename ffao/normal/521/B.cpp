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

int n;
pair<int, int> cubes[110000];
map< pair<int, int>, int> indexes;
int blocked[110000];
int supported[110000];
int mark[110000];
set<int> can_remove;

const int mod = 1000000009;

void block(int i) {
    int ny = cubes[i].second - 1;
    for (int nx = cubes[i].first-1; nx <= cubes[i].first+1; nx++) {
        pair<int, int> p = make_pair(nx, ny);
        auto it = indexes.find(p);
        if (it != indexes.end()) {
            blocked[it->second]++;
            can_remove.erase(it->second);
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &cubes[i].first, &cubes[i].second);
        indexes[ cubes[i] ] = i;
    }

    for (int i = 0; i < n; i++) {
        int ny = cubes[i].second + 1;
        for (int nx = cubes[i].first-1; nx <= cubes[i].first+1; nx++) {
            pair<int, int> p = make_pair(nx, ny);
            auto it = indexes.find(p);
            if (it != indexes.end()) {
                supported[it->second]++;
            }
        }
    }

    for (int i = 0; i < n; i++) if (supported[i] == 1) {
        int ny = cubes[i].second - 1;
        for (int nx = cubes[i].first-1; nx <= cubes[i].first+1; nx++) {
            pair<int, int> p = make_pair(nx, ny);
            auto it = indexes.find(p);
            if (it != indexes.end()) {
                blocked[it->second]++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (!blocked[i]) can_remove.insert(i);
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int rem;
        if (i & 1) rem = *can_remove.begin();
        else rem = *can_remove.rbegin();

        can_remove.erase(rem);
        ans = (ans * n + rem) % mod;
        mark[rem] = 1;

        if (supported[rem] == 1) {
            int ny = cubes[rem].second - 1;
            for (int nx = cubes[rem].first - 1; nx <= cubes[rem].first + 1; nx++) {
                pair<int, int> p = make_pair(nx, ny);
                auto it = indexes.find(p);
                if (it != indexes.end()) {
                    int idx = it->second;
                    if (!mark[idx]) {
                        blocked[idx]--;
                        if (!blocked[idx]) can_remove.insert(idx);
                    }
                }
            }
        }

        int ny = cubes[rem].second + 1;
        for (int nx = cubes[rem].first - 1; nx <= cubes[rem].first + 1; nx++) {
            pair<int, int> p = make_pair(nx, ny);
            auto it = indexes.find(p);
            if (it != indexes.end()) {
                int idx = it->second;
                if (!mark[idx]) {
                    supported[idx]--;
                    if (supported[idx] == 1) {
                        block(idx);
                    }
                }
            }
        }

    }

    printf("%d\n", (int) ans);
}