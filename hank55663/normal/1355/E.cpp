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
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MAXN 205
//#define N 262144
#define ULL unsigned long long
LL cal(int *h,int n,int a,int r,int m,int k){
    LL x=0,y=0;
    for(int i= 0;i<n;i++){
        if(h[i]>k)
        x+=h[i]-k;
        else
        y+=k-h[i];
    }
    LL res=0;
    LL tot=min(x,y);
    x-=tot;
    y-=tot;
    res+=tot*m+a*y+r*x;
    return res;
}
int main(){
    int n,a,r,m;
    scanf("%d %d %d %d",&n,&a,&r,&m);
    int h[100005];
    m=min(m,a+r);
    for(int i = 0;i<n;i++){
        scanf("%d",&h[i]);
    }
    sort(h,h+n);
    LL Max=h[n-1],Min=h[0];
    while(Max>Min+100){
        LL mid1=(Max+Min*2)/3,mid2=(Max*2+Min)/3;
        LL res1=cal(h,n,a,r,m,mid1),res2=cal(h,n,a,r,m,mid2);
        if(res1>res2){
            Min=mid1;
        }
        else{
            Max=mid2;
        }
    }
  //  printf("%d %d\n",Min,Max);
    LL ans=1e18;
    for(int i = Min;i<=Max;i++){
        ans=min(ans,cal(h,n,a,r,m,i));
    }
    printf("%lld\n",ans);
}

/*
1000000000000000000
1000000000000000000 1 1 1 1000000000
*/