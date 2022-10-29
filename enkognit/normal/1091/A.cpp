#include <bits/stdc++.h>
#define ll long long
#define fr front()
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define pu push
#define pll pair<ll,ll>


using namespace std;

ll n, m, k, b[101], a[100001];
string s;




int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> m >> k;
    swap(n,k);
    cout << min(n-2,min(m-1,k))+min(n-1,min(m,k+1))+min(n,min(m+1,k+2));
    return 0;
}