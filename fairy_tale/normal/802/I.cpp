#include<bits/stdc++.h>
#define fi first
#define se second
#define LSON t << 1, l, mid
#define RSON t<< 1 | 1, mid + 1, r
#ifdef FEIFEI
#define Debug printf
#else
#define Debug(...)
#endif

using namespace std;
typedef long long LL;
typedef pair<int, int> P;

const int mod = 998244353;
const int maxn = 3e5 + 5;

const int inf = 0x3fffffff;
LL ans1[maxn], ans2[maxn];

struct suffixTree {
    int link[maxn << 1], len[maxn << 1], start[maxn << 1], s[maxn << 1], n, tail, now, rem, ch[maxn << 1][27];
    suffixTree (): tail(1), n(0), rem(0), now(1) {len[0] = inf;}

    void clear() {
        for (int i = 0; i <= tail; i++) memset(ch[i], 0, sizeof(int) * 27);
        tail = now = 1;
        n = rem = 0;
        len[0] = inf;
    }
    int newnode(int st, int le)
    {
        link[++tail] = 1;
        start[tail] = st;
        len[tail] = le;
        return tail;
    }
    void extend(int x, int d) // d 
    {
        s[++n] = x;
        rem++; //1
        for (int last = 1; rem;){
            while (rem > len[ch[now][s[n - rem + 1]]])
                rem -= len[now = ch[now][s[n - rem + 1]]]; // 2
            int &v = ch[now][s[n - rem + 1]];
            int c = s[start[v] + rem - 1];
            if (!v || x == c){
                link[last] = now;
                last = now;
                if (!v) v = newnode(n, d); //3
                else break; //4.a
            } else { //4.b
                int u = newnode(start[v], rem - 1);
                ch[u][c] = v;
                ch[u][x] = newnode(n, d); //
                start[v] += rem - 1;
                len[v] -= rem - 1;
                link[last] = v = u;
                last = u;
            }
            if (now == 1) rem--;
            else now = link[now]; //5
        }
    }

    int dfs(int u, int depth, LL &ans) // u:nowNode  depth:prefixLen
    {
        int sz = 0;
        for (int i = 0; i <= 26; i++) {
            if (ch[u][i]) {
                sz += dfs(ch[u][i], depth + len[ch[u][i]], ans);
            }
        }

        if (sz == 0 && depth > 0) {
            sz = 1;
        }

        ans += 1LL * len[u] * sz * sz;
        return sz;
    }
} sft;

int a[maxn];
void solve()
{
    int n;
    LL ans = 0;
    string s;
    cin >> s;
    n = s.length();
    for (int i = 0; i < n; i++) sft.extend(s[i] - 'a', n - i);
    sft.extend(26, 0); // add end mask
    sft.dfs(1, 0, ans);
    sft.clear();
    cout << ans << endl;
}

int main()
{
#ifdef FEIFEI
    freopen("E:\\code\\input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    int pT = 1;
    cin >> pT;
    while (pT--) {
        solve();
    }

    Debug("Time: %.3lfs\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}