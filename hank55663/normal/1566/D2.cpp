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
#define MXN 3000000
int mod=1e9+7;
bool cmp(const pii &p,const pii &q){
    if(p.x!=q.x)return p.x<q.x;
    else return p.y>q.y;
}
int vis[305][305];
pii loc[90005];
void solve(int T){
    int n,m;
    scanf("%d %d",&n,&m);
    pii a[90005];
    for(int i = 0;i<n*m;i++){
        int x;
        scanf("%d",&x);
        a[i]=mp(x,i);
    }
    sort(a,a+n*m);

    vector<int> v;
    v.pb(a[0].y);
    int nowx=0,nowy=0;
    for(int i = 1;i<n*m;i++){
        //a[i].x=i;
        if(a[i].x==a[i-1].x)v.pb(a[i].y);
        else{
            //printf("%d %d %d\n",i,a[i].x,a[i-1].x);
            reverse(v.begin(),v.end());
            while(v.size()){
                if(m-nowy<=v.size()){
                    for(int j = m-1;j>=nowy;j--){
                        int x=v.back();
                    //    printf("%d %d %d\n",x,nowx,j);
                        v.pop_back();
                        loc[x]=mp(nowx,j);
                    }
                    nowx++;
                    nowy=0;
                }
                else{
                    int s=v.size();
                    for(int j = nowy+s-1;j>=nowy;j--){
                        int x=v.back();
                     //    printf("%d %d %d\n",x,nowx,j);
                        v.pop_back();
                        loc[x]=mp(nowx,j);
                    }
                    nowy=nowy+s;
                }
            }
            v.pb(a[i].y);
        }
    }
     reverse(v.begin(),v.end());
            while(v.size()){
                if(m-nowy<=v.size()){
                    for(int j = m-1;j>=nowy;j--){
                        int x=v.back();
                      //    printf("%d %d %d\n",x,nowx,j);
                        v.pop_back();
                        loc[x]=mp(nowx,j);
                    }
                    nowx++;
                    nowy=0;
                }
                else{
                    int s=v.size();
                    for(int j = nowy+s-1;j>=nowy;j--){
                        int x=v.back();
                    //     printf("%d %d %d\n",x,nowx,j);
                        v.pop_back();
                        loc[x]=mp(nowx,j);
                    }
                    nowy=nowy+s;
                }
            }
    int ans=0;
    MEM(vis);
    for(int i = 0;i<n*m;i++){
        for(int j = 0;j<loc[i].y;j++){
            if(vis[loc[i].x][j])ans++;
        }
        vis[loc[i].x][loc[i].y]++;
      //  printf("%d %d\n",loc[i].x,loc[i].y);
    }
    printf("%d\n",ans);
}
int main(){
    int t=1;
    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve(i);
    }
    return 0;
}
/*
000010000
001010000
001010100
001011100

1 1 2
1 1 2 1
2 1
2


XOXOXOXOOXOXXOXOXOXOOXOX
*/