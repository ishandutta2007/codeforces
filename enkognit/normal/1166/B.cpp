#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pll pair<ll,ll>
#define fr front()
#define sqr(a) ((a)*(a))
#define y1 Enkognit

using namespace std;

const ll MOD=1000000007;

ll n, m, l, r, ans, k;
string s, d, f;
vector <char> v;
char a[10005][10001];
//bool tl[1001][201], tr[1001][201];

int main()
{
    //freopen("divisors.in","r",stdin);
    //freopen("divisors.out","w",stdout);
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    cin >> n;
    f="aeiuo";
    a[1][1]='a';
    a[1][2]='o';
    a[1][3]='u';
    a[1][4]='i';
    a[1][5]='e';
    a[2][1]='o';
    a[2][2]='a';
    a[2][3]='i';
    a[2][4]='e';
    a[2][5]='u';
    a[3][1]='u';
    a[3][2]='i';
    a[3][3]='e';
    a[3][4]='a';
    a[3][5]='o';
    a[4][1]='i';
    a[4][2]='e';
    a[4][3]='o';
    a[4][4]='u';
    a[4][5]='a';
    a[5][1]='e';
    a[5][2]='u';
    a[5][3]='a';
    a[5][4]='o';
    a[5][5]='i';
    for (int i = 5; i <= n; i++)
        if (n%i==0)
        {
            ll l=i, r=n/i;
            if (r<5) continue;
            //cout << l << " " << r  << "\n";
            for (int i = 6; i <= l; i++)
                for (int j = 1; j <= 5; j++) {a[i][j]=f[j-1];}
            for (int i = 6; i <= r; i++)
                for (int j = 1; j <= 5; j++) {a[j][i]=f[j-1];}
            for (int i = 1; i <= l; i++)
            {for (int j = 1; j <= r; j++) if (a[i][j]) cout << a[i][j]; else
                {cout << 'a';}}
            exit(0);
        }
    cout << -1;
    return 0;
}
/*
5
2 3 4 5 6
6
1 2 4
1 2 3
0 1 1
0 4 7
1 1 3
1 1 4
bokutachi wa benkyou ga dekinai
*/