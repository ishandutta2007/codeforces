#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pi;
const int maxn=211;
ll ans;
int a[maxn][maxn],n,pre[maxn][maxn],px,py;
struct node{
    int x,y,val;
};
vector<node> res;
bool cmp(node u,node v){return u.val<v.val;}
int l[maxn][maxn],r[maxn][maxn],u[maxn][maxn],d[maxn][maxn],ok[maxn][maxn];
//0 x++
//1 x--
//2 y++
//3 y--
bool valid(int x,int y){
    return x>=1&&x<=n&&y>=1&&y<=n&&pre[x][y]==-1&&a[x][y]!=-1;
}
void bfs(int sx,int sy){
    queue<pi> que;
    que.push((pi){sx,sy});
    memset(pre,-1,sizeof(pre));
    pre[sx][sy]=0;
    while (!que.empty()){
        pi tmp=que.front(); que.pop();
        int x=tmp.F,y=tmp.S;
        if (ok[x][y]){
            if (px==-1||a[px][py]<a[x][y]) px=x,py=y;
        }
        if (valid(x-1,y)&&u[x][y]){
            pre[x-1][y]=0;
            que.push((pi){x-1,y});
        }
        if (valid(x+1,y)&&d[x][y]){
            pre[x+1][y]=1;
            que.push((pi){x+1,y});
        }
        if (valid(x,y-1)&&l[x][y]){
            pre[x][y-1]=2;
            que.push((pi){x,y-1});
        }
        if (valid(x,y+1)&&r[x][y]){
            pre[x][y+1]=3;
            que.push((pi){x,y+1});
        }
    }
}
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
            if ((i==1)+(j==1)+(i==n)+(j==n)==1) ok[i][j]=1,res.pb((node){i,j,a[i][j]});
        }
    for (int i=1;i<n;i++) {
        ans+=abs(a[1][i]-a[1][i+1])+abs(a[n][i]-a[n][i+1]);
        ans+=abs(a[i][1]-a[i+1][1])+abs(a[i][n]-a[i+1][n]);
    }
    for (int i=2;i<n;i++)
        for (int j=1;j<n;j++)
            l[i][j+1]=r[i][j]=1,u[j+1][i]=d[j][i]=1;
    sort(res.begin(),res.end(),cmp);
    for (auto p:res){
        px=py=-1; ok[p.x][p.y]=0;
        bfs(p.x,p.y);
        if (px!=-1){
            ans+=a[px][py]-a[p.x][p.y];
            while (px!=p.x||py!=p.y){
                int op=pre[px][py];
                if (op==0){
                    d[px][py]++;
                    px++;
                    u[px][py]--;
                } else if (op==1){
                    u[px][py]++;
                    px--;
                    d[px][py]--;
                } else if (op==2){
                    r[px][py]++;
                    py++;
                    l[px][py]--;
                } else {
                    l[px][py]++;
                    py--;
                    r[px][py]--;
                }
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}