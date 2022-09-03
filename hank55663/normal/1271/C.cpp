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
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define KK 500
#define MXN 200005
int main(){
    int n,x,y;
    scanf("%d %d %d",&n,&x,&y);
    //pii p[200005];
    int u=0,d=0,l=0,r=0;
    for(int i = 0;i<n;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        a-=x;
        b-=y;
       // printf("%d %d\n",a,b);
        if(a>0)u++;
        if(a<0)d++;
        if(b>0)r++;
        if(b<0)l++;
      //  printf("%d %d %d %d\n",u,d,r,l);
    }
    if(u>=d&&u>=l&&u>=r){
        printf("%d\n%d %d\n",u,x+1,y);
    }
    else if(d>=u&&d>=l&&d>=r){
        printf("%d\n%d %d\n",d,x-1,y);
    }
    else if(l>=u&&l>=d&&l>=r){
        printf("%d\n%d %d\n",l,x,y-1);
    }
    else{
        printf("%d\n%d %d\n",r,x,y+1);
    }
}