#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef pair<LL,LL>PL;
const LL INF=1e18;
LL i,j,Ns,Nt;
LL c[2];
LL P[1234567];
char S[1234567],T[1234567],ans[1234567];
inline void Z()
{
    LL l=-1,r=-1;
    for(i=1;i<Nt;i++)
    {
        P[i]=-1;
        if(i<=r)
            P[i]=min(r-i,P[i-l]);
        while(i+P[i]+1<Nt&&T[i+P[i]+1]==T[P[i]+1])
            P[i]++;
        if(r<i+P[i])
            r=i+P[i],l=i;
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>S;
    cin>>T;
    Ns=strlen(S);
    Nt=strlen(T);
    Z();
    for(i=1;i<Nt;i++)
        if(i+P[i]==Nt-1)
            break;
    Nt=i;
    for(i=0;i<Ns;i++)
        c[S[i]-'0']++;
    for(i=j=0;i<Ns;i++)
    {
        if(c[0]==0)
            ans[i]='1';
        else if(c[1]==0)
            ans[i]='0';
        else
            ans[i]=T[j];
        c[ans[i]-'0']--;
        j++;
        if(j>=Nt)
            j-=Nt;
    }
    cout<<ans<<endl;
    return 0;
}