#include<iostream>
#include<vector>
#include<bitset>
#include<algorithm>
using namespace std;
typedef long long LL;
const LL INF=1e18;
const LL MAXN=1e5+10;
bitset<7005>S[MAXN];
bitset<7005>P[7005],Q[7005];
bitset<7005>t;
LL type,T,i,j,x;
bool chk[7005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for(i=2;i*i<=7000;i++)
        chk[i*i]=true;
    for(i=1;i<=7000;i++)
        if(chk[i])
            for(j=i*2;j<=7000;j+=i)
                chk[j]=true;
    for(i=1;i<=7000;i++)
        for(j=1;j<=7000;j++)
            if(i%j==0)
                P[i][j]=true;
    for(i=1;i<=7000;i++)
        for(j=1;i*j<=7000;j++)
            if(!chk[j])
                Q[i][i*j]=true;
    cin>>type>>T;
    while(T-->0)
    {
        cin>>type>>i>>j;
        if(type==1)
            S[i]=P[j];
        else if(type==2)
        {
            cin>>x;
            S[i]=S[j]^S[x];
        }
        else if(type==3)
        {
            cin>>x;
            S[i]=S[j]&S[x];
        }
        else
        {
            t=S[i]&Q[j];
            cout<<(t.count()&1);
        }
    }
    cout<<endl;
    return 0;
}