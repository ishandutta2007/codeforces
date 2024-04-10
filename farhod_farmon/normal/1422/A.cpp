#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 500500;

using namespace std;


int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int t;
        cin >> t;
        while(t--){
                int a, b, c;
                cin >> a >> b >> c;
                cout << max(max(a, b), c) << "\n";
        }
}