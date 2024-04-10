#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 200;
char s[maxn][maxn + 1];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;
    cin >> s;
    int n = s.size();
    cout << "4\n";
    cout << "R 2\n";
    cout << "R " << 2 * n - 3 << "\n";
    cout << "L " << 2 * n - 2 << "\n";
    cout << "L 2\n";
    return 0;
}