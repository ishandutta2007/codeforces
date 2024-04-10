#include <bits/stdc++.h>

using namespace std;
#define int long long

const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 7;

int len(int n){
    int res = 0;
    while (n){
        n /= 10;
        ++res;
    }
    return res;
}

string to_string_(int n){
    string res = "";
    while (n){
        res += '0' + (n % 10);
        n /= 10;
    }

    reverse(res.begin(), res.end());
    return res;
}

int stoi_(string s){
    int res = 0;
    for (int i = 0; i < s.size(); ++i){
        res = res * 10 + (s[i] - '0');
    }
    return res;
}

signed main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cout.precision(40);
    int k, p;
    cin >> k >> p;

    int ans = 0;
    for (int i = 1; i <= k; ++i){
        int add1 = i;
        for (int j = 0; j < len(i); ++j){
            add1 *= 10;
        }
        ans += add1;

        string s = to_string_(i);
        reverse(s.begin(), s.end());
        ans += stoi_(s);

        ans %= p;
    }

    cout << (ans + p) % p;
    return 0;
}