#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 3e5 + 5;
const ll mo = 1e9 + 7;
ll m[4], a[4][NN], jum[4], hz, has, mi[4];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    for(ll i = 1; i <= 3; i++)
    	cin >> m[i];
    for(ll i = 1; i <= 3; i++)
    {
    	mi[i] = 1e18;
    	for(ll j = 1; j <= m[i]; j++)
    	{
    		cin >> a[i][j];
    		mi[i] = min(mi[i], a[i][j]);
    		jum[i] += a[i][j];
    	}
    }
    hz = jum[1] + jum[2] + jum[3];
    has = max(has, hz - (jum[1] * 2));
    has = max(has, hz - (jum[2] * 2));
    has = max(has, hz - (jum[3] * 2));
    has = max(has, hz - ((mi[1] + mi[2]) * 2));
    has = max(has, hz - ((mi[1] + mi[3]) * 2));
    has = max(has, hz - ((mi[2] + mi[3]) * 2));
    cout << has << "\n";
}