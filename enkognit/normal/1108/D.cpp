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

ll n, m, k, j, o, ans, a[500001];
string s,d[6],ss;
map<ll,ll> t;

int main()
{
	//freopen("unionday.in", "r", stdin);
	//freopen("unionday.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	cin >> n;
	cin >> s;
	s+=' ';
	ll x=0;
	for (int i = 1; i < n; i++)
    {
        if (s[i-1]==s[i])
        {

            if (s[i-1]!='R' && s[i+1]!='R') s[i]='R'; else
            if (s[i-1]!='B' && s[i+1]!='B') s[i]='B'; else
            if (s[i-1]!='G' && s[i+1]!='G') s[i]='G';
            x++;
            //cout << s[i] << "\n";
        }
    }
    cout << x << "\n";
    cout << s;
    return 0;
}
/**/
/**/