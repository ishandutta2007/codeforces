#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 1e4 + 5;
ll t, n, m, a[330][330];
ll dx[] = {0, 0, -1, 1};
ll dy[] = {-1, 1, 0, 0};
ll cek(ll aa, ll bb)
{
    ll H = 0;
    for(ll i = 0; i < 4; i++)
    {
        ll nx = aa + dx[i];
        ll ny = bb + dy[i];
        if(1 <= nx && nx <= n && 1 <= ny && ny <= m)
            H++;
    }
    return H;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        ll bisa = 1;
        for(ll i = 1; i <= n; i++)
            for(ll j = 1; j <= m; j++)
            {
                cin >> a[i][j];
                if(a[i][j] > cek(i, j))
                    bisa = 0;
            }
        if(bisa)
        {
            cout << "YES\n";
            for(ll i = 1; i <= n; i++)
            {
                for(ll j = 1; j <= m; j++)
                    cout << cek(i, j) << " ";
                cout << "\n";
            }
        }
        else
            cout << "NO\n";

    }
}