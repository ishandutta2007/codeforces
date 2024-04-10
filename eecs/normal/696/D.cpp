#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 210;
int n, tot = 1, a[maxn], ed[maxn], ch[maxn][26], fail[maxn];
ll L;
struct mat { ll a[maxn][maxn]; } A, B;

mat operator * (const mat &A, const mat &B) {
    mat C; memset(C.a, -0x3f, sizeof(C.a));
    for (int i = 1; i <= tot; i++) {
        for (int j = 1; j <= tot; j++) {
            for (int k = 1; k <= tot; k++) {
                C.a[i][k] = max(C.a[i][k], A.a[i][j] + B.a[j][k]);
            }
        }
    }
    return C;
}

int main() {
    ios::sync_with_stdio(0);
    cin >> n >> L;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        string s; cin >> s;
        int cur = 1;
        for (char $ : s) {
            int c = $ - 'a';
            while (!ch[cur][c]) ch[cur][c] = ++tot;
            cur = ch[cur][c];
        }
        ed[cur] += a[i];
    }
    fill(ch[0], ch[0] + 26, 1);
    queue<int> Q; Q.push(1);
    while (!Q.empty()) {
        int v = Q.front(); Q.pop();
        ed[v] += ed[fail[v]];
        for (int c = 0; c < 26; c++) {
            if (ch[v][c]) fail[ch[v][c]] = ch[fail[v]][c], Q.push(ch[v][c]);
            else ch[v][c] = ch[fail[v]][c];
        }
    }
    memset(A.a[1], -0x3f, sizeof(A.a[1]));
    A.a[1][1] = 0;
    memset(B.a, -0x3f, sizeof(B.a));
    for (int i = 1; i <= tot; i++) {
        for (int c = 0; c < 26; c++) {
            B.a[i][ch[i][c]] = 0;
        }
        for (int c = 0; c < 26; c++) {
            B.a[i][ch[i][c]] += ed[ch[i][c]];
        }
    }
    for (; L; L >>= 1, B = B * B) {
        if (L & 1) A = A * B;
    }
    printf("%lld\n", *max_element(A.a[1] + 1, A.a[1] + tot + 1));
    return 0;
}