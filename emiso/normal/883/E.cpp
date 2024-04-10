#include <bits/stdc++.h>

using namespace std;

int n, m;
string s, w[1010];
bool app[300];

int main() {
    scanf("%d", &n);
    cin >> s;
    for (int i = 0; i < s.size(); i++)
        if (s[i] != '*')
            app[s[i]] = true;

    scanf("%d", &m);
    for (int i = 0; i < m; i++)
        cin >> w[i];

    vector < string > valid;
    for (int i = 0; i < m; i++) {
        bool v = true;
        for (int j = 0; j < w[i].size(); j++)
            if (s[j] == '*' && app[w[i][j]]) v = false;
            else if (s[j] != '*' && w[i][j] != s[j]) v = false;

        if (v) valid.push_back(w[i]);
    }

    int ans = 0;
    for (char c = 'a'; c <= 'z'; c++) {
        if (app[c]) continue;
        int cnt = 0;
        for (int i = 0; i < valid.size(); i++) {
            bool v = false;
            for (int j = 0; j < valid[i].size(); j++)
                if (s[j] == '*' && valid[i][j] == c)
                    v = true;
            if (v) cnt++;
        }
        if (cnt == valid.size()) ans++;
    }

    printf("%d\n", ans);
    return 0;
}