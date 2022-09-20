#include "bits/stdc++.h"

#define fi first
#define se second

const int N = 100100;

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        if(2 * k - 1 > n){
            cout << -1 << "\n";
            continue;
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                cout << (i == j && i % 2 == 1 && i <= 2 * k - 1 ? 'R' : '.');
            }
            cout << "\n";
        }
    }
}