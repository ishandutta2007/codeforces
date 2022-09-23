#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;

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
                vector < int > a(2 * n + 1);
                for(int i = 1; i <= 2 * n; i++){
                        cin >> a[i];
                }
                vector < int > d(n + 1, 0);
                d[0] = 1;
                for(int i = 1; i <= 2 * n; i++){
                        int x = 1;
                        while(i + x <= 2 * n && a[i] > a[i + x]){
                                x += 1;
                        }
                        i += x - 1;
                        for(int j = n - x; j >= 0; j--){
                                d[j + x] |= d[j];
                        }
                }
                cout << (d[n] ? "YES" : "NO") << "\n";
        }
}