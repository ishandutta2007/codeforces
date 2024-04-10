#include <bits/stdc++.h>
#define ll long long
#define fr front()
#define fi first
#define mp make_pair
#define se second
#define pb push_back
#define pll pair<ll,ll>
#define pii pair<int,int>

using namespace std;

ll n, m, i, j, a, b, c, ans;

int main()
{
    //ios_base::sync_with_stdio(0);
    cin.tie();cout.tie();
    cin >> a >> b >> c;
    ans+=c*2;
    if (b>a)
    {
        b--;
        ans++;
    }else
    if (b<a)
    {
        a--;
        ans++;
    }
    ans+=min(a,b)*2;
    cout << ans;
    return 0;
}
/*
10 2
abacdabcda
7 10 0
5 8 1

*/