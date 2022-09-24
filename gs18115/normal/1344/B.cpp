#include<iostream>
#include<vector>
#include<algorithm>
#define ep emplace
#define eb emplace_back
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
typedef pair<ll,ll>pl;
const int inf=1e9+7;
const ll INF=1e18+7;
const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};
bool chk[1010][1010];
char s[1010][1010];
void dfs(int x,int y)
{
    chk[x][y]=1;
    for(int k=0;k<4;k++)
    {
        int nx=x+dx[k];
        int ny=y+dy[k];
        if(s[nx][ny]=='#'&&!chk[nx][ny])
            dfs(nx,ny);
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int r,c;
    cin>>r>>c;
    for(int i=0;i++<r;)
        cin>>(s[i]+1);
    int nr=0,nc=0;
    for(int i=0;i++<r;)
    {
        bool f=0;
        for(int j=0;j++<c;)
        {
            if(s[i][j]=='#')
            {
                if(f&&s[i][j-1]!='#')
                    return cout<<-1<<endl,0;
                f=1;
            }
        }
        if(!f)
            nr++;
    }
    for(int j=0;j++<c;)
    {
        bool f=0;
        for(int i=0;i++<r;)
        {
            if(s[i][j]=='#')
            {
                if(f&&s[i-1][j]!='#')
                    return cout<<-1<<endl,0;
                f=1;
            }
        }
        if(!f)
            nc++;
    }
    if((nr!=0&&nc==0)||(nr==0&&nc!=0))
        return cout<<-1<<endl,0;
    int cnt=0;
    for(int i=0;i++<r;)
        for(int j=0;j++<c;)
            if(!chk[i][j]&&s[i][j]=='#')
                dfs(i,j),cnt++;
    cout<<cnt<<endl;
    return 0;
}