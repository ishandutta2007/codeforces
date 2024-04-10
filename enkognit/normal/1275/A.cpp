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

ll n, m, k, l, r, T, i, j, kl, x, y, z, h, a, b, c, d;
vector <ll> v;
map<pair<char,char>, char> w;

void rec(ll a,ll b,ll c,ll d)
{
    if (a==0 && b==0 && c==0 && d==0)
    {
        //cout << "YES\n";
        for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
        cout << "\n";
        //exit(0);
    }
    if (v.size()==0)
    {
        v.pb(0);
        rec(a-1,b,c,d);
        v[0]=1;
        rec(a,b-1,c,d);
         v[0]=2;
        rec(a,b,c-1,d);
        v[0]=3;
        rec(a,b,c,d-1);
        return;
    }
    if (v.back()==0 && b) {v.pb(1);rec(a,b-1,c,d);v.pop_back();}
    if (v.back()==1)
    {
        v.pb(0);
        if (a)rec(a-1,b,c,d);
        v.pop_back();
        v.pb(2);
        if (c)rec(a,b,c-1,d);
        v.pop_back();
    }
    if (v.back()==2)
    {
        v.pb(1);
        if (b)rec(a,b-1,c,d);
        v.pop_back();
        v.pb(3);
        if (d)rec(a,b,c,d-1);
        v.pop_back();
    }
    if (v.back()==3 && c) {v.pb(2);rec(a,b,c-1,d);v.pop_back();}
}

void solve()
{
    a=x;b=y;c=z;d=h;
    v.clear();
    if (a<b) v.pb(1),b--;
    for (int i = 0; i < a; i++) v.pb(0), v.pb(1), b--;
    if (b<0) {cout << "NO\n";exit(0);}
    for (int i = 0; i < b; i++) v.pb(2), v.pb(1), c--;
    if (c<0) {cout << "NO\n";exit(0);}
    for (int i = 0; i < d; i++) v.pb(2), v.pb(3), c--;
    if (c<0) {cout << "NO\n";exit(0);}
    if (c) v.pb(2), c--;
    if (c!=0) {cout << "NO\n";exit(0);}
    cout << "YES\n";
    for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b >> c >> d;
    x=a;
    y=b;
    z=c;
    h=d;
    if (b==0 && c==0 && d==0) {if (a==1)cout << "YES\n0"; else cout << "NO\n";exit(0);}
    if (c==0 && a==0 && b==0) {if (d==1)cout << "YES\n3"; else cout << "NO\n";exit(0);}
    if (c==0 && d==0 && a-b==1)
    {
        cout << "YES\n";
        for (int i = 0; i < b; i++) cout << "0 1 ";
        cout << "0\n";
        exit(0);
    }
    if (a==0 && b==0 && d-c==1)
    {
        cout << "YES\n";
        for (int i = 0; i < c; i++) cout << "3 2 ";
        cout << "3\n";
        exit(0);
    }
    //if (abs(a-d)>1 || abs(b-c)>1 || a>b || c<d) {cout << "NO\n";exit(0);}
    //rec(a,b,c,d);
    vector <ll> v;
    //if (max(a,d)>m2 3 2 3 in(b,c)) {cout << "NO\n";exit(0);}
    //if (a<b) v.pb(1),b--;
    //solve();
    if (b-a==c-d && b-a>0)
    {
        cout << "YES\n";
        for (int i = 0; i < a; i++) cout << "1 0 ";
        for (int i = 0; i < b-a; i++) cout << "1 2 ";
        for (int i = 0; i < d; i++) cout << "3 2 ";
    }else
    if (b-a+1==c-d+1 && b-a+1>0)
    {
        cout << "YES\n";
        for (int i = 0; i < a; i++) cout << "0 1 ";
        for (int i = 0; i < b-a; i++) cout << "2 1 ";
        for (int i = 0; i < d; i++) cout << "2 3 ";
    }else
    if (b-a==c-d+1 && b-a>0)
    {
        cout <<"YES\n";
        for (int i = 0; i < a; i++) cout << "1 0 ";
        for (int i = 0; i < b-a-1; i++) cout << "1 2 ";
        cout << "1 ";
        for (int i = 0; i < d; i++) cout << "2 3 ";
    }else
    if (b-a+1==c-d && b-a+1>0)
    {
        cout <<"YES\n";
        for (int i = 0; i < a; i++) cout << "0 1 ";
        for (int i = 0; i < b-a; i++) cout << "2 1 ";
        cout << "2 ";
        for (int i = 0; i < d; i++) cout << "3 2 ";
    }else
    cout << "NO\n";
    //for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
    return 0;
}