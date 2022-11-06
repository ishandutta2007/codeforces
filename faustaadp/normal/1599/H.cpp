#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 2e5 + 5;
const ll mo = 1e9 + 7;
const ld eps = 1e-9;
ll S = 1e9;
ll X1, Y1, X2, Y2;
ll tau;
ll tanya(ll X, ll Y)
{
    if(tau)
    {
        if(Y1 <= Y && Y <= Y2)
            return min(abs(X - X1), abs(X - X2));
        if(X1 <= X && X <= X2)
            return min(abs(Y - Y1), abs(Y - Y2));
        return min(abs(X - X1), abs(X - X2)) + min(abs(Y - Y1), abs(Y - Y2));
    }
    cout << "? " << X << " " << Y << endl;
    ll ret;
    cin >> ret;
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
    // tau = 1, X1 = 2003, Y1 = 18374, X2 = 2938912, Y2 = 836123;
    ll A = tanya(1, 1);
    ll B = tanya(S, 1);
    ll C = tanya(1, S);
    ll D = tanya(S, S);
    ll Yt = (A - B + S + 1) / 2; 
    // cout << Yt << "\n";
    ll Y1 = tanya(Yt, 1) + 1;
    ll X1 = A - Y1 + 2;
    ll X2 = S + Y1 - 1 - B;
    ll Y2 = S + S - X2 - D; 
    cout << "! " << X1 << " " << Y1 << " " << X2 << " " << Y2 << endl;
}