#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
const ll NN = 1e5 + 5;
ll t, n, m;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);  
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        ll nol = n - m;
        ll sep = m + 1;
        ll sz1 = nol / sep;
        ll sz2 = nol / sep + 1;
        ll bsr = nol % sep;
        ll kcl = sep - bsr;
        // cout << bsr << " " << kcl << "\n";
        ll has = n * (n + 1) / 2;
        has -= bsr * (sz2 * (sz2 + 1) / 2);
        has -= kcl * (sz1 * (sz1 + 1) / 2);
        cout << has << "\n";
    }     
}