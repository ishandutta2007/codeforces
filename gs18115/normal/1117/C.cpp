#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef pair<LL,LL>PL;
const LL INF=1e18;
inline LL Abs(LL x)
{
    if(x>0)
        return x;
    return -x;
}
inline LL dis(LL x,LL y,LL X,LL Y)
{
    return Abs(x-X)+Abs(y-Y);
}
LL x,y,X,Y,xd,yd,N,i,v,m,s,e,mid;
char c;
LL A[1234567],B[1234567];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>x>>y;
    cin>>X>>Y;
    cin>>N;
    for(i=1;i<=N;i++)
    {
        cin>>c;
        A[i]=A[i-1];
        B[i]=B[i-1];
        if(c=='R')
            A[i]++;
        else if(c=='L')
            A[i]--;
        else if(c=='U')
            B[i]++;
        else
            B[i]--;
    }
    if(x==X&&y==Y)
        return cout<<0<<endl,0;
    m=INF;
    for(i=0;i<N;i++)
    {
        s=0;
        e=2e9;
        x+=A[i];
        y+=B[i];
        if(dis(x+A[N]*e,y+B[N]*e,X,Y)>N*e+i)
            continue;
        while(s<e)
        {
            mid=s+e>>1;
            if(dis(x+A[N]*mid,y+B[N]*mid,X,Y)>N*mid+i)
                s=mid+1;
            else
                e=mid;
        }
        x-=A[i];
        y-=B[i];
        m=min(m,s*N+i);
    }
    if(m==INF)
        cout<<-1<<endl;
    else
        cout<<m<<endl;
    return 0;
}