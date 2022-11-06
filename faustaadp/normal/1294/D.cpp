#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
const ll NN = 4e5 + 5;
ll q, x;
set<pair<ll, ll > > s1;
set<ll> s2[NN];
ll X[NN];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> q >> x;
    for(ll i = 0; i < x; i++)
    {
        s2[0].insert(i);
        s1.insert(mp(0, i));
    }
    while(q--)
    {
        ll ta;
        cin >> ta;
        ta %= x;

        s1.erase(mp(X[ta], ta));
        s2[X[ta]].erase(ta); 
        X[ta]++;
        s1.insert(mp(X[ta], ta));
        s2[X[ta]].insert(ta); 

        auto it = s1.begin();
        pair<ll,ll> temp = *it;
        ll kecil = temp.fi;
        auto ite = s2[kecil].begin();
        ll tmp = *ite;
        cout << kecil * x + tmp << "\n";
    }
}