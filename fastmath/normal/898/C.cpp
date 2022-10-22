#include <bits/stdc++.h>

using namespace std;
#define int long long

const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 7;

bool is_post(string t, string s){
    if (t.size() >= s.size()) return false;
    return (s.substr(s.size() - t.size(), t.size()) == t);
}

signed main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cout.precision(40);
    int n;
    cin >> n;
    map <string, set <string> > ms;
    set <string> names;
    for (int i = 0; i < n; ++i){
        string name;
        cin >> name;
        names.insert(name);
        int k;
        cin >> k;
        for (int j = 0; j < k; ++j){
            string num;
            cin >> num;
            ms[name].insert(num);
        }
    }

    map <string, vector <pair <string, bool> > > ms1;
    for (string name: names){
        for (string num: ms[name]){
            ms1[name].push_back({num, true});
        }
    }

    for (string name: names){
        int len = ms1[name].size();
        for (int i = 0; i < len; ++i){
            for (int j = 0; j < len; ++j){
                string t = ms1[name][i].first;
                string s = ms1[name][j].first;
                if (is_post(t, s)){
                    ms1[name][i].second = false;
                }
            }
        }
    }

    map <string, set <string> > ans;
    for (string name: names){
        for (pair <string, bool> num: ms1[name]){
            if (num.second){
                ans[name].insert(num.first);
            }
        }
    }

    cout << names.size() << '\n';
    for (string name: names){
        cout << name << ' ' << ans[name].size() << ' ';
        for (string num: ans[name]){
            cout << num << ' ';
        }
        cout << '\n';
    }

    return 0;
}