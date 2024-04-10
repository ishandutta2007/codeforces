#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define fr front()
#define se second
#define pll pair<ll,ll>

using namespace std;

const ll MOD=1000000007;

ll n, m, i, j, Q, k, l, T, d2[100001], w[2];

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    string s, d;
    cin >> s;
    bool tt=0;
    for (int i = s.size()-1; i > -1; i--)
    {
        if (s[i]!='a') d+=s[i],w[tt]++; else tt=1;
    }
    reverse(d.begin(),d.end());
    //cout << w[1] << " " << w[0] << "\n";
    if (d.size()%2 || w[0]<w[1]) {cout << ":(";exit(0);}
    //cout << d << "\n";
    for (int i = 0; i < d.size()/2; i++)
        if (d[i]!=d[i+d.size()/2]) {cout << ":(";exit(0);}
    cout << s.substr(0,s.size()-d.size()/2);
}
/*
10 11
1 2
1 3
1 4
3 4
2 5
2 6
5 6
3 7
4 8
5 9
6 10
*/