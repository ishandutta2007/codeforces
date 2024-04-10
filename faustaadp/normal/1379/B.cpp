#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 2e5 + 5;
ll t, L, R, m;
ll batas;
ll bisa(ll A, ll B)
{
    if(A <= 0)
        return 0;
    return (abs(A - m) <= B);
}
ll cek(ll A, ll z)
{
    return((bisa(A * z, batas) == 1) && (bisa((A + 1) * z, batas) == 0) && (bisa((A - 1) * z, batas) == 0));
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
    cin >> t;
    while(t--)
    {
        cin >> L >> R >> m;
        batas = R - L;
        for(ll i = L; i <= R; i++)
        {
            ll bawah = m / i;
            ll atas = m / i + 1;
            if(cek(bawah, i))
            {
                cout << i << " " << L + (m - bawah * i) << " " << L << "\n";
                break;
            }
            if(cek(atas, i))
            {
                cout << i << " " << L << " " << L + (atas * i- m) << "\n";
                break;
            }
        }
    }
}