#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 2e5 + 5;
ll n, x[NN], y[NN], a[NN], sz;
void masuk(ll idx, ll mas)
{
    for(ll i = sz; i > idx; i--)
        a[i + 1] = a[i];
    a[idx + 1] = mas; 
}
void gagal()
{
    cout << -1 << "\n";
    exit(0);
}
unsigned long long jar(ll I, ll J)
{
    return (x[I] - x[J]) * (x[I] - x[J]) + (y[I] - y[J]) * (y[I] - y[J]);
}
ll cek(ll I, ll J, ll K)
{
    if(I == 0 || J == 0 || K == 0)
        return 1;
    // ll val = (y[J] - y[I]) * (x[K] - x[J]) - (x[J] - x[I]) * (y[K] - y[J]);
    unsigned long long X = jar(I, J);
    unsigned long long Y = jar(J, K);
    unsigned long long Z = jar(I, K);
    // cout << X << " " << Y << " " << Z << "\n";
    // cout << X + Y << " " << Z << "\n";
    return (X + Y > Z);
}
void cetak()
{
    // cout << "CETAK\n";
    for(ll i = 1; i <= sz; i++)
        cout << a[i] << " ";
    cout << "\n";
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(ll i = 1; i <= n; i++)
    {
        // x[i] = rand() % 100;
        // y[i] = rand() % 100;
        cin >> x[i] >> y[i];
    }
    a[1] = 1;
    a[2] = 2;
    for(ll i = 3; i <= n; i++)
    {
        sz = i - 1;
        // cout << cek(1, 2, 3) << "\n";
        if(cek(a[i - 2], a[i - 1], i))
            a[i] = i;
        else
        if(cek(i, a[1], a[2]))
            masuk(0, i);
        else
        {
            ll ada = 0;
            for(ll j = 1; j < sz; j++)
                if(cek(a[j], i, a[j + 1]) && cek(a[j - 1], a[j], i) && cek(i, a[j + 1], a[j + 2]))
                {
                    masuk(j, i);
                    ada = 1;
                    break;
                }
            if(!ada)
                gagal();    
        }
        sz++;
        // cetak();
    }
    for(ll i = 2; i < n; i++)
        if(!cek(a[i - 1], a[i], a[i + 1]))
            gagal();
    cetak();
}