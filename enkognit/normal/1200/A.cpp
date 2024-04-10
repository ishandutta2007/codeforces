#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
//#pragma GCC optimize("-Otime")
//#pragma GCC optimize("unr")
#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define sqr(a) ((a)*(a))
#define pll pair<ll,ll>
#define y1 Enkognit

using namespace std;

ll n, m, i, j, k, l, r, a[300001], d[1000001];
pll b[200001];
bool tt[1000001];
string s;


int main()
{
    //freopen("tickets.in","r",stdin);
    //freopen("tickets.out","w",stdout);
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    cin >> n;
    cin >> s;
    for (int i = 0; i < 10; i++) tt[i]=0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i]=='L')
        {
            for (int j = 0; j < 10; j++)
                if (!tt[j]) {tt[j]=1;break;}
        }else
        if (s[i]=='R')
        {
            for (int j = 9; j > -1; j--)
                if (!tt[j]) {tt[j]=1;break;}
        }else
        tt[s[i]-'0']=0;
    }
    for (int i = 0; i < 10; i++) cout << tt[i];
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