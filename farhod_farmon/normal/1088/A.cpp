#include <bits/stdc++.h>

#define fi first
#define se second
#define ll long long

const int N = 100100;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int n;
        cin >> n;
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                        if(j % i == 0 && j / i < n && j * i > n){
                                cout << j << " " << i << "\n";
                                return 0;
                        }
                }
        }
        cout << -1 << "\n";
}