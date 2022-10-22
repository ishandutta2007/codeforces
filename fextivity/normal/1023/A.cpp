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
    string s, t;
    cin >> s >> t;
    if (n > m + 1){
        cout << "NO";
        return 0;
    }
    int ck = 0, idx = -1;
    for (int i = 0; i < n; i++){
        if (s[i] == '*'){
            ck = 1;
            idx = i;
            break;
        }
    }
    if (!ck){
        if (s == t){
            cout << "YES";
        }
        else{
            cout << "NO";
        }
        return 0;
    }
    int l = 0, r = m - 1;
    while (s[l] == t[l]){
        l++;
    }
    while (s[r - m + n] == t[r]){
        r--;
    }
    if (l <= r - m + n && l == idx && r - m + n == idx){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
}