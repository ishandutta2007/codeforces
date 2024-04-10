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
    vl v;
    long n,k,i,a[200005],cur=0,sum=0,nn,last,rating,cnt=0;
    cin>>n>>k;
    nn=n;
    for(i=1;i<=n;++i)
    cin>>a[i];
    last=1;
    rating=0;
    cnt=2;
    for(i=2;i<=n;++i)
    {
        sum+=a[last]*(i-2-cur);
        rating=sum-(cnt-1)*(nn-(i-cur))*a[i];
        if(rating<k)
        {
            sum-=a[last]*(i-2-cur);
            v.pb(i);
            nn--;
            cur++;
        }
        else last=i,cnt++;
    }
    for(i=0;i<v.size();++i)
    cout<<v[i]<<endl;
    return 0;
}