#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    for(cin >> T; T; T -= 1){
        int n, c = 0;
        cin >> n;
        string s;
        cin >> s;
        for(char a : s) c += a - '0';
        if(c & 1){
            cout << "NO\n";
            continue;
        }
        string a(n, '0'), b(n, '0');
        for(int i = 0, j = 0; i < n; i += 1) if(s[i] == '1'){
            j += 1;
            if(j <= c / 2) a[i] = b[i] = '(';
            else a[i] = b[i] = ')';
        }
        for(int i = 0, j = 0; i < n; i += 1) if(s[i] == '0'){
            j += 1;
            if(j & 1) a[i] = '(', b[i] = ')';
            else a[i] = ')', b[i] = '(';
        }
        int ok = 1;
        for(int i = 0, sa = 0, sb = 0; i < n; i += 1){
            if(a[i] == '(') sa += 1; else sa -= 1;
            if(b[i] == '(') sb += 1; else sb -= 1;
            if(sa < 0 or sb < 0) ok = 0;
        }
        if(ok) cout << "YES\n" << a << "\n" << b << "\n";
        else cout << "NO\n";
    }
    return 0;
}