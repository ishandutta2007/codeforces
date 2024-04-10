#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcount
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC

string s = "ACB";
bool check(int l, int r, int k, int n) {
    if (n == 2 && l == 0 && r == 1 && k == 0)
        return 0;
    if (n == 1 && l != r)
        return 0;
    if ((n - (l != 0) - (r != 1)) / 2 < k)
        return 0;
    return 1;
}   
string gen(int l, int r, int k, int n) {
    string ans;
    ans += s[l];
    for (int i = 0; i < k; ++i) {
        if (ans.back() == 'A')
            ans += 'C';
        else
            ans += "AC";
    }   
    if (ans.size() == n) {        
        return ans;
    }   
    else {
        while (ans.size() + 1 < n)
            ans += 'Z';
        ans += s[r];
        return ans;
    }   
}   

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            for (int k = 0; k < 10; ++k) {
                for (int t = 0; t < 10; ++t) {
                    if (check(i, j, k, t))
                        gen(i, j, k, t);
                }   
            }   
        }   
    }   

    int k, x, n, m;
    cin >> k >> x >> n >> m;
    for (int l1 = 0; l1 < 3; ++l1) {
        for (int r1 = 0; r1 < 3; ++r1) {
            for (int l2 = 0; l2 < 3; ++l2) {
                for (int r2 = 0; r2 < 3; ++r2) {
                    for (int i = 0; i <= n; ++i) {
                        for (int j = 0; j <= m; ++j) {

                            if (check(l1, r1, i, n) && check(l2, r2, j, m)) {
                                vector <string> a;
                                vector <int> cnt = {i, j};

                                string t;
                                t += s[l1];
                                t += s[r1];
                                a.app(t);
                                t = "";
                                t += s[l2];
                                t += s[r2];
                                a.app(t); 
                                for (int t = 3; t <= k; ++t) {
                                    cnt.app(cnt[cnt.size() - 2] + cnt.back() + (a[a.size() - 2].back() == 'A' && a.back()[0] == 'C'));
                                    string lmao;
                                    lmao += a[a.size() - 2][0];
                                    lmao += a.back().back();
                                    a.app(lmao);
                                }   

                                if (cnt.back() == x) {
                                    cout << gen(l1, r1, i, n) << '\n';
                                    cout << gen(l2, r2, j, m) << '\n';
                                    exit(0);
                                }   
                            }

                        }   
                    }   
                }   
            }   
        }   
    }   
    cout << "Happy new year!\n";
}