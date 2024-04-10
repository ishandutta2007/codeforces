#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
const ll NN = 4e3 + 5;
string s;
ll n, p[31][201010], q;
char a[201010];
ll cek(ll aa, ll bb)
{
    if(aa == bb)
        return 1;
    if(a[aa] != a[bb])
        return 1;
    ll jen = 0;
    for(ll i = 0; i < 26; i++)
        if((p[i][bb] - p[i][aa - 1]) > 0)
            jen++;
    if(jen > 2)
        return 1;
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> s;
    n = s.length();
    for(ll i = 1; i <= n; i++)
        a[i] = s[i - 1];
    for(ll j = 'a'; j <= 'z'; j++)
        for(ll i = 1; i <= n; i++)
        {
            p[j - 'a'][i] = p[j - 'a'][i - 1];
            if(a[i] == char(j))
                p[j - 'a'][i]++;
        }
    cin >> q;
    while(q--)
    {
        ll ta, tb;
        cin >> ta >> tb;
        if(cek(ta, tb))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}