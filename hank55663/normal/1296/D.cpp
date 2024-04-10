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
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define ld long double
//#define N 6000005
#define rank Rank
#define index Index
int main() {
    int n,a,b,k;
    scanf("%d %d %d %d",&n,&a,&b,&k);
    int h[200005];
    for(int i = 0;i<n;i++){
        int x;
        scanf("%d",&x);
        x--;
        x%=(a+b);
        x++;
        x-=a;
        h[i]=(x+a-1)/a;
       // printf("%d ",h[i]);
    }
  //  printf("\n");
    sort(h,h+n);
    int ans=0;
    int tmp=0;
    for(int i = 0;i<n;i++){
        if(tmp+h[i]>k)break;
        ans++;
        tmp+=h[i];
    }
    printf("%d\n",ans);
}
/*
int main(){

"RGGGGRRRRG", "RG"
}*/