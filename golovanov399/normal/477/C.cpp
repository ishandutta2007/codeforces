#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second

using namespace std;

int main(){

    string s, p;
    cin >> s >> p;
    int n = s.length();
    int m = p.length();
    vector<int> last(n);
    for (int i = 0; i < n; i++){
        int ij = 0;
        int j = i;
        while (j < n && ij < m){
            if (s[j] == p[ij]) ij++;
            j++;
        }
        if (ij == m) last[i] = j - 1; else last[i] = -1;
    }
    /*
    for (int i = 0; i < n; i++) cerr << last[i] << " ";
    cerr << "\n";
    */
    vector<vector<int> > a(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++) a[n][i] = 2222;
    for (int i = 0; i < n; i++){
        a[n - 1 - i][0] = 0;
        int cur = last[n - 1 - i];
        for (int j = 1; j <= i + 1; j++){
            if (j < i + 1){
                if (cur > -1){
                    a[n - 1 - i][j] = min(a[n - i][j], a[cur + 1][j - 1] + cur - (n - 1 - i) + 1 - m);
                } else {
                    a[n - 1 - i][j] = a[n - i][j];
                }
            } else {
                if (cur > -1){
                    a[n - 1 - i][j] = a[cur + 1][j - 1] + cur - (n - 1 - i) + 1 - m;
                } else {
                    a[n - 1 - i][j] = 2222;
                }
            }
        }
        for (int j = i + 2; j <= n; j++) a[n - 1 - i][j] = 2222;
    }
    vector<int> ans(n + 1);
    int j = 0;
    for (int i = 0; i <= n; i++){
        while (a[0][j + 1] <= i) j++;
        ans[i] = j;
    }
    for (int i = 0; i <= n; i++){
        ans[i] = min(ans[i], (n - i) / m);
    }
    for (int i = 0; i <= n; i++) cout << ans[i] << " ";
    cout << "\n";

    return 0;
}