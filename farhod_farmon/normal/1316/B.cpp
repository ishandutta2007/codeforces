#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")

#define fi first
#define se second

const int N = 100100;
const int Q = 400200;

using namespace std;


int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        int T;
        cin >> T;
        int n;
        string s, t;
        while(T--){
                cin >> n >> s;
                pair < string, int > best = {s, 1};
                for(int k = 1; k < n; k++){
                        t = "";
                        for(int i = k; i < n; i++) t += s[i];
                        if(k % 2 != n % 2) for(int i = k - 1; i >= 0; i--) t += s[i];
                        else for(int i = 0; i < k; i++) t += s[i];
                        best = min(best, make_pair(t, k + 1));
                }
                cout << best.fi << "\n";
                cout << best.se << "\n";
        }
}