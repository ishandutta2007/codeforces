#include <bits/stdc++.h>

#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back

#define all(s) (s).begin(), (s).end()
#define sz(s) ((int) ((s).size()))

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-12;

#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

const int MOD = 1e9 + 7;
const int N = 1e5 + 100;

int n, t;
char s1[N], s2[N];

int main()
{
#ifdef DEBUG
    freopen("text.in", "r", stdin);
#endif
    cin >> n >> t;
    scanf(" %s %s", s1, s2);
    int change = 0;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        if (s1[i] != s2[i]) {
            change++;
            v.pb(i);
        }
    }
    t -= change / 2;
    if (t - change % 2 < 0) {
        cout << -1 << endl;
    } else {
        bool flag = false;
        if (change % 2 == 1) {
            flag = true;
            change--;
            t--;
        }
        for (int i = 0; i < n; i++) {
            if (t && s1[i] == s2[i]) {
                char c = 'a';
                for (; c == s1[i] || c == s2[i]; c++);
                s1[i] = c;
                t--;
            }
        }
        for (int i = 0; i < change; i += 2) {
            if (t) {
                t--;
                char c = 'a';
                for (; c == s1[v[i]] || c == s2[v[i]]; c++);
                s1[v[i]] = c;
                c = 'a';
                for (; c == s1[v[i + 1]] || c == s2[v[i + 1]]; c++);
                s1[v[i + 1]] = c;
            } else {
                s1[v[i]] = s2[v[i]];
            }
        }
        if (flag) {
            int i = change;
            char c = 'a';
            for (; c == s1[v[i]] || c == s2[v[i]]; c++);
            s1[v[i]] = c;
        }
        if (t) {
            cout << -1 << endl;
        } else {
            printf("%s\n", s1);
        }
    }
    return 0;
}