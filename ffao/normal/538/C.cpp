#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stdio.h>
#include <string.h>
#include <map>
#include <math.h>
#include <algorithm>
using namespace std;

#define gc getchar
#define MOD 1000000007
#define pc(x) putchar(x);
#define pi(n) printf("%d",n)
#define pin(n) printf("%d\n",n)
#define pis(n) printf("%d ",n)
#define pll(n) printf("%lld",n)
#define plls(n) printf("%lld ",n)
#define ps printf(" ")
#define pn printf("\n")
#define rep(i,n) for(i=0;i<n;i++)
#define fu(i,a,n) for(i=a;i<=n;i++)
#define fd(i,n,a) for(i=n;i>=a;i--)
#define INV 333333336
#define ll long long
#define EPS 1e-9
#define infi 2000000000

inline ll sn()
{
    ll n=0;
    ll ch=gc();
    while( ch <48 )ch=gc();
    while( ch >47 )
    n = (n<<3)+(n<<1) + ch-'0', ch=gc();
        return n;
}


int main()
{
    int i,j,n,m;
    n=sn();
    m=sn();
    vector<int> index(m);
    vector<int> hei(m);
    rep(i,m)
    {
        index[i]=sn();
        hei[i]=sn();
    }
    int maxi=0;
    maxi=index[0]-1+hei[0];
    //pin(maxi);
    fu(i,1,m-1)
    {
        index[i]-index[i-1];
        if(abs(hei[i]-hei[i-1]) > index[i]-index[i-1])
        {
            printf("IMPOSSIBLE\n");
            return 0;
        }
        if(hei[i]<hei[i-1])
        {
            int k=index[i]-(hei[i-1]-hei[i]);
            int ans=hei[i-1]+(k-index[i-1])/2;
            //pin(ans);
            maxi=max(maxi,ans);
        }
        else
        {
            int k=index[i]-(hei[i]-hei[i-1]);
            int ans=hei[i]+(k-index[i-1])/2;
            //pin(ans);
            maxi=max(maxi,ans);
        }
    }
    int ans=n-index[m-1]+hei[m-1];
    //pin(ans);
    maxi=max(maxi,ans);
    pin(maxi);
    return 0;
}