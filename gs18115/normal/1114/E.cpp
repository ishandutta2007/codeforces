#include<iostream>
#include<vector>
#include<time.h>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef pair<LL,LL>PL;
const LL INF=1e9+1;
LL cnt;
inline bool q1(LL x)
{
    cnt++;
    cout<<"> "<<x<<endl;
    LL ret;
    cin>>ret;
    if(ret==-1)
        exit(0);
    return ret>0;
}
inline LL q2(LL i)
{
    cnt++;
    cout<<"? "<<i+1<<endl;
    LL ret;
    cin>>ret;
    if(ret==-1)
        exit(0);
    return ret;
}
inline void answer(LL x,LL d)
{
    cout<<"! "<<x<<' '<<d<<endl;
    return;
}
inline LL gcd(LL x,LL y)
{
    if(x==0)
        return y;
    if(y==0)
        return x;
    return abs(__gcd(abs(x),abs(y)));
}
LL s,e,i,g,N;
bool chk[1234567];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(NULL));
    for(s=0;s<10000;s++)
        srand(time(NULL)+rand());
    cin>>N;
    s=0;
    e=INF;
    while(s<e)
    {
        i=s+e>>1;
        if(q1(i))
            s=i+1;
        else
            e=i;
    }
    g=0;
    if(N<50)
    {
        for(i=0;i<N&&cnt<60;i++)
            g=gcd(g,s-q2(i));
        answer(s-g*(N-1),g);
        return 0;
    }
    while(cnt<60)
    {
        i=rand()*(LL)rand()%N;
        if(chk[i])
            continue;
        chk[i]=true;
        g=gcd(g,s-q2(i));
    }
    answer(s-g*(N-1),g);
    return 0;
}