#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    while (n--) {
        string s;
        if (s == "::") {
            cout << "0000:0000:0000:0000:0000:0000:0000:0000\n";
            continue;
        }
        cin >> s;
        vector<string> v;
        v.push_back("");
        for (int i = 0; s[i]; ++i) {
            if (s[i] == ':')
                v.push_back("");
            else
                v.back() += s[i];
        }
        if (v.size() >= 2 && v[0] == "" && v[1] == "")
            v.erase(v.begin());
        else if (v.size() >= 2 && v[v.size() - 2] == "" && v[v.size() - 1] == "")
            v.erase(v.begin() + v.size() - 1);
        for (int i = 0; i < v.size(); ++i) {
            if (v[i] == "") {
                int cnt = 8 - (v.size() - 1);
                v.erase(v.begin() + i);
                while (cnt--)
                    v.insert(v.begin() + i, "0000");
                break;
            }
        }
        for (int i = 0; i < v.size(); ++i) {
            while (v[i].size() < 4)
                v[i] = "0" + v[i];
            cout << (i ? ":" : "") << v[i];
        }
        cout << "\n";
    }

    return 0;
}