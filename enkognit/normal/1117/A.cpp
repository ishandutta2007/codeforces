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
ll a[100001];
string s, d;
vector <ll> c[100002];

int main()
{
	//freopen("unionday.in", "r", stdin);
	//freopen("unionday.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
    {cin >> a[i];k=max(k,a[i]);}
    ll p=0, u=0;
    for (int i = 0; i < n; i++)
    {
        if (a[i]==k) p++; else p=0;
        u=max(u,p);
    }
    cout << u;
    return 0;
}
/*

*/