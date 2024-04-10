#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    string t = "abc";
    vector<vector<int>> sum;
    do{
        sum.push_back(vector<int>(n));
        for (int i = 0; i < n; i += 1) {
            sum.back()[i] = s[i] != t[i % 3];
            if (i) sum.back()[i] += sum.back()[i - 1];
        }
    }while(next_permutation(t.begin(), t.end()));
    for (int i = 0; i < m; i += 1) {
        int l, r, ans = n;
        cin >> l >> r;
        for (int j = 0; j < 6; j += 1) {
            int pans = sum[j][r - 1];
            if (l >= 2) pans -= sum[j][l - 2];
            ans = min(ans, pans);
        }
        cout << ans << "\n";
    }
    return 0;
}