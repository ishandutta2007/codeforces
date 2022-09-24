#include<iostream>
#include<stack>
using namespace std;
typedef long long LL;
LL ncr[105][105];
LL eee[20];
LL F(const LL&X)
{
    /*LL ans=0;
    for(i=0;eee[i+1]<X;i++)
        ans+=ncr[i][2]*729+i*81+9;*/
    if(X<=0)
        return 0;
    LL Y=X;
    LL ans=0;
    stack<LL>stk;
    while(Y>0)
    {
        stk.push(Y%10);
        Y/=10;
    }
    LL T,t;
    LL cnt=stk.size();
    LL cnt2=3;
    while(cnt>0)
    {
        if(cnt2==0)
        {
            cnt2=-1;
            break;
        }
        T=stk.top();
        cnt--;
        if(T>0)
        {
            if(cnt2==3)
                ans+=ncr[cnt][3]*729+T*(ncr[cnt][2]*81+cnt*9+1)-1;
            else if(cnt2==2)
                ans+=ncr[cnt][2]*81+T*(cnt*9+1);
            else
                ans+=cnt*9+T;
            cnt2--;
        }
        stk.pop();
    }
    return ans+1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    LL T,i,j;
    LL L,R;
    cin>>T;
    ncr[0][0]=1;
    eee[0]=1;
    for(i=1;i<19;i++)
        eee[i]=eee[i-1]*10;
    for(i=0;i<100;i++)
    {
        ncr[i][0]=ncr[i][i]=1;
        for(j=1;j<i;j++)
            ncr[i][j]=ncr[i-1][j]+ncr[i-1][j-1];
    }
    while(T--)
    {
        cin>>L>>R;
        cout<<F(R)-F(L-1)<<'\n';
    }
    cout<<endl;
    return 0;
}