#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define pll pair<ll,ll>
#define fi first
#define se second

using namespace std;

ll n, m, i, j, k, l, r, a[1005][1005];
string s[1005], d;
vector <ll> v, c[300001];
bool t[1000001];
ll w[1005][1005][4];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        s[i]=' '+s[i];
        for (int j = 1; j <= m; j++)
            if (i==1 || s[i-1][j]!=s[i][j]) a[i][j]=1;
              else
              a[i][j]=a[i-1][j]+1;
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            ll p=a[i][j], k=1, st=i, x[4]={};
            bool tt=1;
            while (k<4)
            {
                if (st<1 || (a[st][j]!=p && !(k==3 && a[st][j]>p)) || (k>1 && s[st][j]==s[st+p][j])) {tt=0;break;}
                x[k]=s[st][j];
                k++;
                st-=p;
            }
            if (tt)
            {
                x[4]=p*3;
                for (int u = 1; u <= 4; u++) w[i][j][u]=x[u];
            }
        }
    ll k=0, ans=0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (w[i][j][4]==0)continue;
            k++;
            if (w[i][j][4]==w[i][j+1][4] && w[i][j][3]==w[i][j+1][3]
                && w[i][j][2]==w[i][j+1][2] && w[i][j][1]==w[i][j+1][1]) {continue;}
            ans+=k*(k+1)/2;
            //cout << i << " " << j << "\n";
            k=0;
        }
    cout << ans;
}