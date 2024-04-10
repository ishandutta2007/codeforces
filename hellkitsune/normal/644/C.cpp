#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

map<string, vector<string> > ma;
vector<pair<string, string> > v;
vector<string> ans;

int n;
char buf[100];
string s;

int main() {
    scanf("%d", &n);
    REP(i, n) {
        scanf("%s", buf);
        s = string(buf);
        int cnt = 0, ind = 0;
        while (ind < (int)s.length()) {
            if (s[ind] == '/') ++cnt;
            if (cnt == 3) break;
            ++ind;
        }
        ma[s.substr(0, ind)].pb("#" + s.substr(ind));
    }
    for (auto &entry : ma) {
        sort(entry.second.begin(), entry.second.end());
        entry.second.erase(unique(entry.second.begin(), entry.second.end()), entry.second.end());
        string tot;
        for (string x : entry.second) {
            for (char c : x) {
                tot.pb(c);
            }
        }
        v.pb(mp(tot, entry.first));
    }
    sort(v.begin(), v.end());
    //for (auto x : v) printf("%s %s\n", x.first.c_str(), x.second.c_str());
    int sz = (int)v.size();
    for (int beg = 0; beg < sz; ) {
        int end = beg + 1;
        while (end < sz && v[end].first == v[beg].first) ++end;
        if (end - beg > 1) {
            string tot = v[beg].second;
            for (int i = beg + 1; i < end; ++i) {
                tot.pb(' ');
                for (char c : v[i].second) {
                    tot.pb(c);
                }
            }
            ans.pb(tot);
        }
        beg = end;
    }
    printf("%d\n", (int)ans.size());
    for (string x : ans) {
        printf("%s\n", x.c_str());
    }
    return 0;
}