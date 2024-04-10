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

ll n, m, k, j;
string s,d;

int main()
{
	//freopen("unionday.in", "r", stdin);
	//freopen("unionday.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	cin >> s;
	d=s;
	ll l=0,r=0;
	reverse(d.begin(),d.end());
	if (s.find('[')==string::npos) {cout << -1;exit(0);} else l=(ll)s.find('[');
	if (d.find(']')==string::npos) {cout << -1;exit(0);} else r=(ll)(d.size()-d.find(']')-1);
	ll lp=0, rp=0;
	for (int i = l; i < r; i++) if (s[i]==':') {lp=i;break;}
	for (int i = r; i > l; i--) if (s[i]==':') {rp=i;break;}
	if (lp>=rp) {cout << -1;exit(0);}
	ll le=0;
	for (int i = lp; i < rp; i++) le+=(ll)(s[i]=='|');
	cout << le+4;
    return 0;
}