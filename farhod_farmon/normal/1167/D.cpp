#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 500500;
const int Q = 1 << 21;
const long long mod = 1e9 + 7;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        //freopen("sum.in", "r", stdin);
        //freopen("sum.out", "w", stdout);
        ios_base::sync_with_stdio(0);

        int n;
        string s;
        cin >> n >> s;
        int gg = 0;
        for(int i = 0; i < n; i++){
                cout << (gg ^ (s[i] == '('));
                gg ^= 1;
        }
}