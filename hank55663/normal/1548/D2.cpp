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
int val[6005][6005];
void solve(){
    int n=5;
    scanf("%d",&n);
   // printf("%d\n",n);
    pii p[6005];
    for(int i = 0;i<n;i++){
        int x=rand()%5,y=rand()%5;
        scanf("%d %d",&x,&y);
       // printf("%d %d\n",x,y);
        p[i]=mp(x,y);
    }
    for(int i = 0;i<n;i++){
        for(int j= i+1;j<n;j++){
            int x=abs(p[i].x-p[j].x),y=abs(p[i].y-p[j].y);
            if(x%4==0&&y%4==0)val[i][j]=val[j][i]=0;
            else if(x%2==0&&y%2==0)val[i][j]=val[j][i]=2;
            else val[i][j]=val[j][i]=__gcd(x,y)%4;
            //if(i==0&&j==2)printf("%d %d %d %d\n",val[i][j],x,y);
        }
    }
    LL odd=0,even=0;
    for(int i = 0;i<n;i++){
      //  printf("!!!%d\n",i);
        int cnt[4][4][4];
        memset(cnt,0,sizeof(cnt));
        for(int j = 0;j<n;j++){
            if(i==j)continue;
            int x=(p[j].x-p[i].x)%4+4,y=(p[j].y-p[i].y)%4+4;
          //  if(i==0)
          //  printf("%d %d %d\n",x%4,y%4,val[i][j]);
            cnt[x%4][y%4][val[i][j]]++;
        }
        for(int x1=0;x1<4;x1++){
            for(int y1=0;y1<4;y1++){
                for(int k1=0;k1<4;k1++){
                    for(int x2=0;x2<4;x2++){
                        for(int y2=0;y2<4;y2++){
                            for(int k2=0;k2<4;k2++){
                                int a=x1*4+y1*2+k1,b=x2*4+y2*2+k2;
                                LL val=cnt[x1][y1][k1]*cnt[x2][y2][k2];
                                if(a==b){
                                    val=cnt[x1][y1][k1]*(cnt[x1][y1][k1]-1)/2;
                                }
                                
                                if(a>b)continue;
                                int S=abs(x1*y2-x2*y1);
                                if(val){
                                  //  printf("%d %d %d %d %d %d\n",S,x1,y1,x2,y2,val);   
                                }
                                if(S%2)continue;
                                S/=2;
                                if(val){
                                //    printf("%d %d\n",k1,k2);   
                                }
                                if(k1%2!=k2%2)continue;
                                int x=abs(x1-x2),y=abs(y1-y2);
                                if(val){
                                  //  printf("%d %d\n",x,y);   
                                }
                                if(x%2||y%2)continue;
                                int tot=k1+k2;
                                if(x%4||y%4)tot+=2;
                                else tot+=4;
                                tot/=2;
                                if(val){
                                //    printf("%d %d\n",S,tot);   
                                }
                                if(tot%2==S%2){
                                    
                                    if(k1%2)odd+=val;
                                    else{ 
                                        even+=val;
                                     //   if(val)
                                     //  printf("%d %d %d %d %d %d %d %d %d\n",i,x1,y1,k1,x2,y2,k2,cnt[x1][y1][k1],cnt[x2][y2][k2]);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
   
    printf("%lld\n",odd+even/3);
     assert(even%3==0);
}
int main(){
    int t=1;
   // scanf("%d",&t);
    while(t--){
        solve();
    }
    //printf("8192\n");
    //printf("%d\n",cnt);
    //printf("%.12f\n",sum/tt);
    return 0;
}
/*

a b c
b c
ab ac bc
5
4 3
1 4
4 2
3 4
0 0
*/