#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acosl(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
//#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define ld long double
//#define N 6000005
#define rank Rank
#define index Index
#define MXN 100005
vector<pii> v[1000055];
int X[4]={0,0,1,-1};
int Y[4]={1,-1,0,0};
short dis[45][1000055];
int main(){
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    int a[1005][1005];
    for(int i = 0 ; i<n;i++)
        for(int j =0;j<m;j++){
            scanf("%d",&a[i][j]);
            for(int k =0;k<4;k++){
                int x=i+X[k],y=j+Y[k];
                if(x>=0&&x<n&&y>=0&&y<m){
                    v[i*m+j].pb(mp(x*m+y,1));
                }
            }
            v[a[i][j]+n*m].pb(mp(i*m+j,1));
            v[i*m+j].pb(mp(a[i][j]+n*m,0));
        }
    //printf("%d\n",k);
    for(int i = 1;i<=k;i++){
        queue<int> q1,q2;
        q1.push(n*m+i);
        fill(dis[i],dis[i]+1000055,6000);
        dis[i][n*m+i]=0;
        int now=0;
      //  printf("%d\n",i);
        while(!q1.empty()){
            while(!q1.empty()){
                int x = q1.front();
               /* if(i==3){
                    printf("%d %d\n",x,now);
                }*/
                q1.pop();
                if(dis[i][x]!=now)continue;
                for(pii &p : v[x]){
                    if(p.y == 0){
                        if(dis[i][x]<dis[i][p.x]){
                            dis[i][p.x]=dis[i][x];
                            q1.push(p.x);
                        }
                    }
                    else{
                        if(dis[i][x]+1<dis[i][p.x]){
                            dis[i][p.x]=dis[i][x]+1;
                            q2.push(p.x);
                        }
                    }
                }
            }
            while(!q2.empty()){
                q1.push(q2.front());
                q2.pop();
            }
            now++;
        }
    }
    int q;
    scanf("%d",&q);
    while(q--){
        int r1,c1,r2,c2;
        scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
        r1--;
        c1--;
        r2--;
        c2--;
        if(a[r2][c2]==a[r1][c1]){
            if(r1==r2&&c1==c2)printf("0\n");
            else printf("1\n");
        }
        else{
       // printf("%d %d\n",a[r2][c2],r1*m+c1);
            int ans=dis[a[r2][c2]][r1*m+c1];
            for(int i = max(r2-40,0);i<min(r2+40,n);i++){
                for(int j=max(c2-40,0);j<min(c2+40,m);j++){
                    ans=min(dis[a[i][j]][r1*m+c1]+abs(i-r2)+abs(j-c2),ans);
                }
            }
            ans=min(ans,abs(r1-r2)+abs(c1-c2));
            printf("%d\n",ans);
        }
    }
    
}