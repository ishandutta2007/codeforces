#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<li, li>;

const int INF = 1e9 + 14;
const int M = 998244353;
const int N = 2e5 + 13;

/*
1
AN
*/

void solve() {
    string s;
    cin >> s;

    int n = s.size();

    vector<int> a(n);
    vector<int> cnt(4, 0);
    map<char, int> mp;
    mp['A'] = 0;
    mp['N'] = 1;
    mp['O'] = 2;
    mp['T'] = 3;
    for(int i = 0; i < n; i++) {
        cnt[mp[s[i]]]++;
        a[i] = mp[s[i]];
    }

//    for(auto x : a)
//        cout << x << ' ';
//    cout << endl;
//    for(auto x : cnt)
//        cout << x << ' ';
//    cout << endl;
    vector<int> p = {0, 1, 2, 3};
    li res = 0;
    vector<int> ans = p;
    do {
        vector<int> c(4);
        for(int i = 0; i < 4; i++)
            c[i] = cnt[p[i]];

        li r = 0;
        for(int i = 0; i < n; i++) {
//            for(auto x : c)
//                cout << x << ' ';
//            cout << endl;
            for(int j = 0; j < 4; j++)
                if(p[j] == a[i]) {
                    c[j]--;
                    break;
                } else {
                    r += c[j];
                }
        }

//        cout << r << endl;
//        for(auto x : p)
//            cout << x << ' ';
//        cout << endl;

        if(res < r) {
            res = r;
            ans = p;
        }
//        break;
    } while(next_permutation(p.begin(), p.end()));

//    for(auto x : ans)
//        cout << x << ' ';
//    cout << endl;

    vector<char> alf = {'A', 'N', 'O', 'T'};
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < cnt[ans[i]]; j++)
            cout << alf[ans[i]];
    }

    cout << endl;
}



int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();



}