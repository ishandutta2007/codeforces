#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
typedef long long LL;
const LL MOD=998244353;
inline void Z(char*S,const LL&Slen,char*P,const LL&Plen,char*T,vector<LL>&mt)
{
    mt.resize(Slen+Plen);
    LL i;
    for(i=0;i<Plen;i++)
        T[i]=P[i];
    for(i=0;i<Slen;i++)
        T[Plen+i]=S[i];
    mt[0]=Slen+Plen;
    LL l,r;
    l=r=0;
    for(i=1;i<Slen+Plen;i++)
    {
        if(i<r)
            mt[i]=min(r-i,mt[i-l]);
        else
            mt[i]=0;
        while(i+mt[i]<Slen+Plen&&T[mt[i]]==T[i+mt[i]])
            mt[i]++;
        if(i+mt[i]>r)
        {
            r=i+mt[i];
            l=i;
        }
    }
    for(i=0;i<Slen;i++)
        mt[i]=min(Plen,mt[i+Plen]);
    mt.erase(mt.begin()+Slen,mt.end());
    return;
}
LL FT[1234567];
char A[1234567],L[1234567],R[1234567],T[2345678];
vector<LL>Lmt,Rmt;
LL Al,Ll,Rl;
LL i,j;
LL mini,maxi;
LL S;
LL X[1234567];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>A;
    cin>>L;
    cin>>R;
    Al=strlen(A);
    Ll=strlen(L);
    Rl=strlen(R);
    Z(A,Al,L,Ll,T,Lmt);
    Z(A,Al,R,Rl,T,Rmt);
    X[0]=1;
    X[1]=MOD-1;
    for(i=0;i<Al;i++)
    {
        S=(S+X[i])%MOD;
        mini=Lmt[i]==Ll||A[i+Lmt[i]]>L[Lmt[i]]?Ll:Ll+1;
        if(i+mini>Al)
            continue;
        if(A[i]=='0')
            maxi=2;
        else
            maxi=Rmt[i]==Rl||A[i+Rmt[i]]<R[Rmt[i]]?Rl+1:Rl;
        maxi=min(Al+5-i,maxi);
        if(mini<maxi)
        {
            X[i+mini]=(X[i+mini]+S)%MOD;
            X[i+maxi]=(X[i+maxi]-S+MOD)%MOD;
        }
    }
    cout<<(S+X[Al])%MOD<<endl;
    return 0;
}