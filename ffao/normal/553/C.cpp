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

int n, k;
vector<int> adj_diff[110000];
vector<int> adj_same[110000];
int seen[110000];
int cc;

int mod = 1000000007;

bool dfs(int v, int color) {
    if (seen[v] != -1) {
        if (seen[v] == color) return true;
        return false;
    }

    seen[v] = color;

    for (int same : adj_same[v]) {
        if (!dfs(same, color)) return false;
    }

    for (int diff : adj_diff[v]) {
        if (!dfs(diff, color^1)) return false;
    }

    return true;
}

int main() {
    memset(seen,-1,sizeof(seen));
    scanf("%d %d", &n, &k);

    for (int i = 0; i < k; i++) {
        int a,b,c;
        scanf("%d %d %d", &a, &b, &c); b--; a--;
        if (c == 1) {
            adj_same[b].push_back(a);
            adj_same[a].push_back(b);
        }
        else {
            adj_diff[a].push_back(b);
            adj_diff[b].push_back(a);
        }
    }

    for (int i = 0; i < n; i++) {
        if (seen[i] == -1) {
            cc++;
            if (!dfs(i, 0)) {
                printf("0\n");
                return 0;
            }
        }
    }

    int ans = 1;
    for (int i = 1; i < cc; i++) {
        ans = (ans * 2) % mod;
    }
    printf("%d\n", ans);
}