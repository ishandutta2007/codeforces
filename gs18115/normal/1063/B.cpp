#include<iostream>
#include<queue>
using namespace std;
typedef long long LL;
typedef pair<LL,LL>PL;
const LL INF=1e18;
const LL MAXN=2010;
char S[MAXN][MAXN];
bool vis[MAXN][MAXN];
LL VIS[MAXN][MAXN];
queue<pair<PL,PL> >Q;
LL X,Y;
LL N,M,R,C;
LL i,j;
LL cnt;
LL x,y,r,c;
inline void qpush(LL x,LL y,LL r,LL c)
{
    vis[x][y]=true;
    VIS[x][y]=r;
    Q.push({{x,y},{r,c}});
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N>>M;
    cin>>R>>C;
    cin>>X>>Y;
    for(i=1;i<=N;i++)
        cin>>S[i]+1;
    for(i=0;i<MAXN;i++)
        fill(VIS[i],VIS[i]+MAXN,INF);
    qpush(R,C,0LL,0LL);
    while(!Q.empty())
    {
        r=Q.front().first.first;
        c=Q.front().first.second;
        x=Q.front().second.first;
        y=Q.front().second.second;
        Q.pop();
        if(x!=VIS[r][c])
            continue;
        if((!vis[r+1][c]||VIS[r+1][c]>x)&&S[r+1][c]=='.')
            qpush(r+1,c,x,y);
        if((!vis[r-1][c]||VIS[r-1][c]>x)&&S[r-1][c]=='.')
            qpush(r-1,c,x,y);
        if((!vis[r][c+1]||VIS[r][c+1]>x)&&S[r][c+1]=='.'&&y<Y)
            qpush(r,c+1,x,y+1);
        if((!vis[r][c-1]||VIS[r][c-1]>x+1)&&S[r][c-1]=='.'&&x<X)
            qpush(r,c-1,x+1,y);
    }
    for(i=1;i<=N;i++)
        for(j=1;j<=M;j++)
            if(vis[i][j])
                cnt++;
    cout<<cnt<<endl;
    return 0;
}