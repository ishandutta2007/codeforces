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
void solve(){
    int l,n;
    scanf("%d %d",&l,&n);
    int a[100005];
    for(int i = 1;i<=n;i++)scanf("%d",&a[i]);
    a[n+1]=l;
    int Min=1,Max=l/n+1;
    while(Min+1<Max){
        int mid=(Max+Min)/2;
        int l=0;
        int ok=1;
        for(int i = 1;i<=n;i++){
            if(l>a[i]){
                ok=0;
                break;
            }
            l=max(l+mid,a[i]);
        }
        if(!ok)Max=mid;
        else Min=mid;
    }
    int Minn=Min;
    Min=(l+n-1)/n-1,Max=l;
    while(Min+1<Max){
        int mid=(Max+Min)/2;
        int l=0;
        int ok=1;
      //  printf("%d\n",mid);
        for(int i = 1;i<=n;i++){
          //  printf("%d ",l);
            l+=mid;
            if(l<a[i]){
                ok=0;
                break;
            }
            l=min(a[i+1],l);
          //  printf("%d\n",l);
        }
        if(l!=a[n+1])ok=0;
        if(ok)Max=mid;
        else Min=mid;
    }
    Min=Minn;
  //  printf("%d %d\n",Min,Max);
    pii p[100005];
    int now=0;
    for(int i =1;i<=n;i++){
        p[i].y=max(now+Min,a[i]);
        p[i].x=p[i].y-Min;
        now=p[i].y;
    }
     /* for(int i = 1;i<=n;i++)printf("%d %d\n",p[i].x,p[i].y);*/
    int last=l;
    p[0]=mp(0,0);
    for(int i = n;i>=1;i--){
        p[i]=mp(max(last-Max,p[i-1].y),last);
        last=p[i].x;
    }
    for(int i = 1;i<=n;i++)printf("%d %d\n",p[i].x,p[i].y);
}
int main(){
    int t=1;00000;
 //   scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}
/*
p*t = a^2+b^2
q*t = ab
(p+2*q)*t=(a+b)^2
*/