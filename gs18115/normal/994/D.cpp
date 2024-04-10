#include<iostream>
#include<algorithm>
#include<vector>
#define FI first
#define SE second
#define MP make_pair
#define PB push_back
using namespace std;
typedef long long LL;
typedef pair<LL,LL>PL;
typedef vector<LL>VL;
PL a[23],b[23];
int N,M,i,j,L,m,C;
bool chk[12];
int max(int X,int Y)
{
    return X>Y?X:Y;
}
int CNT(PL X,PL Y)
{
    int cnt1=0,cnt2=0;
    cnt1+=(X.FI==Y.FI);
    cnt1+=(X.SE==Y.SE);
    cnt1+=(X.FI==Y.SE);
    cnt1+=(X.SE==Y.FI);
    return max(cnt1,cnt2);
}
int B(PL X,PL Y)
{
    if(X.FI==Y.FI||X.FI==Y.SE)
        return X.FI;
    return X.SE;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N>>M;
    for(i=0;i<N;i++)
        cin>>a[i].FI>>a[i].SE;
    for(i=0;i<M;i++)
        cin>>b[i].FI>>b[i].SE;
    for(i=0;i<N;i++)
        for(j=0;j<M;j++)
            if(CNT(a[i],b[j])==1)
                chk[B(a[i],b[j])]=true;
    for(i=1;i<10;i++)
    {
        if(chk[i])
        {
            C++;
            m=i;
        }
    }
    if(C==1)
        cout<<m;
    else
    {
        for(i=0;i<N;i++)
        {
            C=0;
            for(j=1;j<10;j++)
                chk[j]=false;
            for(j=0;j<M;j++)
            {
                if(CNT(a[i],b[j])==1)
                    chk[B(a[i],b[j])]=true;
            }
            for(j=1;j<10;j++)
                if(chk[j])
                    C++;
            if(C>1)
            {
                cout<<-1;
                return 0;
            }
        }
        for(j=0;j<M;j++)
        {
            C=0;
            for(i=1;i<10;i++)
                chk[i]=false;
            for(i=0;i<N;i++)
            {
                if(CNT(a[i],b[j])==1)
                    chk[B(a[i],b[j])]=true;
            }
            for(i=1;i<10;i++)
                if(chk[i])
                    C++;
            if(C>1)
            {
                cout<<-1;
                return 0;
            }
        }
        cout<<0;
    }
    return 0;
}