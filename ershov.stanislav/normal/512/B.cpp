#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ll lINF = 1e18;

void print(vector<int> v) {
    cerr << "(";
    for (int i = 0; i < (int) v.size(); i++) {
        cerr << v[i];
        if (i != (int) v.size() - 1) {
            cerr << ", ";
        }
    }
    cerr << ")" << endl;
}

int n, l[333];
ll c[333];

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a%b);
    }
}

map<int, ll> dp, dp2;

int main()
{
#ifdef DEBUG
freopen("in.txt", "r", stdin);
#endif

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &l[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
    }
    dp[l[0]] = c[0];
    dp[0] = 0;
    for (int i = 1; i < n; i++) {
        dp2.clear();
        dp2 = dp;
        for (auto j : dp) {
            //cout << j.fs << ' ' << j.sc << ',';
            if (dp2.count(gcd(j.fs, l[i]))) {
                dp2[gcd(j.fs, l[i])] = min(j.sc + c[i], dp2[gcd(j.fs, l[i])]);
            } else {
                dp2[gcd(j.fs, l[i])] = j.sc + c[i];
            }
        }
        //cout << endl;
        dp = dp2;
    }
    if (dp.count(1)) {
        cout << dp[1] << endl;
    } else {
        cout << -1;
    }
    return 0;
}