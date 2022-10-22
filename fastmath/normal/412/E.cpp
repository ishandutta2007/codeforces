#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC
#define debug(x) std::cout << #x << ": " << x << '\n';

bool letter(char c) {
    return 'a' <= c && c <= 'z';
}
bool dig(char c) { return '0' <= c && c <= '9'; }
bool left(char c) {
    return letter(c) || dig(c) || c == '_';
}   

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(20); 
    #endif

    string s;
    cin >> s;

    int n = s.size();

    vector <int> dot;
    for (int i = 0; i < n; ++i)
        if (s[i] == '.')
            dot.app(i);

    vector <int> bad(n + 1);
    for (int i = 0; i < n; ++i)
        bad[i + 1] = bad[i] + (!letter(s[i]) && !dig(s[i]));

    vector <int> le(n);
    for (int i = n - 2; i >= 0; --i) {
        if (letter(s[i + 1]))
            le[i] = le[i + 1] + 1;
        else
            le[i] = 0;
    }   

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '@') {
            int l = 0;
            for (int j = i - 1; j >= 0; --j) {
                if (!left(s[j])) {
                    break;
                }   
                l += letter(s[j]);
            }   

            auto t = lower_bound(all(dot), i);
            if (t == dot.end()) {
                continue;
            }

            int p = *t;
            if (p > i + 1 && bad[p] - bad[i + 1] == 0) {
                ans += l * le[p];                                    
            }   
        }
    }   
    cout << ans << endl;
}