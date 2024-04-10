#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cassert>
#include <map>
#include <numeric>
#include <cstring>
#include <set>
#include <ctime>
#include <queue>
#include <cmath>
#include <iomanip>
#include <iterator>
#include <bitset>
#include <unordered_map>
#include <complex>
#include <unordered_set>
#include <chrono>
#include <random>
#include <functional>
#include <random>

using namespace std;
///started 11:42

const int maxLength = 200009, maxNodes = maxLength, sigma = 26;
int N, cnt[maxLength];
char t[maxLength], s[maxLength];

struct ahoCorasick {
    int nodes = 1, nxt[maxNodes][sigma], cnt[maxNodes], phi[maxNodes], q[maxNodes + 2];

    void addString(char s[], int len) {
        int q = 1;
        for (int i=0; i<len; i++) {
            char c = s[i] - 'a';
            if (nxt[q][c] == 0) nxt[q][c] = ++nodes;
            q = nxt[q][c];
        }
        cnt[q] ++;
    }

    int getNextState(int state, int c) {
        while (state != 1 && nxt[state][c] == 0)
            state = phi[state];
        if (nxt[state][c] != 0)
            state = nxt[state][c];
        return state;
    }

    void process() {
        q[0] = q[1] = 1, phi[1] = 0;
        for (int i=1; i<=q[0]; i++)
            for (int j=0; j<sigma; j++)
                if (nxt[q[i]][j] != 0) {
                    int node = nxt[q[i]][j];
                    q[++q[0]] = node;
                    if (q[i] != 1)
                        phi[node] = getNextState(phi[q[i]], j);
                    else
                        phi[node] = 1;
                    cnt[node] += cnt[phi[node]];
                }
    }
}standard, reversed;

int main() {
    //freopen("../input", "r", stdin);
    scanf("%s", t + 1), N = strlen(t + 1);
    int M;
    scanf ("%d\n", &M);
    while (M --) {
        int len;
        scanf("%s", s + 1);
        len = strlen(s + 1);
        standard.addString(s + 1, len);
        reverse (s + 1, s + len + 1);
        reversed.addString(s + 1, len);
    }
    standard.process();
    reversed.process();
    int q = 1;
    for (int i=1; i<=N; i++) {
        q = standard.getNextState(q, t[i] - 'a');
        cnt[i] = standard.cnt[q];
    }
    q = 1;
    long long ans = 0;
    for (int i=N; i>=1; i--) {
        q = reversed.getNextState(q, t[i] - 'a');
        ans += 1LL * reversed.cnt[q] * cnt[i - 1];
    }
    printf("%lld\n", ans);
    return 0;
}