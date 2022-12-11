#include <bits/stdc++.h>
using namespace std;
           
#define ll longl long
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db long double

int n;
int a[22];

int main(){
   // freopen("input.txt", "r", stdin);
    //freopen("output1.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int mask = 0; mask < (1 << n); mask++){
        int pos = 0;
        for (int i = 0; i < n; i++) if ((mask >> i) & 1) pos += a[i];
            else pos -= a[i];
        if (abs(pos) % 360 == 0) cout << "YES", exit(0);
    }
    cout << "NO";
}