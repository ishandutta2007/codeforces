#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>

#define ll long long

using namespace std;

int x[102]={0},y[102]={0};
double m_e=2.7182818284590452353602874713527;

double dist(double x1,double y1,double x2,double y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,X0,Y0;
    int K,E;
    cin >> n >> K >> E >> X0 >> Y0;
    for(int i=0;i<n;i++)
        cin >> x[i] >> y[i];
    double l=0,r=100000;
    for(int t=0;t<400;t++)
    {
        double m=(l+r)/2;
        double kol=0;
        double dp[103]={0},dp1[103]={0};
        dp[0]=1.0;
        for(int j=0;j<n;j++)
        {
            double k=dist(X0,Y0,x[j],y[j]),ver=0;
            if (k<=m+1e-7) ver=1;
            else ver=pow(m_e,1.0-(k*k)/(m*m));
            for(int i=0;i<=n;i++)
            {
                dp1[i]+=dp[i]*(1.0-ver);
                dp1[i+1]+=dp[i]*ver;
            }
            for(int i=0;i<=n;i++)
            {
                dp[i]=dp1[i];
                dp1[i]=0.0;
            }
        }
        double s=0;
        for(int i=K;i<=n;i++)
            s+=dp[i];
        if ((1.0-s)*1000.0<=(double)E) r=m;
        else l=m;
    }
    cout.precision(20);
    cout << l << endl;
    return 0;
}