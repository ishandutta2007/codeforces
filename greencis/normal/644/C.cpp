#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n;
string s, s1, s2;
map<string, map<string, char> > mp;
map< map<string, char>, vector<string> > v;
vector<string> ans;

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n;
    while (n--) {
        cin >> s;
        int idx = 7;
        while (s[idx] && s[idx] != '/') ++idx;
        s1 = s.substr(7, idx - 7);
        s2 = s.substr(idx, s.size() - idx);
        mp[s1][s2] = 1;
    }
    for (map<string, map<string, char> >::iterator it = mp.begin(); it != mp.end(); ++it)
        v[it->second].push_back(it->first);
    mp.clear();
    for (map< map<string, char>, vector<string> >::iterator it = v.begin(); it != v.end(); ++it) {
        if (it->second.size() >= 2) {
            s = "";
            for (int i = 0; i < it->second.size(); ++i) {
                if (i > 0) s += " ";
                s += "http://" + it->second[i];
            }
            ans.push_back(s);
        }
    }

    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i] << "\n";

    return 0;
}