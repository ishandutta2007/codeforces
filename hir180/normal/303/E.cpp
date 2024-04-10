#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define dd double
dd ans[85][85]={},s,ma[85],mi[85],a[165][85],b[165][85],c[165][85],d[165][85],e[165][85];
bool in[165][85]={},up[165][85]={},low[165][85]={};
int main()
{
    int n;
    vector<dd>vec;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lf %lf",&mi[i],&ma[i]);
        vec.push_back(ma[i]);
        vec.push_back(mi[i]);
    }
    sort(vec.begin(),vec.end());
    vec.erase(unique(vec.begin(),vec.end()),vec.end());
    for(int i=1;i<vec.size();i++)
    {
        for(int k=1;k<=n;k++)
        {
            d[i][k]=ma[k]-mi[k];
            a[i][k]=max(0.0,min(ma[k],vec[i-1])-mi[k])/d[i][k];
            b[i][k]=max(0.0,ma[k]-max(mi[k],vec[i]))/d[i][k];
            c[i][k]=max(0.0,min(vec[i],ma[k])-max(vec[i-1],mi[k]))/d[i][k];
            e[i][k]=(vec[i]-vec[i-1]) / (ma[k]-mi[k]);
            if(c[i][k]>0) in[i][k]=true;
            if(a[i][k]==1.0) low[i][k]=true;
            if(b[i][k]==1.0) up[i][k]=true;
        }
    }
    for(int j=1;j<=n;j++)
    {
        for(int i=1;i<vec.size();i++)
        {
            if(in[i][j])
            {
                static dd dp[85][85][85]={};
                dp[0][1][0]=1.0;
                int q=0;
                int g=0;
                for(int k=1;k<=n;k++)
                {
                    if(up[i][k]) g++;
                    else if(low[i][k]);
                    else if(j!=k)
                    {
                        q++;
                        for(int r1=k+1;r1>=1;r1--) for(int r2=k+1-r1;r2>=0;r2--)
                        {
                            dp[q][r1][r2]=(dp[q-1][r1-1][r2]*b[i][k] + (r2?dp[q-1][r1][r2-1]*c[i][k]:s) + dp[q-1][r1][r2]*a[i][k]);
                        }
                    }
                }
                for(int r1=0;r1<=n;r1++) for(int r2=0;r2<=n-r1;r2++) for(int r3=0;r3<=r2;r3++)
                {
                    ans[j][r1+r3+g] += dp[q][r1][r2] / ((dd)r2+1.0) * e[i][j];
                }
            }
        }
        for(int jf=n;jf>=1;jf--)
        {
            printf("%.8lf ",ans[j][jf]);
        }
        puts("");
    }
    return 0;
}