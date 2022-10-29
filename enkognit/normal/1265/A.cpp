#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define fi first
#define se second
#define pld pair<ld,ld>
#define pll pair<ll,ll>
#define pii pair<int,int>
#define y1 Enkognit

using namespace std;

ll MOD=1e9+7;

ll n, m, k, l, r, T, i, j, kl, x, y, a[1000001];
vector <ll> v;
map<pair<char,char>, char> w;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    w[mp('a','a')]='c';
    w[mp('a','c')]='b';
    w[mp('c','a')]='b';
    w[mp('c','c')]='b';
    w[mp('b','c')]='a';
    w[mp('c','b')]='a';
    w[mp('b','b')]='a';
    w[mp('a','b')]='c';
    w[mp('b','a')]='c';
    w[mp('b','?')]='a';
    w[mp('a','?')]='b';
    w[mp('c','?')]='a';
    w[mp('?','c')]='a';
    w[mp('?','b')]='c';
    w[mp('?','a')]='c';
    w[mp('?','?')]='a';
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        s='?'+s+'?';
        bool t=0;
        for (int j = 1; j < s.size(); j++)
        {
            if (s[j]=='?')
            {
                s[j]=w[mp(s[j-1],s[j+1])];
            }else
            if (s[j]==s[j-1] || s[j]==s[j+1]) t=1;
        }
        if (t) {cout << "-1\n";continue;}
        s.erase(s.begin());
        for (int j = 0; j < s.size()-1; j++) cout << s[j];
        cout << "\n";
    }
    return 0;
}