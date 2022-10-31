#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 1e3 + 10;

int n,m;
bool isp(int x)
{
    int i;
    for(i=2;i*i<=x;i++) if(!(x%i)) return false;
    return true;
}

int main()
{

    int i;
    scanf("%d",&n);m=n;
    for(m=n;;m++) if(isp(m)) break;

    printf("%d\n",m);
    for(i=1;i<=n;i++) printf("%d %d\n",i,i%n+1);
    for(;i<=m;i++)
    {
        printf("%d %d\n",i-n,i-(n>>1));
    }

    return 0;
}