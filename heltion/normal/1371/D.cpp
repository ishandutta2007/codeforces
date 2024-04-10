#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 300;
int A[maxn][maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t, n, k;
    for(cin >> t; t; t -= 1){
        cin >> n >> k;
        cout << not not(k % n) * 2 << "\n";
        for(int i = 0; i < n; i += 1)
            for(int j = 0; j < n; j += 1)
                A[i][j] = 0;
        for(int i = 0; i < n; i += 1)
            for(int j = 0; j < n; j += 1)
                if(k){
                    A[j][(i + j) % n] = 1;
                    k -= 1;
                }
        for(int i = 0; i < n; i += 1){
            for(int j = 0; j < n; j += 1)
                cout << A[i][j];
            cout << "\n";
        }
    }
    return 0;
}