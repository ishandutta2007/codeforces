#include<bits/stdc++.h>
#define maxn 230402

using namespace std;
typedef long long ll;

ll n,m,k,d;

int main()
{
    scanf("%d%d",&n,&m);
    if (n>30) printf("%d\n",m);
    else printf("%d\n",m%(1<<n));
    return 0;
}