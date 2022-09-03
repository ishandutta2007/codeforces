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
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
int vis[500005];
int sg[1005];
//int SG2(int);
int SG(int x){
    while(x>500)x-=34;
    if(x==-1)return 0;
    if(sg[x]!=-1)return sg[x];
    if(x==0)return 0;
    if(x==1)return 0;
    int vis[105];
    MEM(vis);
   // if(x==3)printf("\n");
    for(int j = 0;j<x-1;j++){
        vis[SG(j)^SG(x-j-2)]=1;
        /*if(x==3){
            printf("%d %d\n",j,x-j-2);
        }*/
        //vis[SG2(j)^SG2(x-j-2)]=1;
       
     /*   if(x==3){
            printf("%d %d ",SG(j)^SG(x-j-1),SG(j)^SG(x-j-2));
        }*/
     
    }
  //  if(x==3)printf("\n");
    for(int j = 0;;j++){
        if(!vis[j])return sg[x]=j;
    }
}
void solve(){
    MEMS(sg);    int n;
    scanf("%d",&n);
   // MEMS(sg2);

    char c[500005];
  //  int val[500005];
   // fill(val,val+n+1,0);
    fill(vis,vis+n+1,0);
    scanf("%s",c);
    int r=0,b=0;
    int cnt=0;
    int ch=0;
    int ok=0;
    //int b=0;
    for(int i = 0;c[i+1]!=0;i++){
        if(c[i]!=c[i+1]){
          //  val[i]=val[i+1]=1;
            cnt++;
        }
        else{
            cnt++;
            if(cnt%2==1){
                cnt--;
                if(c[i+1]=='B'){
                    b++;
                    if(cnt==i){}
                }
                else r++;
                vis[cnt+1]^=1;

            }else{
              //         if(cnt%4==0)ok=1;
              //ch++;
            //  ch+=cnt/2;
                vis[cnt]^=1;
            }
            cnt=0;
        }
    }
       // printf("%d %d\n",r,b);
    /*for(int i = 0;c[i]!=0;i++){
        if(!val[i]){
            if(c[i]=='R')r++;
            else b++;
        }
    }*/
       // printf("%d %d %d\n",r,b,cnt);
     cnt++;
     
        if(cnt%2==1){
            cnt--;
            if(c[n-1]=='B')b++;
            else r++;
            vis[cnt+1]^=1;
        }else{
                   //if(cnt%4==0)ok=1;
            //ch+=cnt/2;
            vis[cnt]^=1;
        }
    
 //   printf("%d %d %d\n",r,b);
    int bi=0;
    for(int i = 2;i<=n;i++){
        if(vis[i]){
            bi^=SG(i);
        }
    }
//   printf("%d %d %d\n",r,b,bi);
    if(r==b){
        if(bi)printf("Alice\n");
        else printf("Bob\n");
    }
    else if(r>b)printf("Alice\n");
    else printf("Bob\n");
}
int main(){
    int t=1;00000000;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    
}
/*
*/