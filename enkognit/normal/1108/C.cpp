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
    for (int i = 0; i < n; i+=3)
    {
        d[0]+="GRB";
        d[1]+="GBR";
        d[2]+="BRG";
        d[3]+="BGR";
        d[4]+="RBG";
        d[5]+="RGB";
    }
    if (n%3==1)
    {
       d[0].erase(d[0].size()-2,2);
       d[1].erase(d[1].size()-2,2);
       d[2].erase(d[2].size()-2,2);
       d[3].erase(d[3].size()-2,2);
       d[4].erase(d[4].size()-2,2);
       d[5].erase(d[5].size()-2,2);
    }
    if (n%3==2)
    {
       d[0].erase(d[0].size()-1,1);
       d[1].erase(d[1].size()-1,1);
       d[2].erase(d[2].size()-1,1);
       d[3].erase(d[3].size()-1,1);
       d[4].erase(d[4].size()-1,1);
       d[5].erase(d[5].size()-1,1);
    }
    ll ans=1e18;
    for (int j = 0; j < 6; j++)
    {
        ll x=0;
        for (int i = 0; i < n; i++)
        {
            if (s[i]!=d[j][i]) x++;
        }
        if (x<ans) ans=x,ss=d[j];
    }
    cout << ans << "\n";
    cout << ss;
    return 0;
}
/**/
/**/