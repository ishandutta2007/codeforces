#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = -1;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int q;
    for(cin >> q; q ; q -= 1){
        LL n, k;
        string s;
        cin >> n >> k >> s;
        int z = 0, o = 0;
        for(; z < n; z += 1)
            if(s[z] == '0'){
                if(k < o) break;
                k -= o;
            }
            else o += 1;
        if(z == n){
            sort(s.begin(), s.end());
            cout << s << "\n";
        }
        else{
            for(int i = 0; i < z - o; i += 1) cout << 0;
            for(int i = 0; i < o - k; i += 1) cout << 1;
            cout << 0;
            for(int i = 0; i < k; i += 1) cout << 1;
            for(int i = z + 1; i < n; i += 1) cout << s[i];
            cout << "\n";
        }
    }
    return 0;
}