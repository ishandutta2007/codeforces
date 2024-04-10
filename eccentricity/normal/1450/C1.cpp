#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 302;
int x[maxn], y[maxn];
char s[maxn][maxn];
int cnt[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n;
        cin >> n;
        for(int i = 0; i < n; i += 1) cin >> s[i];
        for(int k = 0; k < 3; k += 1) cnt[k] = 0;
        for(int i = 0; i < n; i += 1)
            for(int j = 0; j < n; j += 1)
                if(s[i][j] == 'X')
                    cnt[(i + j) % 3] += 1;
        int k = min_element(cnt, cnt + 3) - cnt;
        for(int i = 0; i < n; i += 1)
            for(int j = 0; j < n; j += 1)
                if(s[i][j] == 'X')
                    if((i + j) % 3 == k) s[i][j] = 'O';
        for(int i = 0; i < n; i += 1) cout << s[i] << "\n";
    }
    return 0;
}