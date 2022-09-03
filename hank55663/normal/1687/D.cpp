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
int pre[10000005];
int suf[10000005];
void solve(){
    int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
        int x;
        scanf("%d",&x);
        //x--;
        pre[x]=x;
        suf[x]=x;
    }
    for(int i = 1;i<=10000000;i++){
        if(pre[i]==0)
        pre[i]=pre[i-1];
    }
    for(int i = 10000000;i>=0;i--){
        if(suf[i]==0)suf[i]=suf[i+1];
    }
    for(int i = 1;;i++){
        int a=i+1,b=i;
        int Max=i,Min=0;
        LL now=i;
        now*=i;
        for(int j = 1;j<=2500000;){
            if(pre[j+a-1]!=0)
            Max=min(Max,j+a-1-pre[j+a-1]);
            if(suf[j+a]!=0)
            Min=max(Min,j+a+b-suf[j+a]);
            now+=a+b;
            j+=a+b;
            a++;
            b++;
        }
        //printf("%d %d\n",Max,Min);
        if(Max>=Min){
            printf("%lld\n",i*1ll*i+Min-1);
            return;
        }
        a=i+1,b=i;
        now=i*1ll*i+a;
        a=i,b=i+2;
         Max=i-1,Min=0;
        for(int j =1;j<=2500000;){
            if(pre[j+a+b-1]!=0)
            Max=min(Max,j+a+b-1-pre[j+a+b-1]);
            if(suf[j]!=0)
            Min=max(Min,j+a-suf[j]);
            now+=a+b;
            j+=a+b;
            a++;
            b++;
        }
        if(Max>=Min){
            printf("%lld\n",i*1ll*i+i+Min);
            return;

        }
    }
} 

int main(){
   
    int t=1;
  // scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}
/*
9 10 15 16
0 1 2 3 4 5 6 7 
0 1 6 7 4 5 2 3
0 3 2 5 4 7 6 1
0 3 6 1 4 7 2 5
0 5 2 7 4 1 6 3
0 5 6 3 4 1 2 7
0 7 2 1 4 3 6 5
0 7 6 5 4 3 2 1
    a=p*1+(1-p)*(1+t2+a)
    a=p+q+q*t2+q*a
    a=(p+q+q*t2)/(1-q)
*/
/*
0 0 0 0
1 2 1 4
1 0 1 0
3 3 3 3
3 1 2 2
4 1 2 1
2 0 2 0

1 4 2 7 5 6 3
*/