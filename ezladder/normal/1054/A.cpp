#include <bits/stdc++.h>
//#pragma comment(linker, /STACK:36777216)
           
using namespace std;
           
typedef long long ll;
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db long double


int main(){
    srand(time(NULL));
    //freopen("input.txt", "r", stdin);
    //freopen("output1.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll x, y, z, t1, t2, t3;
    cin >> x >> y >> z >> t1 >> t2 >> t3;
    ll f1 = abs(x - y) * t1;
    ll f2 = (abs(x - z) + abs(x - y)) * t2 + t3 + t3 + t3;
    if (f2 <= f1) cout << "YES"; else cout << "NO";
}