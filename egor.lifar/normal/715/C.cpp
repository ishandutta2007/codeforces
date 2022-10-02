#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <bitset>
#include <unordered_map>


using namespace std;


const int MAXN = (int)1e5 + 288;
int n, Mod, M;


inline int myPow(int x, int a) {
    int ans = 1;
    while (a > 0) {
        if (a & 1) {
            a--;
            ans = (1LL * ans * x) % Mod;
        }
        x = (1LL * x * x) % Mod;
        a >>= 1;
    }
    return ans;
} 


int minusOfDegrees(int a, int b) {
    if (b == 0) {
        return 1;
    }
    return pow(a, b) - pow(a, b - 1);   
}


int getCnt(int n) {
    int i = 2;
    int ans = 1;
    while (i * i <= n) {
        int cnt = 0;
        while (n % i == 0) {
            cnt++;
            n /= i;
        }
        ans *= minusOfDegrees(i, cnt);
        i++;
    }
    if (n != 1) {
        ans *= (n - 1);
    }
    return ans; 
}


bool used[MAXN];
int s[MAXN];
int numberOfComponent[MAXN];
int dist[MAXN];
int a[MAXN], b[MAXN];
vector<int> costOfEdge[MAXN];
vector<int> graph[MAXN];


void dfs(int i, int p, vector<int> &st) {
    s[i] = 1;
    if (p == -1) {
        numberOfComponent[i] = -1;
        a[i] = 0;
        b[i] = 0;
        dist[i] = 0;
    }
    st.push_back(i);
    for (int k = 0; k < (int)graph[i].size(); k++) {
        int j = graph[i][k];
        int c = costOfEdge[i][k];
        if (p != j && !used[j]) {
            if (p == -1) {
                numberOfComponent[j] = j;
            } else {
                numberOfComponent[j] = numberOfComponent[i];
            }
            dist[j] = dist[i] + 1;
            a[j] = (1LL * a[i] * 10 + c) % Mod;
            b[j] = (1LL * b[i] * M + c) % Mod;
            dfs(j, i, st);
            s[i] += s[j];
        } 
    }
}


long long ans = 0;
map<int, int> cnt[2];


void centroidDecomposition(int i) {
    vector<int> st;
    used[i] = true;
    dfs(i, -1, st);
    cnt[0].clear();
    cnt[1].clear();
    for (int k = 0; k < 2; k++) {
        for (int j = 0; j < (int)st.size(); j++) {
            if (j != 0 && numberOfComponent[st[j]] != numberOfComponent[st[j - 1]]) {
                for (int u = j - 1; u >= 0; u--) {
                    cnt[k][((1LL * myPow(10LL, dist[st[u]]) * b[st[u]] % Mod) * M) % Mod]++;
                    if (u != 0 && numberOfComponent[st[u - 1]] != numberOfComponent[st[u]]) {
                        break;
                    }
                }
            }
            ans += cnt[k][(1LL * myPow(M, dist[st[j]]) * (Mod - a[st[j]])) % Mod];
        }
        reverse(st.begin(), st.end());
    }
    for (int j = (int)st.size() - 1; j >= 0; j--) {
        if (!used[st[j]] && s[st[j]] * 2 >= s[numberOfComponent[st[j]]]) {
            centroidDecomposition(st[j]);
        }
    }
}


int main () {
    ios::sync_with_stdio(false);
    cin >> n >> Mod;
    if (Mod == 1) {
        cout << 1LL * n * (n - 1) << endl;
        return 0;
    }
    M = myPow(10, getCnt(Mod) - 1);
    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        //scanf("%d %d %d", &a, &b, &c);
        cin >> a >> b >> c;
        graph[a].push_back(b);
        graph[b].push_back(a);
        costOfEdge[a].push_back(c);
        costOfEdge[b].push_back(c);
    }
    centroidDecomposition(0);
    cout << ans << endl;
    return 0;
}