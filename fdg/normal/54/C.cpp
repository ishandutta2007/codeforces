#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <memory.h>
#include <ctime>
#include <set>
#include <cmath>

#define ll unsigned long long

using namespace std;

vector <ll> rec(ll n)
{
    vector <ll> ans(10,0);
    if (n<10)
    {
        for(int i=1;i<=n;i++)
            ans[i]++;
        return ans;
    }
    for(int i=1;i<=9;i++)
        ans[i]++;
    ll step=10,cur=9,num=1;
    while(cur<n)
    {
        if (cur+step<=n)
        {
            ans[num]+=step;
            cur+=step;
        }
        else
        {
            ans[num]+=n-cur;
            break;
        }
        num++;
        if (num==10)
        {
            step*=10;
            num=1;
        }
    }
    return ans;
}

double dp[1005][1005]={0};

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    ll n,k;
    cin >> n;
    vector < vector <ll> > v(n);
    vector <ll> l(n),r(n);
    for(int i=0;i<n;i++)
    {
        cin >> l[i] >> r[i];
        v[i]=rec(r[i]);
        vector <ll> tmp=rec(l[i]-1);
        for(int j=1;j<tmp.size();j++)
            v[i][j]-=tmp[j];
    }
    cin >> k;
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
            dp[i][j]=0.0;
    dp[0][0]=1.0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            double ver=((double)v[i][1])/(r[i]-l[i]+1);
            dp[i+1][j]+=dp[i][j]*(1-ver);
            dp[i+1][j+1]+=dp[i][j]*ver;
        }
    }
    double ans=0,val=double(n*k)/100.0;
    int e=val;
    if (fabs(val-e)>1e-7) e++;
    for(int i=e;i<=n;i++)
        ans+=dp[n][i];
    printf("%.9lf\n",ans);
    return 0;
}