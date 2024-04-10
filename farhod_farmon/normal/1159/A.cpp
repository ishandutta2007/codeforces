#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 400400;
const int Q = 7070;

using namespace std;


int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

        int n;
        cin >> n;
        int res = 0;
        for(int i = 1; i <= n; i++){
                char c;
                cin >> c;
                res = max(0, res + (c == '+' ? 1 : -1));
        }
        cout << res << "\n";
}