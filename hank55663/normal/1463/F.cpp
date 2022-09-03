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
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
using namespace std;
#define N 1000000
#define Point pdd
#define Polygon vector<Point>
#define Line pair<Point,Point>
int vis[60];
int ok[60];
int dfs(int x,int a,int b,int n,int cnt,int q){
    if(x==n){
        return cnt;
    }
    int Max=0;
    if(ok[x]==1&&!vis[(x+a)%n]&&!vis[(x+b)%n]){
        vis[x]=1;
        ok[(x+a)%n]--;
        ok[(x+b)%n]--;
        int add=0;
        if(q%n>x)add++;
        Max=max(Max,dfs(x+1,a,b,n,cnt+q/n+add,q));
        vis[x]=0;
        ok[(x+a)%n]++;
        ok[(x+b)%n]++;
        if(x>b){
            if(!vis[x-b]&&ok[x-b]==1&&!vis[x-a]&&ok[x-a]==1){
                return Max;
            }
        }
    }
    Max=max(Max,dfs(x+1,a,b,n,cnt,q));
    return Max;
}
bool solve(){
  /*  for(int x=1;x<=22;x++){
        for(int y=x;y<=22;y++){
         //   if(x%2==1&&y%2==1)continue;
            printf("%d %d\n",x,y);
            fill(ok,ok+1000000+1,1);
            int Max=y,cnt=0;
            for(int i = 0;i<=Max;i++){
                if(i>100){
                   break;
                   // printf("\n");
                   // assert(0);
                }
                printf("%d",ok[i]);
                if(ok[i]){
                    cnt++;
                    ok[i+x]=0;
                    ok[i+y]=0;
                    Max=i+y;
                }
            }
            printf("\n");
            printf("!%d %d\n",cnt,Max+1);
        }
    }*/
    int n,x,y;
    scanf("%d %d %d",&n,&x,&y);
    if(x==y){
        printf("%d\n",n/(2*x)*x+min(n%(2*x),x));
        return true;
    }
    int ans=0;
    for(int i = 2;i<=x+y;i++){
        if(x%i==0||y%i==0)continue;
        int a=x%i,b=y%i;
        vis[0]=1;
        fill(ok,ok+i+1,1);
        ok[a]=ok[b]=0;
        if(a>b)swap(a,b);
        int res=dfs(1,a,b,i,n/i+(n%i>0),n);
        ans=max(ans,res);
       // printf("%d\n",res);
    }
    printf("%d\n",ans);
   /* printf("%d %d\n",Max,cnt);;
    if(x%2==1&&y%2==1){
        printf("%d\n",max(n/(Max)*cnt+add,(n+1)/2));
    }
    else{
        printf("%d\n",n/(Max)*cnt+add);
    }*/
}
int main(){
    int t=1;
   // scanf("%d",&t);
    while(t--)solve();
}
/*
1 4 10100
1 6 1010100
1 8 101010100
1 y 10100  (y+1)  y/2
2 5 1100100
2 6 11001100
2 7 110011000
2 8 1100110000
2 9 11001100100
*/