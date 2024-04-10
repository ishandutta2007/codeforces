#include<iostream>
using namespace std;
typedef long long LL;
const LL MOD=1e9+7;
const LL MAXN=2e5+10;
const LL n=262144;
LL N,Q,i;
LL P[MAXN],W[MAXN];
LL FT1[n+5],FT2[n+5],FT3[n+5];
LL s,e,mid,ss,es,S;
LL X,Y;
inline void add(LL&X,const LL&diff)
{
    X=(X+diff)%MOD;
    if(X<0)
        X+=MOD;
    return;
}
inline void FI1(LL I,const LL diff)
{
    if(I<=0)
        return;
    for(;I<=n;I+=I&-I)
        add(FT1[I],diff);
    return;
}
inline void FI2(LL I,const LL diff)
{
    if(I<=0)
        return;
    for(;I<=n;I+=I&-I)
        add(FT2[I],diff);
    return;
}
inline void FI3(LL I,const LL diff)
{
    if(I<=0)
        return;
    for(;I<=n;I+=I&-I)
        FT3[I]+=diff;
    return;
}
inline LL FS1(LL I)
{
    LL sum=0;
    for(;I>0;I=I&I-1)
        add(sum,FT1[I]);
    return sum;
}
inline LL FS2(LL I)
{
    LL sum=0;
    for(;I>0;I=I&I-1)
        add(sum,FT2[I]);
    return sum;
}
inline LL FS3(LL I)
{
    LL sum=0;
    for(;I>0;I=I&I-1)
        sum+=FT3[I];
    return sum;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N>>Q;
    for(i=0;i<N;i++)
    {
        cin>>P[i];
        P[i]-=i;
    }
    P[N]=P[N-1];
    for(i=0;i<N;i++)
    {
        cin>>W[i];
        FI1(i+1,W[i]*(P[i]-P[0]));
        FI2(N-i,W[i]*(P[N]-P[i]));
        FI3(i+1,W[i]);
    }
    while(Q--)
    {
        cin>>X>>Y;
        if(X<0)
        {
            X=-X-1;
            FI1(X+1,(Y-W[X])*(P[X]-P[0]));
            FI2(N-X,(Y-W[X])*(P[N]-P[X]));
            FI3(X+1,Y-W[X]);
            W[X]=Y;
        }
        else
        {
            s=--X;
            e=--Y;
            ss=FS3(X);
            es=FS3(Y+1);
            while(s<e)
            {
                mid=s+e>>1;
                S=FS3(mid+1);
                if(S-ss<es-S)
                    s=mid+1;
                else
                    e=mid;
            }
            ss%=MOD;
            es%=MOD;
            S=FS3(s+1)%MOD;
            S=((S-ss)*(P[s]-P[0])+(es-S)*(P[N]-P[s])+FS1(X)+FS2(N-Y-1)-FS1(s+1)-FS2(N-s-1))%MOD;
            if(S<0)
                S+=MOD;
            cout<<S<<'\n';
        }
    }
    cout<<endl;
    return 0;
}