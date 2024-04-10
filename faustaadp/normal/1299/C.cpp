#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
const ll NN = 1e6 + 5;
ll t;
ll n, i, x[NN], p[NN];
long double d[NN], a[NN];
priority_queue<pair<long double, ll> > pq;
ll car(ll aa)
{
    if(p[aa] == aa)
        return aa;
    return p[aa] = car(p[aa]);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(ll i = 1; i <= n; i++)
    {
        ll ta;
        cin >> ta;
        a[i] = ta;
        x[i] = 1;
        d[i] = a[i];
        p[i] = i;
        pq.push(mp(a[i], i));
    }
    while(!pq.empty())
    {
        ll idx = pq.top().se;
        pq.pop();
        ll kan = car(idx);
        ll kan2 = car(kan + 1);
        if(kan == n || d[kan2] > d[car(kan)])
            continue;
        x[kan2] += x[car(kan)];
        a[kan2] += a[car(kan)];
        d[kan2] = a[kan2] / (long double)x[kan2];
        p[car(kan)] = kan2;
        pq.push(mp(d[kan2] ,kan2));
    }
    for(ll i = 1;i <= n; i++)
        cout << fixed << setprecision(9) << d[car(i)] << "\n";
}