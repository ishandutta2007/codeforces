#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        int t;
        cin >> t;
        while(t--){
                int n;
                cin >> n;
                vector < char > a(n);
                vector < int > res(2, 0);
                for(int i = 0; i < n; i++){
                        cin >> a[i];
                        if(i > 0 && a[i] == a[i - 1]){
                                res[a[i] - '0'] += 1;
                        }
                }
                cout << max(res[0], res[1]) << "\n";
        }
}