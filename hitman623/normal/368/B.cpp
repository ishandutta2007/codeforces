#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define pll pair < long , long >
#define vll vector < pll >
#define ml map < long , long >
#define mll map < pll , long >
#define x first
#define y second
#define vl vector < long >
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int main()
{
    io
    set < long > s;
    long n,a[100005],m,i,ans[100005]={0},l,j;
    cin>>n>>m;
    for(i=1;i<=n;++i)
    cin>>a[i];
    for(j=n;j>0;j--)
    {
        s.insert(a[j]);
        ans[j]=s.size();
    }
    while(m--)
    {
        cin>>l;
        cout<<ans[l]<<"\n";
    }
    return 0;
}