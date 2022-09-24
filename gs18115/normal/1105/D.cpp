#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef pair<LL,LL>PL;
const LL INF=1e18;
const LL di[4]={1,0,-1,0};
const LL dj[4]={0,1,0,-1};
LL N,M,P;
LL S[12],cnt[12];
char T[1234][1234];
LL i,j,t,hi,hj,ti,tj;
LL D[1234][1234];
queue<PL>Q[12];
bool flag;
inline bool chk(LL X,LL Y)
{
    return X>=0&&Y>=0&&X<N&&Y<M;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N>>M>>P;
    for(i=0;i<P;i++)
        cin>>S[i];
    for(i=0;i<N;i++)
    {
        for(j=0;j<M;j++)
        {
            cin>>T[i][j];
            if(T[i][j]!='.'&&T[i][j]!='#')
                Q[T[i][j]-'1'].emplace(i,j);
        }
    }
    flag=true;
    while(flag)
    {
        flag=false;
        t++;
        for(i=0;i<P;i++)
        {
            while(!Q[i].empty())
            {
                hi=Q[i].front().first;
                hj=Q[i].front().second;
                if(D[hi][hj]>=S[i]*t)
                    break;
                Q[i].pop();
                for(j=0;j<4;j++)
                {
                    ti=hi+di[j];
                    tj=hj+dj[j];
                    if(!chk(ti,tj))
                        continue;
                    if(T[ti][tj]!='.')
                        continue;
                    T[ti][tj]=i+'1';
                    D[ti][tj]=D[hi][hj]+1;
                    flag=true;
                    Q[i].emplace(ti,tj);
                }
            }
        }
    }
    for(i=0;i<N;i++)
        for(j=0;j<M;j++)
            if(T[i][j]!='.'&&T[i][j]!='#')
                cnt[T[i][j]-'1']++;
    for(i=0;i<P;i++)
        cout<<cnt[i]<<' ';
    cout<<endl;
    return 0;
}