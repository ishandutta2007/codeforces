#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
const ll NN = 1e4 + 5;
ll t;
ll n, m, ta, x[99], y[99];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        for(ll i = 0;i <= 60; i++)
        {
            x[i] = 0;
            y[i] = 0;
        }
        for(ll i = 0;i <= 60; i++)
            if(n & (1LL << i))
                x[i]++;
        for(ll i = 1;i <= m; i++)
        {
            cin >> ta;
            for(ll j = 0; j <= 60; j++)
                if(ta & (1LL << j))
                    y[j]++;
        }
        ll has = 0;
        ll hut = -1;
        for(ll i = 0; i <= 60; i++)
        {
            if((y[i] > 0) && (hut != -1))
            {
                y[i]--;
                has += abs(i - hut);
                hut = -1;
            }
            if(x[i] && y[i])
            {
                x[i]--;
                y[i]--;
            }   
            if((x[i] > 0) && (y[i] == 0))
            {
                if(hut == -1)
                    hut = i;
            }
            y[i + 1] += y[i]/2;
        }
        if(hut != -1)
            has = -1;
        cout << has << "\n";
    }
}