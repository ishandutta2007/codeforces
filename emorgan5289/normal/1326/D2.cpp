#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ull 1000000000000000000
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()

#ifdef ONLINE_JUDGE
#pragma GCC optimize ("O3")
#define debug(...)
#define fin cin
#else
#include "../../debug.cpp"
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
ifstream fin("../../input.in");
#define cin fin
#endif

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; fin >> t;
    while (t--) {
        string s; fin >> s;
        int n = s.size();

        // https://cp-algorithms.com/string/manacher.html
        vector<int> d1(n);
        for (int i = 0, l = 0, r = -1; i < n; i++) {
            int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
            while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
                k++;
            }
            d1[i] = k--;
            if (i + k > r) {
                l = i - k;
                r = i + k;
            }
        }
        vector<int> d2(n);
        for (int i = 0, l = 0, r = -1; i < n; i++) {
            int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
            while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
                k++;
            }
            d2[i] = k--;
            if (i + k > r) {
                l = i - k - 1;
                r = i + k ;
            }
        }

        int l = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == s[n-i-1]) l++;
            else break;
        }

        int best = 0, x = 1, y = n;
        for (int i = 0; i < n; i++) {
            int a = i-d1[i]+1, b = i+d1[i]-1;
            if (a < n-1-b) {
                if (a <= l) {
                    int len = b-a+1 + 2*a;
                    if (len > best) {
                        best = len;
                        x = b; y = n-a;
                        // debug(a, b);
                    }
                }
            } else {
                if (n-1-b <= l) {
                    int len = b-a+1 + 2*(n-1-b);
                    if (len > best) {
                        best = len;
                        x = n-2-b; y = a;
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            int a = i-d2[i], b = i+d2[i]-1;
            if (a < n-1-b) {
                if (a <= l) {
                    int len = b-a+1 + 2*a;
                    if (len > best) {
                        best = len;
                        x = b; y = n-a;
                    }
                }
            } else {
                if (n-1-b <= l) {
                    int len = b-a+1 + 2*(n-1-b);
                    if (len > best) {
                        best = len;
                        x = n-2-b; y = a;
                    }
                }
            }
        }
        // debug(s);
        // debug(best, x, y);
        cout << s.substr(0, x+1) << s.substr(y, s.size()) << "\n";
    }
}