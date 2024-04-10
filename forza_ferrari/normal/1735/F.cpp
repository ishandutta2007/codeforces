#include<iostream>
#include<cstdio>
#include<set>
#include<cmath>
using namespace std;
int t,n;
double x[300001],y[300001],lx,rx,ly,ry;
multiset<pair<double,double> > s;
inline int read()
{
    int x=0;
    char c=getchar();
    while(c<'0'||c>'9')
        c=getchar();
    while(c>='0'&&c<='9')
    {
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    return x;
}
int main()
{
    t=read();
    while(t--)
    {
        n=read(),lx=rx=read(),ly=ry=read();
        for(int i=1;i<=n;++i)
            x[i]=read();
        for(int i=1;i<=n;++i)
            y[i]=read();
        if(fabs(lx+ly)<1e-8)
        {
            while(n--)
                cout<<"0\n";
            continue;
        }
        s.clear();
        for(int i=1;i<=n;++i)
        {
            lx-=x[i],rx+=x[i];
            ly+=y[i],ry-=y[i];
            s.emplace(y[i]/x[i],x[i]+x[i]);
            while(lx<-1e-8)
            {
                pair<double,double> tmp=*s.begin();
                s.erase(s.begin());
                if(lx+tmp.second>0)
                {
                    s.emplace(tmp.first,lx+tmp.second);
                    tmp.second=-lx;
                }
                lx+=tmp.second;
                ly-=tmp.first*tmp.second;
            }
            while(ry<-1e-8)
            {
                pair<double,double> tmp=*--s.end();
                s.erase(--s.end());
                if(ry+tmp.first*tmp.second>0)
                {
                    s.emplace(tmp.first,ry/tmp.first+tmp.second);
                    tmp.second=-ry/tmp.first;
                }
                rx-=tmp.second;
                ry+=tmp.first*tmp.second;
            }
            printf("%.10lf\n",rx);
        }
    }
    return 0;
}