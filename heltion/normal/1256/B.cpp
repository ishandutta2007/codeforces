#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 120;
int p[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int q;
    for(cin >> q; q; q -= 1){
        int n;
        cin >> n;
        for(int i = 1; i <= n; i += 1) cin >> p[i];
        for(int s = 1, t = 1; s < n; s = t){
            for(int j = s; j <= n; j += 1) if(p[j] <= p[t]) t = j;
            int tmp = p[t];
            for(int j = t; j > s; j -= 1) p[j] = p[j - 1];
            p[s] = tmp;
            if(s == t) t += 1;
        }
        for(int i = 1; i <= n; i += 1) cout << p[i] << " ";
        cout << "\n";
    }
    return 0;
}