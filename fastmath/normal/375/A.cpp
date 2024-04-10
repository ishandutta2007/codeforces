#include<bits/stdc++.h>
using namespace std;
#define int long long
bool used[10];
set <int> in = {1, 6, 8, 9};
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    string s;
    cin >> s;
    vector <int> t;
    for (char c : s) {
        if (in.find(c - '0') != in.end() && !used[c - '0']) {
            used[c - '0'] = 1;
        }   
        else {
            t.push_back(c - '0');
        }
    }   

    int cnt = 0;
    for (int e : t) cnt += e == 0;

    if (cnt == t.size()) {
        cout << "1869";
        for (int i = 0; i < cnt; ++i) cout << '0';
        cout << '\n';
        exit(0);
    }   

    for (int i = 0; ; ++i) {
        if (t[i]) {
            swap(t[0], t[i]);
            break;
        }   
    }   

    int m = 0;
    for (int e : t) {
        m = (m * 10 + e) % 7;
    }   

    vector <int> a = {1, 6, 8, 9};
    do {
        int add = 0;
        for (int e : a) {
            add = (add * 10 + e) % 7;
        }   
        if ((m * 10000 + add) % 7 == 0) {
            for (int e : t) cout << e;
            for (int e : a) cout << e;
            cout << '\n';
            exit(0);
        }   
    } while (next_permutation(a.begin(), a.end()));
}