#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 500;
string s[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n, m;
        cin >> n >> m;
        for(int i = 0; i < n; i += 1) cin >> s[i];
        int b = m % 3 == 0;
        for(int i = 0; i < n; i += 1)
            for(int j = 0; j < m; j += 1)
                if((j - b) % 3 == 0) s[i][j] = 'X';
        for(int i = b; i + 3 < m; i += 3){
            int x = 0;
            for(int j = 0; j < n; j += 1) if(s[j][i + 1] == 'X' or s[j][i + 2] == 'X') x = j;
            s[x][i + 1] = s[x][i + 2] = 'X';
        }
        for(int i = 0; i < n; i += 1) cout << s[i] << "\n";
    }
    return 0;
}