#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i,x[101010],jumG,has;
char a[101010];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(i=1;i<=n;i++)cin>>a[i];
    for(i=1;i<=n;i++) if(a[i]=='G')x[i]=x[i-1]+1;
    for(i=1;i<=n;i++) if(a[i]=='G')jumG++;
    for(i=n;i>=1;i--) if(a[i]=='G'&&a[i+1]=='G')x[i]=x[i+1];
    for(i=1;i<=n;i++)has=max(has,x[i]);
    for(i=1;i<=n;i++)
        if(x[i]==0)
            has=max(has,x[i-1]+x[i+1]+1 );
    has=min(has,jumG);
    cout<<has<<"\n";
}