#include <bits/stdc++.h>
                  
using namespace std;
          
typedef long long ll;
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db long double

ll gcd(ll a, ll b){
    while(b){
        a %= b;
        swap(a, b);
    }
    return a;
}

ll solve(ll l1, ll r1, ll t1, ll l2, ll r2, ll t2){
    ll val = (l1 - l2) % t1;
    if (val < 0) val += t1;
    ll cc = gcd(t1, t2);
    val -= (val / cc) * cc;
    ll w1 = 0, w2 = r2 - l2 + 1;
    ll s1 = val, s2 = val + r1 - l1 + 1;
    return max((ll)0, min(s2, w2) - max(s1, w1)); 
}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output1.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll l1, r1, t1;
    ll l2, r2, t2;
    cin >> l1 >> r1 >> t1 >> l2 >> r2 >> t2;
    ll ans = max(solve(l1, r1, t1, l2, r2, t2), solve(l2, r2, t2, l1, r1, t1));
    cout << ans;
}