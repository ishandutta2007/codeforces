#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const int Q = N * 50;

using namespace std;

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int t;
        cin >> t;
        while(t--){
                int n;
                cin >> n;
                int s = 0;
                map < int, int > d;
                long long res = 0;
                for(int i = 1; i <= n; i++){
                        d[s - (i - 1)]++;
                        char c;
                        cin >> c;
                        s += c - '0';
                        res += d[s - i];
                }
                cout << res << "\n";
        }
}