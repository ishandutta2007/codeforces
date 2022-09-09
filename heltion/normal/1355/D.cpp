#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = -1;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N, S;
    cin >> N >> S;
    if(S < 2 * N) cout << "NO\n";
    else{
        cout << "YES\n";
        for(int i = 1; i < N; i += 1) cout << 2 << " ";
        cout << S - (N - 1) * 2 << "\n";
        cout << 1;
    }
    return 0;
}