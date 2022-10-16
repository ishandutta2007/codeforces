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


#define rep(i, a, b) for(int i = a; i < (b); ++i)


int n,k;
vector<int> g[210000];
int f[210000];
int d[210000];
int color[210000];
int b;

void ddfs(int v, int p) {
    d[v] = (p == -1 ? 0 : d[p]+1);
    f[v] = p;
    if (d[v] > d[b]) b = v;
    for (int x : g[v]) if (x != p) ddfs(x,v);
}

int cdfs(int v, int p, int c, int d) {
    c = (((c+d)%k)+k)%k;
    color[v] = c;
    int h = 1;
    for (int x : g[v]) if (x != p) {
        h = max(h, cdfs(x,v,c,d)+1);
    }
    return h;
}

void solve()
{
    scanf("%d %d", &n, &k);

    rep(i,0,n-1) {
        int a, b;
        scanf("%d %d", &a, &b); a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    b = 0;
    ddfs(0,-1);
    ddfs(b,-1);
    
    vector<int> path;
    while (b != -1) {
        path.push_back(b);
        b = f[b];
    }

    for (int i = 0; i < path.size(); i++) {
        color[path[i]] = i%k;

        for (int x : g[path[i]]) {
            if (i != 0 && path[i-1] == x) continue;
            if (i+1 < path.size() && path[i+1] == x) continue;

            int left = i + 1;
            int right = path.size() - i; 
            int delta = (right > left ? -1 : +1);

            int h = cdfs(x, path[i], i%k, delta);
            if (h + min(left,right) >= k && k > 2) {
                printf("No");
                return;
            }
        }
    }

    printf("Yes\n");
    rep(i,0,n) printf("%d ", color[i]+1);
}


int main() {


    solve();
}