#include <stdio.h>
#include <set>
#include <vector>
#include <algorithm>
 
using namespace std;

vector<int> g[110000];
int val[110000];
long long mult[110000];
long long small[110000];
long long tot = 0;
int n,a,b;

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b,a%b);
}

long long get(long long a, long long b) {
    if (a == -1) return -1;

    long long g = gcd(a,b);
    b /= g;

    if (tot / b < a) return -1;
    return a*b;
}

void dfs(int v, int p) {
    long long ch = g[v].size();
    mult[v] = 1;

    if (ch == 1 && p != -1) {
        small[v] = val[v];
        return;
    }

    long long min_ind = 1000000000000000000LL;

    for (int i = 0; i < ch; i++) {
        int child = g[v][i];
        if (child == p) continue;

        dfs(child, v);

        mult[v] = get(mult[child], mult[v]);
        if (mult[v] == -1) {
            small[v] = 0;
            return;
        }

        min_ind = min(small[child], min_ind);
    }

    if (v != 1) ch--;
    if (tot / mult[v] < ch) {
        small[v] = 0;
        return;
    }
    
    small[v] = (min_ind - (min_ind % mult[v])) * ch;
    mult[v] *= ch;
}

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &val[i]);
        tot += val[i];
    }
    for (int i = 0; i < n-1; i++) {
        scanf("%d %d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(1, -1);
    printf("%I64d\n", tot - small[1]);
}