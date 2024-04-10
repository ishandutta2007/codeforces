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


vector<int> g[210000];
int h[210000];
int f[210000];
int b;
int n;

void dfs(int v, int p) {
    f[v] = p;
    h[v] = p == -1 ? 0 : h[p]+1;

    if (h[v] > h[b]) b = v;
    for (int x : g[v]) if (x != p) {
        dfs(x,v);
    }
}

int check(int v, int p) {
    if (g[v].size() == (p!=-1)) return 0;
    if (g[v].size() != 2 + (p!=-1)) return -1;

    vector<int> cs;
    for (int x : g[v]) if (x != p) cs.push_back(check(x,v));
    if (cs[0] == -1 || cs[0] != cs[1]) return -1;
    return cs[0]+1;
}

pair<int, int> bcheck(int v, int p) {
    if (g[v].size() == (p!=-1)) {
        return {0, -1};
    }
    if (g[v].size() == 1 + (p!=-1)) {
        vector<int> cs;
        for (int x : g[v]) if (x != p) cs.push_back(check(x,v));
        if (cs[0] == 0) return {1, v};
        return {-1, 0};
    }
    if (g[v].size() == 2 + (p!=-1)) {
        vector<pair<int, int>> cs;
        for (int x : g[v]) if (x != p) cs.push_back(bcheck(x,v));
        if (cs[0].first == -1 || cs[0].first != cs[1].first || min(cs[0].second, cs[1].second) != -1) return {-1, 0};
        return {cs[0].first+1, max(cs[0].second, cs[1].second)};
    }
    if (g[v].size() == 3 + (p!=-1)) {
        vector<int> cs;
        for (int x : g[v]) if (x != p) cs.push_back(check(x,v));
        sort(cs.begin(), cs.end());
        if (cs[0] != -1 && cs[0] == cs[1] && cs[1]+1==cs[2]) return {cs[2]+1, v};
        return {-1, 0};
    }
    return {-1, 0};
}

void solve()
{
    scanf("%d", &n);

    for (int i = 0; i < (1<<n)-3; i++) {
        int a, b;
        scanf("%d %d", &a, &b); a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    b = 0;
    dfs(0, -1);
    int p1 = b;
    dfs(p1, -1);

    vector<int> pt;
    while (b != -1) {
        pt.push_back(b);
        b = f[b];
    }
    
    if (pt.size() % 2 == 0) {
        int r1 = pt[pt.size()/2];
        int r2 = pt[pt.size()/2-1];
        if (r2 < r1) swap(r1,r2);

        int c1 = check(r1,r2);
        int c2 = check(r1,r2);
        if (c1 == c2 && c1 != -1) {
            printf("2\n");
            printf("%d %d\n", r1+1, r2+1);
            return;
        }
        else {
            printf("0\n");
            return;
        }
    }
    
    int r = pt[pt.size()/2];
    pair<int, int> bc = bcheck(r,-1);
    if (bc.first == -1) {
        printf("0\n");
        return;
    }
    printf("1\n%d\n", bc.second+1);
}


int main() {


    solve();
}