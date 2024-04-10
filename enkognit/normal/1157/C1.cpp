#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define fr front()
#define se second
#define pll pair<ll,ll>

using namespace std;

const ll MOD=1000000007;

ll n, m, i, j, Q, k, l, T, a[300001], b[300001], c[300001], hod=0, mx=0;
string s, ans;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {cin >> a[i];}
    for (int i = 1; i <= n; i++)
    {
        b[i]=1;
        if (a[i-1]>a[i]) b[i]=b[i-1]+1;
    }
    for (int i = n; i > 0; i--)
    {
        c[i]=1;
        if (a[i+1]>a[i]) c[i]=c[i+1]+1;
    }
    //for (int i = 1; i <= n; i++) cout << b[i] << " ";
    //cout << "\n";
    //for (int i = 1; i <= n; i++) cout << c[i] << " ";
    //cout << "\n";
    ll l=1, r=n, j=0, last=0;
    string s;
    while (l<=r)
    {
        if (a[l]<a[r])
        {
            if (mx<j+min(b[r],r-l+1) && last<a[r])mx=j+min(b[r],r-l+1), hod=j;
            if (a[l]<=last) break;
            last=a[l];
            s+='L', l++;
        }else
        {
            if (mx<j+min(c[l],r-l+1) && last<a[l])mx=j+min(c[l],r-l+1), hod=j;
            if (a[r]<=last) break;
            last=a[r];
            s+='R', r--;
        }
        j++;
    }
    //cout << s << "\n";
    if (mx<=s.size())
    {
        cout << s.size() << "\n";
        cout << s;
    } else
    {
        l=1, r=n, j=0, last=0;
        s="";
        while (l<=r)
        {
            if (hod==j)
            {
                if (a[l]<a[r])
                {
                    if (last<a[r])for (int j = 0; j < min(b[r],r-l+1); j++) s+='R';
                }else
                {
                    if (last<a[l])for (int j = 0; j < min(c[l],r-l+1); j++) s+='L';
                }
                break;
            }
            if (a[l]<a[r])
            {
                if (a[l]<=last) break;
                last=a[l];
                s+='L', l++;
            }else
            {
                if (a[r]<=last) break;
                last=a[r];
                s+='R', r--;
            }
            j++;
        }
        cout << s.size() << "\n";
        cout << s;
    }
}