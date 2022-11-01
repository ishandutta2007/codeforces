#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, m, k;
char s[MN]; string str;

struct trie {
    trie* ch[26];
    int sz;

    trie() {
        for(int i = 0; i < 26; i++) ch[i] = NULL;
        sz = 1;
    }

    void add(string& str, int pos) {
        if(pos == str.size()) return;
        int nxt = str[pos]-'a';

        if(ch[nxt] == NULL) ch[nxt] = new trie();
        ch[nxt]->add(str, pos + 1);
    }

    void dfs() {
        for(int i = 0; i < 26; i++) {
            if(ch[i] != NULL) {
                ch[i]->dfs();
                sz += ch[i]->sz;
            }
        }
    }

    void search(string& ans, ll k) {
        if(k == 0) return;
        k--;
        for(int i = 0; i < 26; i++) {
            if(ch[i] == NULL) continue;
            if(ch[i]->sz <= k) k -= ch[i]->sz;
            else {
                ans += char('a' + i);
                ch[i]->search(ans, k);
                break;
            }
        }
    }

} dic;

ll dp[1010][1010], safe[1010];

const ll INF = 1000001000000000000LL;

ll solve(string& gr) {
    memset(dp, 0, sizeof dp);

    for(int i = 0; i < n; i++) {
        safe[i] = -2;
        for(int j = 0; j < gr.size() && i + j < n; j++) {
            if(str[i+j] < gr[j]) safe[i] = -1;
            else if(str[i+j] > gr[j]) safe[i] = i+j+1;
            else continue;
            break;
        }
        if(safe[i] == -2 && i + gr.size() > n)
            safe[i] = -1;
        else if(safe[i] == -2)
            safe[i] = i + gr.size();
    }

    for(int i = 0; i <= n; i++)
        dp[i][0] = 1;

    for(int ss = 1; ss <= m; ss++) {

        for(int i = 0; i < n; i++) {
            if(safe[i] == -1) continue;
            dp[i][ss] = dp[safe[i]][ss-1];
            if(dp[i][ss] >= INF) dp[i][ss] = INF;
        }

        for(int i = n-1; ss < m && i >= 0; i--) {
            dp[i][ss] += dp[i+1][ss];
            if(dp[i][ss] >= INF) dp[i][ss] = INF;
        }
    }

    return dp[0][m];
}

int main() {
    scanf("%lld %lld %lld", &n, &m, &k);
    scanf("%s", s); str = s;

    for(int i = 0; i < n; i++)
        dic.add(str, i);

    dic.dfs();

    ll l = 1, r = dic.sz - 1, m;
    while(l < r) {
        m = (l + r + 1) / 2;
        string tmp;
        dic.search(tmp, m);

        if(solve(tmp) >= k) l = m;
        else r = m - 1;
    }


    string ans;
    dic.search(ans, l);
    printf("%s\n", ans.c_str());
    return 0;
}