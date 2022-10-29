#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>
#define pb push_back


using namespace std;

const ll MOD=1e9+7;

ll n, m, k, l, r, i, j, a[500001], d[1000001];
string s;
vector <ll> v;
bool tt[1000001], q[1000001];

int main()
{
   // freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int it = 0; it< n; it++)
    {
        cin >> s;
        s+=' ';
        for (int i = 0; i < 36; i++) tt[i]=0, q[i]=0, a[i]=0;
        for (int i = 0; i < s.size()-1; i++)
        {if (s[i]==s[i+1])
        {
            q[s[i]-'a']=1;
            i++;
        } else tt[s[i]-'a']=1;a[s[i]-'a']=1;}
        vector <ll> v;
        for (int i = 0; i < 36; i++)if (!(q[i] && !tt[i]) && a[i])
        {
            v.pb('a'+i);
        }
        for (int i = 0; i < v.size(); i++) cout << (char)v[i];
        cout << "\n";
    }
    return 0;
}