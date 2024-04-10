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
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    ll q;
    cin >> n >> q;
    if (n<q*(q+1)/2) {cout << "NO\n";exit(0);}
    ll sum=q*(q+1)/2, m=(n-sum)/q, p=(n-sum)%q;
    for (int i = 1; i <= q; i++)
    {
        a[i]=i+m;
        sum+=m;
    }
    for (int i = q-p+1; i <= q; i++) if (a[i-1]*2>=a[i]+1) a[i]++,sum++;
    sum=n-sum;
    if (sum)
    {
        if (a[q]+sum>a[q-1]*2) {cout << "NO\n";exit(0);}
        a[q]+=sum;
    }
    cout << "YES\n";
    for (int i = 1; i <= q; i++) cout << a[i] << " ";
}