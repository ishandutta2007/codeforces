#include<bits/stdc++.h>
#define maxn 235000

using namespace std;
typedef long long ll;
ll n,ans,k;

int main()
{
    scanf("%d%d",&n,&k);
    ans=1;
    if (k>1) ans+=n*(n-1)/2;
    if (k>2) ans+=n*(n-1)*(n-2)/3;
    if (k>3) ans+=n*(n-1)*(n-2)*(n-3)*3/8;
    cout << ans << endl;
}