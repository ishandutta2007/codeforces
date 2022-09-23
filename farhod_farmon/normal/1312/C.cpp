#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")

#define fi first
#define se second

const int N = 30300;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        int t;
        cin >> t;
        while(t--){
                int n, k;
                cin >> n >> k;
                vector < int > v(100, 0);
                vector < long long > g;
                long long inf = 1e16;
                g.push_back(1);
                while(g.back() <= inf) g.push_back(g.back() * k);

                bool bad = false;
                for(int i = 1; i <= n; i++){
                        long long x;
                        cin >> x;
                        for(int j = g.size() - 1; j >= 0; j--){
                                if(x >= g[j]){
                                        x -= g[j];
                                        v[j] += 1;
                                }
                        }
                        if(x > 0) bad = true;
                }
                for(int x: v) if(x > 1) bad = true;

                cout << (bad ? "NO" : "YES") << "\n";
        }
}