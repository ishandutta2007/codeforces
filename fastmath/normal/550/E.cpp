#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 7;

bool a[MAXN];

signed main() {
    #ifdef HOME
        freopen("input.txt", "r", stdin);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];

    int cnt = 0;
    for (int i = 0; i < n; ++i) cnt += (a[i] == 0);

    if (a[n - 1]) {
        cout << "NO\n";
        exit(0);
    }   

    if (cnt > 2) {
        vector <string> v;
        string curr = "";
        for (int i = 0; i < n; ++i) {
            if (a[i] == 0) {
                curr += '0';
                v.push_back('(' + curr + ')');
                curr = "";
            }
            else {
                curr += "1->";
            }   
        }
        cout << "YES\n";  
        for (int i = 0; i < (int)v.size() - 3; ++i) {
            cout << v[i] << "->";
        }   
        cout << '(' << v[(int)v.size() - 3] << "->" << v[(int)v.size() - 2] << ')' << "->";
        cout << v.back() << '\n';
        exit(0);
    }
    else if (cnt == 1) {
        cout << "YES\n";  
        for (int i = 0; i < n - 1; ++i) cout << a[i] << "->";
        cout << a[n - 1] << '\n';
        exit(0);
    }
    else if (a[n - 2] == 0 && a[n - 1] == 0) {
        cout << "NO\n";
        exit(0);
    }
    else {
        cout << "YES\n";  
        for (int i = 0; i < n - 1; ++i) cout << a[i] << "->";
        cout << a[n - 1] << '\n';
        exit(0);
    }   

    return 0;
}