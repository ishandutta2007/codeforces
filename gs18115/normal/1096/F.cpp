#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
const LL INF=1e18;
const LL MOD=998244353;
inline LL pow(LL X,LL Y)
{
    LL ans=1;
    for(LL i=1;i<=Y;i<<=1)
    {
        if(Y&i)
            ans=ans*X%MOD;
        X=X*X%MOD;
    }
    return ans;
}
inline LL inv(LL X)
{
    return pow(X,MOD-2);
}
LL FT1[1234567],FT2[1234567];
inline void FI1(LL i,LL dif)
{
    for(;i<=1048576;i+=i&-i)
        FT1[i]+=dif;
    return;
}
inline void FI2(LL i,LL dif)
{
    for(;i<=1048576;i+=i&-i)
        FT2[i]+=dif;
    return;
}
inline LL FS1(LL i)
{
    LL ans=0;
    for(;i>0;i=i&i-1)
        ans+=FT1[i];
    return ans%MOD;
}
inline LL FS2(LL i)
{
    LL ans=0;
    for(;i>0;i=i&i-1)
        ans+=FT2[i];
    return ans%MOD;
}
LL ans1,ans2,ans3;
LL N,i;
LL P[1234567];
bool chk[1234567];
LL cnt,cnt2;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N;
    for(i=0;i<N;i++)
    {
        cin>>P[i];
        if(P[i]!=-1)
            chk[P[i]]=true;
        else
            cnt++;
    }
    ans1=cnt*(cnt-1)/2%MOD*inv(2)%MOD;
    for(i=0;i<N;i++)
    {
        if(P[i]==-1)
            cnt2++;
        else
        {
            FI1(P[i],cnt-cnt2);
            FI2(P[i],cnt2);
        }
    }
    for(i=1;i<=N;i++)
        if(!chk[i])
            ans2=(ans2+FS1(1048576)-FS1(i)+FS2(i))%MOD;
    ans2=ans2*inv(cnt)%MOD;
    for(i=1;i<=1048576;i++)
        FT1[i]=FT2[i]=0;
    for(i=0;i<N;i++)
    {
        if(P[i]!=-1)
        {
            ans3+=FS1(1048576)-FS1(P[i]);
            FI1(P[i],1);
        }
    }
    cout<<(ans1+ans2+ans3+MOD)%MOD<<endl;
    return 0;
}