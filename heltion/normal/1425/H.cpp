#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 1000 + 1;
int P[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    for(cin >> T; T; T -= 1){
        int A, B, C, D;
        cin >> A >> B >> C >> D;
        int ans[4] = {1, 1, 1, 1};
        if((A + B) & 1) ans[2] = ans[3] = 0;
        else ans[0] = ans[1] = 0;
        if(not A and not D) ans[0] = ans[3] = 0;
        if(not B and not C) ans[1] = ans[2] = 0;
        for(int i = 0; i < 4; i += 1)
            cout << (ans[i] ? "Ya" : "Tidak") << " ";
        cout << "\n";
    }
    return 0;
}