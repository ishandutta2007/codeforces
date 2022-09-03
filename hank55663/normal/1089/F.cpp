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
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MXN 300000
#define N 100005
int main(){
    int n;
    scanf("%d",&n);
    int tmp=n;
    vector<int> v;
    vector<int> prime;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            while(n%i==0){
                v.pb(i);
                n/=i;
            }
            prime.pb(i);
        }
    }
    if(n!=1)v.pb(n),prime.pb(n);
    if(prime.size()==1){
        printf("NO\n");
    }
    else{
        n=tmp;
      //  n-1-prime[0]*k=prime[1]*j 
        pii p1=mp(0,n/prime[1]);
        int now=n-1;
        while(now%prime[0]!=0){
            now-=prime[1];
            p1.x++;
        }
        printf("YES\n2\n");
        printf("%d %d\n",p1.x,p1.y);
        printf("%d %d\n",now/__gcd(n,now),n/__gcd(n,now));
        assert(now!=0);
    }
  /*  int n;
    scanf("%d",&n);
    if(n<=14){
        for(int i=0;i<8;i++)
            for(int j=0;j<8;j++){
                if(a[i][j]<=n&&a[i][j]!=0){
                    printf("%c%d ",i+'a',j+1);
                }
            }
        //printf("\n");
    }
    else if(n>=17){
        for(int i=0;i<6;i++){
            if(i&1)
            for(int j=7;j>=0;j--){
                if(b[i][j]<=n&&b[i][j]!=0){
                    printf("%c%d ",i+'a',j+1);
                }
            }
            else
            for(int j=0;j<8;j++){
                if(b[i][j]<=n&&b[i][j]!=0){
                    printf("%c%d ",i+'a',j+1);
                }
            }
        }
        if(b[6][0]<=n){
            printf("%c%d ",6+'a',0+1);
        }
        for(int j=0;j<7;j++){
            if(b[7][j]<=n&&b[7][j]!=0){
                    printf("%c%d ",7+'a',j+1);
                }
        }
        if(b[6][6]<=n){
            printf("%c%d ",6+'a',6+1);
        }
        for(int j=1;j<6;j++){
             if(b[6][j]<=n&&b[6][j]!=0){
                    printf("%c%d ",6+'a',j+1);
                }
        }
        if(b[6][7]<=n){
            printf("%c%d ",6+'a',7+1);
        }
        if(b[7][7]){
printf("%c%d ",7+'a',7+1);  
        }
    }
    else if(n==15){
        printf("a1 c1 b1");
        for(int j=2;j<=8;j++)
        printf(" b%d",j);
        for(int j=2;j<8;j++)
        printf(" %c8",'a'+j);
    }
    else if(n==16){
         printf("a1 c1 d1 b1");
        for(int j=2;j<=8;j++)
        printf(" b%d",j);
        for(int j=2;j<8;j++)
        printf(" %c8",'a'+j);
    }
    printf("\n");*/
}