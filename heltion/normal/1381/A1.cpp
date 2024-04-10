#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 100000;
char a[maxn + 1], b[maxn + 1];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    for(cin >> T; T; T -= 1){
        int n;
        cin >> n >> (a + 1) >> (b + 1);
        for(int i = 1; i <= n; i += 1){
            a[i] -= '0';
            b[i] -= '0';
        }
        vector<int> ans;
        int L = 1, R = n, t = 0;
        for(int i = n; i >= 1; i -= 1){
            if((a[R] ^ t) == b[i]){
                if(L < R) R -= 1;
                else R += 1;
                continue;
            }
            else{
                if((a[L] ^ t) == b[i]){
                    ans.push_back(1);
                    a[L] ^= 1;
                }
                ans.push_back(abs(L - R) + 1);
                if(L < R) L += 1;
                else L -= 1;
                swap(L, R);
                t ^= 1;
            }
        }
        cout << ans.size() << " ";
        for(int x : ans) cout << x << " ";
        cout << "\n";
    }
    return 0;
}