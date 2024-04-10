#include <bits/stdc++.h>

#define ll long long
#define fi first
#define fr front()
#define se second
#define pb push_back
#define mp make_pair
#define sqr(a) ((a)*(a))
#define ld long double
#define pll pair<ll,ll>
#define pii pair<int,int>
//#define pi 3.14159265358979323846

using namespace std;

ll n, m, k, j, o, l, r;
ll a[500001], t[500001];
ll b[5001];
bool fl1=0, fl2=0;

ll dist(ll x,ll y)
{
    if (x<=y) return y-x; else return n-x+y;
}

int main()
{
	//freopen("unionday.in", "r", stdin);
	//freopen("unionday.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;
        x--;
        y--;
        if (t[x]==0)b[x]=y; else if (dist(x,b[x])>dist(x,y)) b[x]=y;
        t[x]++;
    }
    for (int i = 0; i < n; i++)
    {
        ll ans=0;
        //cout << i+1 << ":\n";
        for (int j = 0; j < n; j++)
            if (t[j])
        {
            //cout <<" "<< j+1 << ": " << dist(i,j)+n*(t[j]-1)+dist(j,b[j]) << "\n";
            ans=max(dist(i,j)+n*(t[j]-1)+dist(j,b[j]),ans);
        }
        cout << ans << " ";
    }
    //cout << ans;
    return 0;
}
/*

*/