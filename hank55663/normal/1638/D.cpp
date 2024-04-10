#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
int a[1005][1005];
int X[8]={-1,-1,-1,0,0,1,1,1};
int Y[8]={-1,0,1,-1,1,-1,0,1};
int n,m;
int c;
bool check(int x,int y){
    set<int> s;
    if(x==n||y==m)return false;
    if(x==0||y==0)return false;
    for(int i = 0;i<=1;i++)
    for(int j = 0;j<=1;j++){
        if(a[x+i][y+j])
        s.insert(a[x+i][y+j]);
    }
    if(s.size()==1)c=*s.begin();
    return s.size()==1;
    
}
void solve(){
    vector<pair<pii,int> > ans;
    //int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
        }
    }
    queue<pii> q;
    for(int i = 1;i<n;i++){
        for(int j = 1;j<m;j++){
            if(check(i,j)){
                ans.pb(mp(mp(i,j),c));
                for(int aa = 0;aa<=1;aa++)
                for(int b = 0;b<=1;b++){
                    a[aa+i][b+j]=0;
                    //s.insert(a[x+i][y+j]);
                }
                q.push(mp(i,j));
            }
        }
    }
    while(!q.empty()){
        pii p=q.front();
        q.pop();
        
        for(int i =0;i<8;i++){
            if(check(p.x+X[i],p.y+Y[i])){
                for(int aa = 0;aa<=1;aa++)
                for(int b = 0;b<=1;b++){
                    a[p.x+X[i]+aa][p.y+Y[i]+b]=0;
                    //s.insert(a[x+i][y+j]);
                }
                ans.pb(mp(mp(p.x+X[i],p.y+Y[i]),c));
                q.push(mp(p.x+X[i],p.y+Y[i]));
            }
        }
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            if(a[i][j]){
                printf("-1\n");
                return;
            }
        }
    }
    reverse(ans.begin(),ans.end());
    printf("%d\n",ans.size());
    for(auto it:ans)printf("%d %d %d\n",it.x.x,it.x.y,it.y);
}
int main(){
    int t=1;0000;
    //scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}