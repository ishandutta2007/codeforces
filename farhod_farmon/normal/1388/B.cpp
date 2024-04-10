#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 300300;

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
                int X = n * 3 / 4, Y = n - X;
                for(int i = 0; i < X; i++) cout << "9";
                for(int i = 0; i < Y; i++) cout << "8";
                cout << "\n";
        }
}