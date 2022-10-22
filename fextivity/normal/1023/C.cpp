#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define pb push_back
#define pob pop_back
#define mp make_pair
#define fi first
#define se second
typedef vector <int> vi;
typedef pair <int, int> ii;
typedef vector <ii > vii;

const int mod = 1e9 + 7, inf = 1e18 + 5, N = 1e5 + 5;

signed main(){
    int n, m;
    cin >> n >> m;
    string s;
    vector <char> a;
    cin >> s;
    int cnt = 0, i = 0;
    while (cnt < m / 2){
        a.pb(s[i]);
        if (s[i] == '('){
            cnt++;
        }
        i++;
    }
    for (int i = 0; i < a.size(); i++){
        cout << a[i];
    }
    for (int i = 0; i < m - a.size(); i++){
        cout << ')';
    }
    return 0;
}