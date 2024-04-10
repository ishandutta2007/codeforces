#include<bits/stdc++.h>
#define maxn 203490

using namespace std;
typedef pair<double,double> pi;
vector<pi> a[maxn];
double x[maxn],y[maxn],l,r,m;
int c[maxn];
pi p;
int n,cnt[maxn];
double d;

int main()
{
    scanf("%d%lf",&n,&d);
    for (int i=1;i<=n;i++) scanf("%d",&c[i]);
    for (int i=1;i<=n;i++) x[i]=1.0*c[i];
    for (int i=1;i<=1000;i++)
    {
        cnt[i]=1;
        p.first=0; p.second=d;
        a[i].push_back(p);
    }
    for (int i=1;i<=n;i++)
    {
        int w=c[i];
        sort(a[w].begin(),a[w].begin()+cnt[w]);
        l=0.0;r=a[w][0].second;int j=1;
        while (j<cnt[w])
        {
            if (a[w][j].first>r) break;
            else r=max(r,a[w][j].second);
            j++;
        }
        y[i]=r;
        for (int j=1;j<=1000;j++)
        if (abs(j-w)<=d*2){
            m=sqrt(d*d*4.0-(j-w)*(j-w));
            p.first=0;
            p.second=y[i]+m;
            a[j].push_back(p); cnt[j]++;
        }
    }
    for (int i=1;i<=n;i++)printf("%.7f ",y[i]);printf("\n");
    return 0;
}