#include<bits/stdc++.h>
//#include<bits/extc++.h>
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> set_t;
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<double,double>
#define pb push_back
#define x first
#define y second
//#define sqr(x) ((x)*(x))
#define EPS 1e-7
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define Line pair<pii,pii> 
typedef long long LL;
#define hash Hash;
#define MXN 100005
char c[1005][1005];
queue<pii> q[10];
queue<pii> q2[10];
int main(){
    int n,m,p;
    scanf("%d %d %d",&n,&m,&p);
    int s[10];
    for(int i=1;i<=p;i++){
        scanf("%d",&s[i]);
        if(s[i]>=1000000)
        s[i]=1000000;
    }
    int X[4]={0,0,1,-1};
    int Y[4]={1,-1,0,0};
    int cnt=0;
    for(int i=1;i<=n;i++){
        scanf("%s",c[i]+1);
        for(int j=1;j<=m;j++){
            if(c[i][j]!='.'&&c[i][j]!='#'){
                q[c[i][j]-'0'].push(mp(i,j));
            }
            if(c[i][j]=='.')cnt++;
        }
    }
    while(cnt){
        int ok=0;
        for(int i=1;i<=p;i++){
            for(int j=0;j<s[i];j++){
                if(q[i].empty())break;
                while(!q[i].empty()){
                    pii p =q[i].front();
                    q[i].pop();
                    for(int d=0;d<4;d++){
                        int x=X[d]+p.x,y=Y[d]+p.y;
                        if(c[x][y]=='.'){
                            cnt--;
                            c[x][y]=i+'0';
                            q2[i].push(mp(x,y));
                        }
                    }
                }
                swap(q2[i],q[i]);
            }
            if(q[i].size())ok=1;
        }
        if(!ok)break;
    }
    int ans[10];
    MEM(ans);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(c[i][j]>='1'&&c[i][j]<='9')
                ans[c[i][j]-'0']++;
        }
    }
    for(int i=1;i<=p;i++)
    printf("%d ",ans[i]);
    printf("\n");
}