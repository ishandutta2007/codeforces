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

    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<int> l(n), r(n);
    for (int i = 0; i < n; i++){
        l[i] = 0;
        r[i] = m - 1;
        while (l[i] < m && a[i][l[i]] == '.') l[i]++;
        while (r[i] >= 0 && a[i][r[i]] == '.') r[i]--;
        for (int j = l[i]; j <= r[i]; j++){
            if (a[i][j] == '.'){
                cout << -1 << "\n";
                return 0;
            }
        }
    }
    vector<int> u(m), d(m);
    for (int j = 0; j < m; j++){
        u[j] = 0;
        d[j] = n - 1;
        while (u[j] < n && a[u[j]][j] == '.') u[j]++;
        while (d[j] >= 0 && a[d[j]][j] == '.') d[j]--;
        for (int i = u[j]; i <= d[j]; i++){
            if (a[i][j] == '.'){
                cout << -1 << "\n";
                return 0;
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (a[i][j] == 'X') cnt++;
        }
    }
    int ans = n * m + 1;
    /*
    int ml = m;
    for (int i = 0; i < n; i++){
        if (r[i] >= 0 && r[i] - l[i] + 1 < ml) ml = r[i] - l[i] + 1;
    }
    int md = n;
    for (int i = 0; i < m; i++){
        if (d[i] >= 0 && d[i] - u[i] + 1 < md) md = d[i] - u[i] + 1;
    }
    */
    int i = 0;
    while (l[i] == m) i++;
    int mm = 1;
    int j1 = l[i], j2 = r[i];
    int k = r[i] - l[i] + 1;
    bool flag = false;
    string s = "";
    while (i < n - 1){
        i++;
        if (r[i] == -1) break; else
        s += "D";
        if (l[i] > j1 || r[i] < j2){
            mm = 1000001;
            break;
        } else k += (j2 - j1 + 1);
        while (j2 < m - 1 && a[i][j2 + 1] == 'X'){
            if (!flag) mm = d[j1] - i + 1; else
            if (mm != d[j1] - i + 1){
                mm = 1000001;
                break;
            }
            flag = true;
            s += "R";
            j2++;
            j1++;
            k++;
        }
        if (mm > n * m) break;
    }
    if (mm <= n * m){
        for (i = 0; i < mm - 1; i++) s.erase(s.length() - 1);
        k = 0;
        i = 0;
        while (r[i] == -1) i++;
        int j = l[i];
        int y = r[i] - l[i] + 1;
        int x = mm;
        for (int ii = 0; ii < x; ii++){
            for (int jj = 0; jj < y; jj++){
                if (a[i + ii][j + jj] == '.'){
                    k = -1111111;
                    break;
                } else k++;
            }
        }
        for (int ij = 0; ij < s.length(); ij++){
            if (s[ij] == 'D'){
                for (int jj = 0; jj < y; jj++){
                    if (a[i + x][j + jj] == '.') k = -1111111; else
                    k++;
                }
                i++;
            } else {
                for (int ii = 0; ii < x; ii++){
                    if (a[i + ii][j + y] == '.') k = -1111111; else
                    k++;
                }
                j++;
            }
        }
        if (k == cnt) ans = min(ans, (j2 - j1 + 1) * mm);
    }
    
    i = 0;
    s = "";
    while (u[i] == n) i++;
    mm = 1;
    j1 = u[i], j2 = d[i];
    k = d[i] - u[i] + 1;
    flag = false;
    while (i < m - 1){
        i++;
        if (d[i] == -1) break; else
        s += "R";
        if (u[i] > j1 || d[i] < j2){
            mm = 1000001;
            break;
        } else k += (j2 - j1 + 1);
        while (j2 < n - 1 && a[j2 + 1][i] == 'X'){
            if (!flag) mm = r[j1] - i + 1; else
            if (mm != r[j1] - i + 1){
                mm = 1000001;
                break;
            }
            flag = true;
            s += "D";
            j2++;
            j1++;
            k++;
        }
        if (mm > n * m) break;
    }
    if (mm <= n * m){
        for (i = 0; i < mm - 1; i++) s.erase(s.length() - 1);
        k = 0;
        i = 0;
        while (d[i] == -1) i++;
        int j = u[i];
        int y = d[i] - u[i] + 1;
        int x = mm;
        swap(i, j);
        swap(x, y);
        for (int ii = 0; ii < x; ii++){
            for (int jj = 0; jj < y; jj++){
                if (a[i + ii][j + jj] == '.'){
                    k = -1111111;
                    break;
                } else k++;
            }
        }
        for (int ij = 0; ij < s.length(); ij++){
            if (s[ij] == 'D'){
                for (int jj = 0; jj < y; jj++){
                    if (a[i + x][j + jj] == '.') k = -1111111; else
                    k++;
                }
                i++;
            } else {
                for (int ii = 0; ii < x; ii++){
                    if (a[i + ii][j + y] == '.') k = -1111111; else
                    k++;
                }
                j++;
            }
        }
        if (k == cnt) ans = min(ans, (j2 - j1 + 1) * mm);
    }

    if (ans > n * m) cout << -1 << "\n"; else cout << ans << "\n";

    return 0;
}