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

ll n, m, j, o, l, r, x, y, a[200001], k[5];
string s;


int main()
{
	//freopen("unionday.in", "r", stdin);
	//freopen("unionday.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        k[i%2]+=a[i];
    }
    //sort(a,a+n);
    ll ans=0;
    for (int i = n-1; i > -1; i--)
    {
        k[i%2]-=a[i];
        if (k[0]==k[1]) ans++;
        k[(i+1)%2]+=a[i];
    }
    cout << ans;
    return 0;
}