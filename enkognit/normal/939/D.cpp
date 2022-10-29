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

ll n, m, k, j, o, l, r, ans=0;
bool c[101][101];
bool t[101];
vector <pll> v;
string s, d;

void dfs(ll h)
{
    t[h]=0;
    for (int i = 0; i < 26; i++)
        if (t[i] && c[h][i]) {v.pb(mp(h,i));dfs(i);}
}

int main()
{
	//freopen("unionday.in", "r", stdin);
	//freopen("unionday.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    cin >> s;
    cin >> d;
    for (int i = 0; i < n; i++)
        if (s[i]!=d[i])
        {
            t[s[i]-'a']=1;
            t[d[i]-'a']=1;
            c[s[i]-'a'][d[i]-'a']=1;
            c[d[i]-'a'][s[i]-'a']=1;
        }
    for (int i = 0; i < 26; i++)
        if (t[i])
        {
            dfs(i);
        }
    cout << v.size() << "\n";
    for (int i = 0; i < v.size(); i++) cout << (char)(v[i].fi+'a') << " " << (char)(v[i].se+'a') << "\n";
    return 0;
}
/*

*/