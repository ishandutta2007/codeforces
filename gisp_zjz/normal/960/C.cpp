#include<bits/stdc++.h>
#define maxn 50000

using namespace std;
typedef long long ll;
const ll w=1e10;
ll a[maxn],p,n,r,c;

int main()
{
    scanf("%lld%lld",&n,&p);
    r=w;
    for (int i=0;i<=33;i++)
    if (n&(1ll<<i)) {
        for (int j=0;j<i;j++) a[c++]=r;
        r+=w; a[c++]=r; r+=w;
    }
    cout << c << endl;
    for (int i=0;i<c;i++) printf("%lld ",a[i]); printf("\n");
    return 0;
}