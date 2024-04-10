#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef pair<LL,LL>PL;
const LL MAXN=1010;
LL gcd(LL X,LL Y)
{
    return Y>0?gcd(Y,X%Y):X;
}
LL F(LL X)
{
    X<<=1;
    LL s,e,mid;
    s=1;
    e=X;
    while(s<e)
    {
        mid=s+e>>1;
        if(mid*mid<X)
            s=mid+1;
        else
            e=mid;
    }
    if(s*s>X)
        return s-1;
    else
        return s;
}
inline bool chk(LL x,LL X,LL t)
{
    return x<=t&&X>=t||x>=t&&X<=t;
}
map<PL,LL>M;
LL N,i,j;
LL X[MAXN],Y[MAXN],x[MAXN],y[MAXN];
LL t1,t2,t3;
LL xx,yy;
LL sum;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N;
    for(i=0;i<N;i++)
    {
        cin>>X[i]>>Y[i]>>x[i]>>y[i];
        if(X[i]<x[i])
        {
            swap(X[i],x[i]);
            swap(Y[i],y[i]);
        }
    }
    for(i=0;i<N;i++)
    {
        for(j=0;j<i;j++)
        {
            if((X[i]-x[i])*(Y[j]-y[j])==(X[j]-x[j])*(Y[i]-y[i]))
                continue;
            t1=(X[j]*y[j]-x[j]*Y[j])*(x[i]-X[i])-(x[j]-X[j])*(X[i]*y[i]-x[i]*Y[i]);
            t2=(Y[j]-y[j])*(X[i]*y[i]-x[i]*Y[i])-(X[j]*y[j]-x[j]*Y[j])*(Y[i]-y[i]);
            t3=(x[j]-X[j])*(Y[i]-y[i])-(x[i]-X[i])*(Y[j]-y[j]);
            if(t1%t3==0&&t2%t3==0)
            {
                xx=t1/t3;
                yy=t2/t3;
                if(chk(x[i],X[i],xx)&&chk(x[j],X[j],xx)&&chk(y[i],Y[i],yy)&&chk(y[j],Y[j],yy))
                    M[{xx,yy}]++;
            }
        }
    }
    for(i=0;i<N;i++)
        sum+=gcd(X[i]-x[i],abs(Y[i]-y[i]))+1;
    for(auto i:M)
        sum-=F(i.second);
    cout<<sum<<endl;
    return 0;
}