#include<cmath>
#include<set>
#include<cstdio>
#include<vector>
#include<queue>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define maxn 200020
#define inf 1000000020

using namespace std;
typedef long long ll;

ll n,m,a,b,f,t,k;

int main()
{
    scanf("%d%d%d%d",&a,&b,&f,&n);
    t=b-f;
    if (t<0) {printf("-1\n");return 0;}
    m=0;
    for (int i=0;i<n;i++)
    {
        if (i%2==0) k=a-f; else k=f;
        if (i==n-1) {
            if (t<k) t=b,m++;
            if (t<k) {printf("-1\n");return 0;}
            t-=k;
        }
        else{
            if (t<2*k) t=b,m++;
            if (t<2*k) {printf("-1\n");return 0;}
            t-=2*k;
        }
    }
    printf("%d\n",m);
    return 0;
}