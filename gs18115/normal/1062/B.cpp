#include<iostream>
#include<vector>
using namespace std;
typedef long long LL;
const LL INF=1e18;
LL N,S,i,j,cnt,P,Q;
bool flag;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N;
    for(S=1,i=2;i<=N;i++)
    {
        if(N%i==0)
        {
            cnt=0;
            while(N%i==0)
            {
                cnt++;
                N/=i;
            }
            if(Q!=0&&cnt!=Q)
                flag=true;
            S*=i;
            for(j=0;1<<j<cnt;j++);
            if(1<<j!=cnt)
                flag=true;
            P=max(P,j);
            Q=cnt;
        }
    }
    cout<<S<<' '<<P+(flag?1:0)<<endl;
    return 0;
}