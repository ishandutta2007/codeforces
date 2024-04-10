#include<iostream>
#include<vector>
#include<time.h>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef pair<LL,LL>PL;
const LL INF=1e18;
char S[10];
bool query(LL l,LL r)
{
    cout<<l<<' '<<r<<endl;
    cin>>S;
    return S[0]=='Y';
}
LL N,K,i,s,e,m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for(i=0;i<3000;i++)
        srand(time(0)+rand());
    cin>>N>>K;
    s=1;
    e=N;
    while(true)
    {
        while(e-s>60)
        {
            m=s+e>>1;
            if(query(s,m))
                e=m;
            else
                s=m+1;
            s-=K;
            e+=K;
            s=max(s,1LL);
            e=min(e,N);
        }
        m=s+rand()%(e-s+1);
        if(query(m,m))
           return 0;
        s-=K;
        e+=K;
        s=max(s,1LL);
        e=min(e,N);
    }
    return 0;
}