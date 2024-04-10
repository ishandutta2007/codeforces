#include<iostream>
using namespace std;
typedef long long LL;
LL popcount(LL X)
{
    LL cnt=0;
    for(LL i=0;i<62;i++)
        if(X&(1LL<<i))
            cnt++;
    return cnt;
}
LL N,i,j,A,p,sum,m;
LL P[345678],S[345678];
LL ss[2][345678];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N;
    ss[0][0]=1;
    for(i=1;i<=N;i++)
    {
        cin>>A;
        P[i]=popcount(A);
        S[i]=S[i-1LL]+P[i];
        ss[0][i]=ss[0][i-1LL];
        ss[1][i]=ss[1][i-1LL];
        ss[S[i]&1LL][i]++;
        m=P[i];
        for(j=i-1LL;j>=0LL&&j>i-66LL;j--)
        {
            if(((S[i]-S[j])&1LL)==0LL)
                if(S[i]-S[j]>=m*2LL)
                    sum++;
            m=max(m,P[j]);
        }
        if(i>=66LL)
            sum+=ss[S[i]&1LL][i-66LL];
    }
    cout<<sum<<endl;
    return 0;
}