#include<bits/stdc++.h>
#define maxn 203400

using namespace std;
typedef long long ll;

ll a,b,n,k,ans,s;

int main()
{
    scanf("%d%d%d%d",&n,&k,&a,&b);
    ans=(n-1)*a;
    while (n>1&&k>1){
        s+=(n%k)*a+b;
        n/=k;
        ans=min(ans,s+(n-1)*a);
    }
    cout << ans << endl;
}