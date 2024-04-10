#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

#define ll long long

const double Pi=3.1415926535897932384626;

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n;
    double x1[101]={0},y1[101]={0},x2[101]={0},y2[101]={0};
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
        if (x1[i]>x2[i]) swap(x1[i],x2[i]);
        if (y1[i]>y2[i]) swap(y1[i],y2[i]);
    }
    int i;
    double xl=x1[0],yl=y1[0],xr=x2[0],yr=y2[0];
    for(i=1;i<n;i++)
    {
        bool poss=true;
        double m=(x2[i]-x1[i])*(x2[i]-x1[i])*(x2[i]-x1[i]),cx=(x1[i]+x2[i])/2,cy=(y1[i]+y2[i])/2;
        for(int j=i-1;j>=0;j--)
        {
            if (x1[j]<=cx&&cx<=x2[j]&&y1[j]<=cy&&cy<=y2[j])
            {
                cx=((x2[j]-x1[j])*(x2[j]-x1[j])*(x2[j]-x1[j])*(x1[j]+x2[j])/2+m*cx)/((x2[j]-x1[j])*(x2[j]-x1[j])*(x2[j]-x1[j])+m);
                cy=((x2[j]-x1[j])*(x2[j]-x1[j])*(x2[j]-x1[j])*(y1[j]+y2[j])/2+m*cy)/((x2[j]-x1[j])*(x2[j]-x1[j])*(x2[j]-x1[j])+m);
                m+=(x2[j]-x1[j])*(x2[j]-x1[j])*(x2[j]-x1[j]);
            }
            else
            {
                poss=false;
                break;
            }
        }
        if (!poss) break;
/*      double cx=(x1[i]+x2[i])/2,cy=(y1[i]+y2[i])/2;
        if (xl<=cx&&cx<=xr&&yl<=cy&&cy<=yr)
        {
            double a,b,c,d;
            a=max(xl,x1[i]);
            b=min(xr,x2[i]);
            xl=a; xr=b;
            c=max(yl,y1[i]);
            d=min(yr,y2[i]);
            yl=c; yr=d;
        }
        else
        {
            break;
        }*/
    }
    cout << i << endl;
    return 0;
}