#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 5e5 + 5;
const ll mo = 998244353;
ll tes = 0;
ll n, m, X1, Y1, X2, Y2;
ll tanya(ll X, ll Y)
{
    cout << "SCAN " << X << " " << Y << endl;
    if(tes)
    {
        return abs(X - X1) + abs(X - X2) + abs(Y - Y1) + abs(Y - Y2);
    }
    else
    {
        ll ret;
        cin >> ret;
        return ret;
    }
}
ll jawab(ll X, ll Y)
{
    cout << "DIG " << X << " " << Y << endl;
    if(tes)
    {
        if(X == X1 && Y == Y1)
            return 1;
        if(X == X2 && Y == Y2)
            return 1;
        return 0;
    }
    else
    {
        ll ret;
        cin >> ret;
        return ret;
    }
}
int main()
{
    // ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll T;
    cin >> T;
    while(T--)
    {
        
        cin >> n >> m;
        if(tes)
        {   
            X1 = rand() % n + 1;
            Y1 = rand() % m + 1;
            X2 = rand() % n + 1;
            Y2 = rand() % m + 1;
            cout << X1 << " " << Y1 << "\n";
            cout << X2 << " " << Y2 << "\n";
        }
        ll W = tanya(1, 1) + 4;
        ll X = tanya(n, 1) + 2 - 2 * n;
        ll Yt = (W + X) / 2;
        ll Xt = W - Yt;
        ll O = Xt / 2;
        ll Y = tanya(O, 1) + 2;
        ll A = (W - Y) / 2;
        ll C = Xt - A;
        ll P = Yt / 2;
        ll Z = tanya(1, P) + 2;
        ll B = (W - Z) / 2;
        ll D = Yt - B;
        // cout << "JWB\n";
        if(jawab(A, B))
        {
            jawab(C, D);
        }
        else
        {
            swap(B, D);
            jawab(A, B);
            jawab(C, D);
        }
        // cout << A << " " << B << "\n";
        // cout << C << " " << D << "\n";

    }
}