#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define fr front()
#define se second
#define pll pair<ll,ll>
#define pii pair<int,int>

using namespace std;

const ll MOD=1e9+7;

ll n, m, i, j, k, l, r, ans[100001], T, in[100001], out[100001], hh[100001];
vector <ll> c[100001], v[200001];
bool t[400001];

void ext()
{
    cout << ":(";
    exit(0);
}

string s;

int main()
{
    //freopen("tree.in","r",stdin);
    //freopen("tree.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    cin >> s;
    s=' '+s;
    if (s[1]==')') ext();
    if (s[n]=='(') ext();
    s[1]='(';
    s[n]=')';
    for (int i = 2; i < n; i++)
    {
        if (s[i]=='?') t[i]=1, s[i]='(';
        if (s[i]=='(') k++; else k--;
    }
    for (int i = n-1; i > 1; i--)
    {
        if (k>0 && t[i]) s[i]=')', k-=2;
    }
    //if (k!=0) ext;
    ll p = 1;
    for (int i = 2; i <= n; i++)
    {
        //cout << (p==0) << "\n";
        if (p==0) ext();
        if (s[i]=='(') p++; else p--;
    }
    if (p!=0)ext();
    s.erase(0,1);
    cout << s;
}
/*
6 3
2 10 6 0 5 2
*/