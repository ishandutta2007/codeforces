#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 10010;
const int Q = 250200;
const long long mod = 1e9 + 7;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        //freopen("tracking2.in", "r", stdin);
        //freopen("tracking2.out", "w", stdout);
        ios_base::sync_with_stdio(0);

        int T;
        cin >> T;
        while(T--){
                long long n, k;
                cin >> n >> k;
                cout << (n - 1) * 9 + k << "\n";
        }
}