#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define sqr(a) ((a)*(a))
#define pll pair<ll,ll>
#define pii pair<int,int>
#define y1 Enkognit

using namespace std;

ll n, m, k, q, ans=1e18, l, r, i, j, x, y, kol=0, a[50][50], b[50][50];
string s, t;
vector <ll> v[1000], c[200001];

void endb()
{
    cout << "!\n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++) cout << b[i][j];
        cout << "\n";
    }
    exit(0);
}

void enda()
{
    cout << "!\n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++) cout << a[i][j];
        cout << "\n";
    }
    exit(0);
}

void check1(ll x,ll y)
{
    if (x+1>n || y+2>n) return;
    ll p1=((a[x][y]==a[x+1][y+2])&&(a[x+1][y]==a[x+1][y+1]||a[x][y+1]==a[x+1][y+1]||a[x][y+1]==a[x][y+2]));
    ll p2=((b[x][y]==b[x+1][y+2])&&(b[x+1][y]==b[x+1][y+1]||b[x][y+1]==b[x+1][y+1]||b[x][y+1]==b[x][y+2]));
    if (p1!=p2)
    {
        cout << "? " << x << " " << y << " " << x+1 << " " << y+2 << "\n";
        ll p;
        cin >> p;
        fflush(stdout);
        if (p==p1) enda(); else endb();
    }
}

void check2(ll x,ll y)
{
    if (x+2>n || y+1>n) return;
    ll p1=((a[x][y]==a[x+2][y+1])&&(a[x+1][y]==a[x+1][y+1]||a[x][y+1]==a[x+1][y+1]||a[x+1][y]==a[x+2][y]));
    ll p2=((b[x][y]==b[x+2][y+1])&&(b[x+1][y]==b[x+1][y+1]||b[x][y+1]==b[x+1][y+1]||b[x+1][y]==b[x+2][y]));
    if (p1!=p2)
    {
        cout << "? " << x << " " << y << " " << x+2 << " " << y+1 << "\n";
        ll p;
        cin >> p;
        fflush(stdout);
        if (p==p1) enda(); else endb();
    }
}

int main()
{
    //freopen("walk.in","r",stdin);
    //freopen("walk.out","w",stdout);
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) a[i][j]=-1;
    a[1][1]=1;
    a[n][n]=0;
    for (int i = 1; i <= n; i++)
    {
        ll j=1;
        if (i%2==0) j++;
        for (; j <= n; j+=2)
        {
            if (i<n && j<n && a[i][j]!=-1 && a[i+1][j+1]==-1)
            {
                cout << "? " << i << " " << j << " " << i+1 << " " << j+1 << "\n";
                ll p;
                cin >> p;
                fflush(stdout);
                if (p==1) a[i+1][j+1]=a[i][j]; else a[i+1][j+1]=(!a[i][j]);
            }
            if (j+1<n && a[i][j]!=-1 && a[i][j+2]==-1)
            {
                cout << "? " << i << " " << j << " " << i << " " << j+2 << "\n";
                ll p;
                cin >> p;
                fflush(stdout);
                if (p==1) a[i][j+2]=a[i][j]; else a[i][j+2]=(!a[i][j]);
            }
            if (i+1<n && a[i][j]!=-1 && a[i+2][j]==-1)
            {
                cout << "? " << i << " " << j << " " << i+2 << " " << j << "\n";
                ll p;
                cin >> p;
                fflush(stdout);
                if (p==1) a[i+2][j]=a[i][j]; else a[i+2][j]=(!a[i][j]);
            }
        }
    }

    a[1][2]=1;

    for (int i = 1; i <= n; i++)
    {
        ll j=1;
        if (i%2) j++;
        for (; j <= n; j+=2)
        {
            if (i<n && j<n && a[i][j]!=-1 && a[i+1][j+1]==-1)
            {
                cout << "? " << i << " " << j << " " << i+1 << " " << j+1 << "\n";
                ll p;
                cin >> p;
                fflush(stdout);
                if (p==1) a[i+1][j+1]=a[i][j]; else a[i+1][j+1]=(!a[i][j]);
            }
            if (j+1<n && a[i][j]!=-1 && a[i][j+2]==-1)
            {
                cout << "? " << i << " " << j << " " << i << " " << j+2 << "\n";
                ll p;
                cin >> p;
                fflush(stdout);
                if (p==1) a[i][j+2]=a[i][j]; else a[i][j+2]=(!a[i][j]);
            }
            if (i+1<n && a[i][j]!=-1 && a[i+2][j]==-1)
            {
                cout << "? " << i << " " << j << " " << i+2 << " " << j << "\n";
                ll p;
                cin >> p;
                fflush(stdout);
                if (p==1) a[i+2][j]=a[i][j]; else a[i+2][j]=(!a[i][j]);
            }
        }
    }

    for (int i = 2; i <= n; i+=2)
        if (a[i][1]==-1)
    {
        cout << "? " << i << " 1 " << i << " 3\n";
        ll p;
        cin >> p;
        fflush(stdout);
        if (p==1) a[i][1]=a[i][3];
        else a[i][1]=!a[i][3];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++) b[i][j]=(a[i][j]^((i+j)%2));
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            check1(i,j);
            check2(i,j);
        }
    }

    return 0;
}


/*
2 4 4 2
1 2
1 4
2 3
2 1
1 3


*/