#include <bits/stdc++.h>

#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define pll pair<ll,ll>
#define ld long double
#define sqr(a) ((a)*(a))

using namespace std;

ll n, m, i, k, ans, l, r, no, yes, an1[1000001], an2[1000001];
map<ll,bool> tt={};
pair<pll,pair<string,ll> > s[100001];

int main()
{
    //freopen("roulette.in","r",stdin);
    //freopen("roulette.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i].se.fi;
        for (int j = 0; j < m; j++)
            if (s[i].se.fi[j]=='>') s[i].fi.fi++; else
            if (s[i].se.fi[j]=='=') s[i].fi.se++;
        s[i].se.se=i;
    }
    sort(s,s+n);
    //reverse(s,s+n);
    ll k=0;
    for (int i = 0; i < n; i++)
    {
        //cout << s[i].se.fi << "\n";
        string d=s[i].se.fi;
        if (i>0 && d==s[i-1].se.fi) {an1[s[i].se.se]=an1[s[i-1].se.se];continue;}
        k++;
        bool tt=0;
        for (int j = 0; j < m; j++)
        {
            if (i>0)
            {
                if (s[i-1].se.fi[j]=='>' && d[j]!='>') {cout << "No\n";exit(0);}
                if (s[i-1].se.fi[j]=='=' && d[j]=='=' && d!=s[i-1].se.fi) {cout << "No\n";exit(0);}
                if (s[i-1].se.fi[j]=='=' && d[j]=='<') {cout << "No\n";exit(0);}
                if (d[j]=='>' && s[i-1].se.fi[j]=='<' && !tt)k++,tt=1;
            }else
            {
                if (d[j]=='>' && !tt)k++,tt=1;
            }
        }
        for (int j = 0; j < m; j++)
        {
            if (i>0)
            {
                if (d[j]=='>' && s[i-1].se.fi[j]=='<') an2[j]=k-tt;
            }
             else
            {
                if (d[j]=='>') an2[j]=k-tt;
            }
            if (d[j]=='=') an2[j]=k;
        }
        an1[s[i].se.se]=k;
    }
    k++;
    cout << "Yes\n";
    for (int i = 0; i < n; i++) cout << an1[i] << " ";
    cout << "\n";
    for (int i = 0; i < m; i++) if (an2[i]==0) cout << k << " "; else cout << an2[i] << " ";
    return 0;
}