#include <string>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string.h>
#include <utility>
#include <queue>
#include <stack>
#include <iomanip>
#include <ctype.h>
#include <sstream>
#include <map>
#include <set>
#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>
#include <iostream>
#include <unordered_map>

using namespace std;

typedef long long LL;

vector< pair<int, int> > adj[210000];
vector< int > pd[210000];
pair<int, int> pd2[210000];
int needscalc[210000];
int tot[210000];

int n;

int mod = 1000000007;

int modpow(int x, int e) {
    int ans = 1;
    while (e) {
        if (e & 1) ans = (ans * 1ll * x) % mod;
        x = (x * 1ll * x) % mod;
        e >>= 1;
    }
    return ans;
}

int modinv(int x) {
    return modpow(x, mod-2);
}

void mul( pair<int, int>& p, int x) {
    if (x == 0) p.second++;
    else p.first = (p.first * 1ll * x) % mod;
}

void div( pair<int, int>& p, int x) {
    if (x == 0) p.second--;
    else p.first = (p.first * 1ll * modinv(x)) % mod;
}

int dfs(int v, int p) {
    int &ret = pd[v][p+1];
    
    if (ret == -1) {
        pair<int, int> &ans = pd2[v];
        
        if (ans.first == -1) {
            ans = make_pair(1, 0);

            for (int k = 0; k < (int)adj[v].size(); k++) {
                if (k == p) continue;

                int th = 1;
                th = (th + dfs(adj[v][k].first, adj[v][k].second)) % mod;
                mul(ans, th);
            }

            needscalc[v] = p;
        }

        if (needscalc[v] != p && needscalc[v] != -1) {
            int th = 1;
            th = (th + dfs(adj[v][needscalc[v]].first, adj[v][needscalc[v]].second)) % mod;
            mul(ans, th);

            needscalc[v] = -1;
        }

        pair<int, int> tt = ans;

        if (p != -1 && p != needscalc[v]) {
            int th = 1;
            th = (th + dfs(adj[v][p].first, adj[v][p].second)) % mod;
            div(tt, th);
        }

        ret = tt.second ? 0 : tt.first;
    }   

    return ret;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) pd2[i] = make_pair(-1,-1);

    for (int i = 1; i < n; i++) {
        int pp;
        scanf("%d", &pp); pp--;

        adj[i].push_back( make_pair(pp, adj[pp].size()) );
        adj[pp].push_back( make_pair(i, adj[i].size()-1) );
    }

    for (int i = 0; i < n; i++) {
        pd[i].resize(adj[i].size()+1, -1);
    }


    for (int i = 0; i < n; i++) {
        printf("%d ", dfs(i, -1));
    }
}