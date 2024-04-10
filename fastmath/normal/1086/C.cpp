#include <bits/stdc++.h>

using namespace std;

#define int long long

const int C = 26;

char pt[C];

void print(char pt[], int k) {
    set <char> ms;
    for (int i = 0; i < k; ++i) {
        ms.insert('a' + i);
    }
    for (int i = 0; i < k; ++i) {
        if (pt[i] != -1) {
            ms.erase(pt[i]);
        }   
    }   
    for (int i = 0; i < k; ++i) {
        if (pt[i] == -1) {
            pt[i] = *ms.begin();
            ms.erase(ms.begin());
        }   
    }   
    cout << "YES\n";
    for (int i = 0; i < k; ++i) {
        cout << pt[i];
    }   
    cout << '\n';
}

bool can(char pt[], char c1, char c2) {
    if (pt[c1 - 'a'] == c2) {
        return 1;
    }   
    else if (pt[c1 - 'a'] != -1) {
        return 0;
    }   
    else {
        for (int i = 0; i < C; ++i) {
            if (pt[i] == c2) {
                return 0;
            }   
        }   
        return 1;
    }   
}   

char np[C];

bool solveb(string s, string b, int k) {
    for (int i = 0; i < C; ++i) {
        np[i] = pt[i];
    }   

    int n = s.size();
    for (int i = 0; i < n; ++i) {
        if (np[s[i] - 'a'] != -1) {
            if (np[s[i] - 'a'] < b[i]) {
                print(np, k);
                return 1;
            }   
            else if (np[s[i] - 'a'] > b[i]) {
                return 0;
            }   
        }   
        else {
            for (char c = 'a'; c < b[i]; ++c) {
                if (can(np, s[i], c)) {
                    np[s[i] - 'a'] = c;
                    print(np, k);
                    return 1;
                }   
            }   
            if (can(np, s[i], b[i])) {
                np[s[i] - 'a'] = b[i];
            }   
            else {
                return 0;
            }   
        }   
    }   
    
    print(np, k);
    return 1;
}   

bool solvea(string s, string a, int k) {
    for (int i = 0; i < C; ++i) {
        np[i] = pt[i];
    }       

    int n = s.size();
    for (int i = 0; i < n; ++i) {
        if (np[s[i] - 'a'] != -1) {
            if (np[s[i] - 'a'] > a[i]) {
                print(np, k);
                return 1;
            }   
            else if (np[s[i] - 'a'] < a[i]) {
                return 0;
            }   
        }   
        else {
            for (int c = a[i] + 1; c < 'a' + k; ++c) {
                if (can(np, s[i], c)) {
                    np[s[i] - 'a'] = c;
                    print(np, k);
                    return 1;
                }   
            }   
            if (can(np, s[i], a[i])) {
                np[s[i] - 'a'] = a[i];
            }   
            else {
                return 0;
            }   
        }   
    }   

    print(np, k);
    return 1;
}   

void solve() {
    for (int i = 0; i < C; ++i) {
        pt[i] = -1;
    }   

    int k;
    cin >> k;

    string s, a, b;
    cin >> s >> a >> b;

    if (b < a) {
        cout << "NO\n";
        return;
    }   

    int n = s.size();

    int u = -1;
    while (u + 1 < n && a[u + 1] == b[u + 1]) {
        ++u;
    }

    for (int i = 0; i <= u; ++i) {
        if (!can(pt, s[i], a[i])) {
            cout << "NO\n";
            return;
        }
        pt[s[i] - 'a'] = a[i];
    }   

    if (u == n - 1) {
        print(pt, k);
        return;
    }   
    for (int c = a[u + 1] + 1; c < b[u + 1]; ++c) {
        if (can(pt, s[u + 1], c)) {
            pt[s[u + 1] - 'a'] = c;
            print(pt, k);
            return;
        }   
    }   
    if (can(pt, s[u + 1], a[u + 1])) {
        int w = pt[s[u + 1] - 'a'];
        pt[s[u + 1] - 'a'] = a[u + 1];
        if (solvea(s, a, k)) {
            return;
        }   
        else {
            pt[s[u + 1] - 'a'] = w;
        }   
    }   
    if (can(pt, s[u + 1], b[u + 1])) {
        int w = pt[s[u + 1] - 'a'];
        pt[s[u + 1] - 'a'] = b[u + 1];
        if (solveb(s, b, k)) {
            return;
        }   
        else {
            pt[s[u + 1] - 'a'] = w;
        }   
    }   
    cout << "NO\n";
}   

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    #ifdef HOME
        //freopen("input.txt", "r", stdin);
    #else   
        
    #endif

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }   

    return 0;
}