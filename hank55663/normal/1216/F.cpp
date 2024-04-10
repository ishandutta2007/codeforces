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
#define MXN 1500
LL S[200005];
void re(int x,LL k){
   /// printf("%d %d\n",x,k);
    for(int i=x;i>0;i-=i&-i){
      //  printf("%d\n",i);
        S[i]=min(S[i],k);
    }
    //printf("?\n");
}
LL qu(int x){
    //printf("%d\n",x);
    if(x==0)return 0;
    LL res=1e18;
    for(int i=x;i<200005;i+=i&-i){
      //  printf("%d %d\n",i,S[i]);
        res=min(res,S[i]);
    }
    return res;
}
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    fill(S,S+200005,1e18);
    char c[200005];
    scanf("%s",c+1);
    for(int i = 1;c[i]!=0;i++){
        LL x=qu(i-1);
        //printf("%d %d\n",i,x);
        re(i,x+i);
        if(c[i]=='1'){
            int l=max(i-k,1),r=min(i+k,n);
            x=qu(l-1);
            re(r,x+i);
        }
    }
    printf("%lld\n",qu(n));
}