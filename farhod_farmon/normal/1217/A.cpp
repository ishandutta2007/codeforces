#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int T;
        cin >> T;
        while(T--){
                int a, b, c;
                cin >> a >> b >> c;
                b = b + c - a;
                int l = 0;
                if(b >= 0){
                        l = b / 2 + 1;
                }
                cout << max(0, c - l + 1) << "\n";
        }
}