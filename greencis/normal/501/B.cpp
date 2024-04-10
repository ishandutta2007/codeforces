#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

int q;
string s1, s2;
map<string, string> mp;
map<string, int> u;
vector<string> v;
vector< pair<string,string> > ans;

int main()
{
    cin >> q;
    while (q--) {
        cin >> s1 >> s2;
        v.push_back(s2);
        mp[s2] = s1;
    }
    for (int i = v.size() - 1; i >= 0; --i) {
        if (u[v[i]]) continue;
        s1 = v[i];
        string cur = v[i];
        while (mp[cur] != "") {
            u[cur] = 1;
            cur = mp[cur];
        }
        if (s1 != cur)
            ans.push_back(make_pair(s1, cur));
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i) cout << ans[i].second << " " << ans[i].first << endl;

    return 0;
}