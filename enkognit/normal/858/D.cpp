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

ll n, m, k, j, p, v[101], ans[101];
string s[70001];
map<string,int> t;

int main()
{
	//freopen("unionday.in", "r", stdin);
	//freopen("unionday.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	cin >> n;
	for (int u = 0; u < n; u++)
    {
        cin >> s[u];
        map<string,bool> z={};
        for (int i = 0; i < s[u].size(); i++)
        {
            string d="";
            for (int j = i; j < s[u].size(); j++)
            {
                d+=s[u][j];
                if (!z[d])t[d]++;
                z[d]=1;
            }
        }
    }
    for (int u = 0; u < n; u++)
    {
        string g="11111111111111";
        for (int i = 0; i < s[u].size(); i++)
        {
            string d="";
            for (int j = i; j < s[u].size(); j++)
            {
                d+=s[u][j];
                if (t[d]==1 && d.size()<g.size()) g=d;
            }
        }
        cout << g << "\n";
    }
    //cout << t["000"];
	return 0;
}