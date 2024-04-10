#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define sqr(a) ((a)*(a))
#define ld long double
#define pll pair<ll,ll>
#define pii pair<int,int>
//#define pi 3.14159265358979323846

using namespace std;

ll n, m, k, j, tt, a[1000001];
vector <ll> v;
string s,d;

int main()
{
	//freopen("unionday.in", "r", stdin);
	//freopen("unionday.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    tt=1e18;
    for (int i = 1; i < 1000; i++)
   {
    ll ans=0;
    for (int j = 0; j < n; j++)
    {
        if (a[j]<i) ans+=i-a[j]-1;
        if (a[j]>i) ans+=a[j]-i-1;
    }
    if (ans<tt) tt=ans,m=i;
   }
   cout << m << " " << tt;
    return 0;
}