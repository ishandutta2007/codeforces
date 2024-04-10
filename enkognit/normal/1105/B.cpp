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
map<char,ll> c;

int main()
{
	//freopen("unionday.in", "r", stdin);
	//freopen("unionday.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	cin >> n >> m;
	cin >> s;
	ll k=1;
	s+=' ';
	for (int i = 1; i <= n; i++)
    {
        if (k==m) k=0,c[s[i-1]]++;
        if (s[i-1]==s[i]) k++; else k=1;
    }
    ll ans=0;
    for (int i = 'a'; i <= 'z'; i++) ans=max(ans,c[i]);
    cout << ans;
    return 0;
}