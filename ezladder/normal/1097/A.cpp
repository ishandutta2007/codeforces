#include <bits/stdc++.h>
using namespace std;
           
#define ll longl long
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db long double



int main(){
   // freopen("input.txt", "r", stdin);
    //freopen("output1.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s;
    cin >> s;
    bool ans = 0;
    for (int i = 0; i < 5; i++){
        string t;
        cin >> t;
        if (t[0] == s[0] || s[1] == t[1]) ans = 1;
    }
    if (ans) cout << "YES"; else cout << "NO";
}