#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const int NN = 3e5 + 5;
int r, n, t[NN], x[NN], y[NN], d[NN], s[NN], has; 
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> r >> n;
    for(int i = 1; i <= n; i++)
        cin >> t[i] >> x[i] >> y[i];
    for(int i = n; i >= 1; i--)
    {
        d[i] = max(1, s[i + 1001] + 1);
        int nx = min(i + 1000, n);
        for(int j = i + 1; j <= nx; j++)
            if(abs(x[i] - x[j]) + abs(y[i] - y[j]) <= (t[j] - t[i]))
                d[i] = max(d[i], d[j] + 1);
        s[i] = max(s[i + 1], d[i]);
        if(abs(1 - x[i]) + abs(1 - y[i]) <= t[i])
            has = max(has, d[i]);
    }
    cout << has << "\n";
}