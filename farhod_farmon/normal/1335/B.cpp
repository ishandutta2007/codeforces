#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 1010;

using namespace std;

int main()
{
        ios_base::sync_with_stdio(false);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int T;
        cin >> T;
        while(T--){
                int n, a, b;
                cin >> n >> a >> b;
                for(int i = 0; i < n; i++){
                        cout << char('a' + i % b);
                }
                cout << "\n";
        }
}