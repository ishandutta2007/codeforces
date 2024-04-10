#include<bits/stdc++.h>
using namespace std;
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcount
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC
const int N = 1e6 + 7;
int r[N];
string s;
int solve(int sh) {
    int i = 0, l = 0, ans = 0;
    while (i < s.size()) {
        if (ans > 100000)
            return N;

        if (i - l + 1 > sh) {
            if (r[i] == -1 || r[i] - l + 1 > sh)
                return N;
            ++ans;
            l = i = r[i] + 1;
        }   
        else {
            i = max(i + 1, sh + l);
        }   
    }   
    return ans + 1;
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    string t; getline(cin, t);
    int k = stoi(t);
    getline(cin, s);

    r[0] = -1;
    for (int i = 1; i < s.size(); ++i) {
        if (s[i - 1] == '-' || s[i - 1] == ' ')
            r[i] = i - 1;
        else
            r[i] = r[i - 1];
    }   

    {
    int l = 0, r = s.size();
    while (l < r - 1) {
        int m = (l + r) >> 1;
        if (solve(m) <= k)
            r = m;
        else
            l = m;
    }
    cout << r << endl;
    }
}