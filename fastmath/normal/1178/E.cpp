#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back

bool usl[3], usr[3];

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    string s;
    cin >> s;
    int n = s.size();

    if (n % 4 == 0) {
        int m = n / 2;
        string l = s.substr(0, m);
        reverse(l.begin(), l.end());
        string r = s.substr(m, m);
        string t;
        for (int i = 0; i + 1 < l.size() && i + 1 < r.size(); i += 2) {
            for (int j = 0; j < 3; ++j) {
                usl[j] = usr[j] = 0;
            }   
            for (int j = i; j <= i + 1; ++j) {
                usl[l[j] - 'a'] = 1;
                usr[r[j] - 'a'] = 1;
            }   
            for (int j = 0; j < 3; ++j) {
                if (usl[j] && usr[j]) {
                    t += (char)('a' + j);
                    break;
                }   
            }   
        }   
        string a = t;
        reverse(a.begin(), a.end());
        cout << a << t << '\n';
        exit(0);
    }   

    int m = (n + 1) / 2 - 1;

    string l = s.substr(0, m);
    reverse(l.begin(), l.end());
    string r = s.substr(m + 1, n - (m + 1));                 

    string t;
    for (int i = 0; i + 1 < l.size() && i + 1 < r.size(); i += 2) {
        for (int j = 0; j < 3; ++j) {
            usl[j] = usr[j] = 0;
        }   
        for (int j = i; j <= i + 1; ++j) {
            usl[l[j] - 'a'] = 1;
            usr[r[j] - 'a'] = 1;
        }   
        for (int j = 0; j < 3; ++j) {
            if (usl[j] && usr[j]) {
                t += (char)('a' + j);
                break;
            }   
        }   
    }   

    string a = t;
    reverse(a.begin(), a.end());
    cout << a << s[m] << t << '\n';
}