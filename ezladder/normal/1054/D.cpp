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

int n, k;
int a[200007];
int b[200007];
map<int, int> was;

int main(){
    srand(time(NULL));
    //freopen("input.txt", "r", stdin);
    //freopen("output1.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    b[0] = a[0];
    for (int i = 1; i < n; i++){
        b[i] = b[i - 1] ^ a[i];
    }
    int now = (1 << k) - 1;
    for (int i = 0; i < n; i++){
        if ((b[i] ^ now) < b[i]) b[i] = b[i] ^ now;
        was[b[i]]++;
    }  
    was[0]++;
    ll ans = 0;
    for (auto c : was){
        ll val = c.y;
        ll k1 = val / 2;
        ll k2 = val - k1;
        ans += k1 * (k1 - 1) / 2;
        ans += k2 * (k2 - 1) / 2;
    }
    cout << n * (ll)(n + 1) / 2 - ans;
}