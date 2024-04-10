#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
typedef long long LL;
typedef long double LD;
const LL MAXN=1e5+10;
const LD INF=1e18;
LL N,NP,NM;
LL i;
LL X[MAXN],Y[MAXN];
LD s,e,R,xmin,xmax,x,y,T;
inline bool equals(LD p,LD q)
{
    if(abs(p-q)<1e-9)
        return true;
    if(abs(p)<1e-9||abs(q)<1e-9)
        return false;
    return abs((p-q)/p)<1e-9;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N;
    for(i=0;i<N;i++)
    {
        cin>>X[i]>>Y[i];
        if(Y[i]>0)
            NP++;
        else
        {
            NM++;
            Y[i]=-Y[i];
        }
    }
    if(NP>0&&NM>0)
        return cout<<-1<<endl,0;
    s=0;
    e=1e20;
    while(!equals(s,e))
    {
        R=(s+e)/(LD)2.0;
        xmin=-INF;
        xmax=INF;
        for(i=0;i<N;i++)
        {
            x=(LD)X[i];
            y=(LD)Y[i];
            if(y>R*2)
            {
                xmax=-INF;
                xmin=INF;
                break;
            }
            T=sqrt(y*(2*R-y));
            xmin=max(xmin,x-T);
            xmax=min(xmax,x+T);
        }
        if(xmin<xmax)
            e=R;
        else
            s=R;
    }
    cout<<fixed<<setprecision(12)<<s<<endl;
    return 0;
}