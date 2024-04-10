#include<bits/stdc++.h>
#define maxn 129
#define N 500050

using namespace std;
typedef long long ll;
int n,m,p,q,dp[maxn][maxn],k,s,r;
int a[N],b[N];
bool flag;
int main()
{
    scanf("%d%d",&n,&p);s=0;
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for (int i=1;i<=n;i++) s=(s+a[i])%p,b[i]=s;
    for (int i=1;i<=n;i++) if (b[i]>b[n]) flag=true;
    if (flag) cout << p+b[n] << endl; else cout << b[n] << endl;
    return 0;
}