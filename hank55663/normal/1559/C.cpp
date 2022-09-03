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
void solve(){
    int n;
    scanf("%d",&n);
    int x=1,y=0;
    int a[10005];
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
        x&=a[i];
        y|=a[i];
    }
    if(a[0]==1){
        printf("%d ",n+1);
        for(int i = 1;i<=n;i++)printf("%d ",i);
        printf("\n");
    }
    else if(a[n-1]==0){
          for(int i = 1;i<=n;i++)printf("%d ",i);
          printf("%d\n",n+1);
          
    }
    else{
        int ok=0;
        for(int i=0;i<n;i++){
            printf("%d ",i+1);
            if(a[i]==0&&a[i+1]==1&&!ok){
                printf("%d ",n+1);
                ok=1;
            }
        }
        if(!ok)printf("%d ",n+1);
        printf("\n");
    }
}
int main(){
    int t=1;//00;//00;
    scanf("%d",&t);
    while(t--){
        solve();
    }
 //   printf("0\n1\n2\n");
    //printf("8192\n");
    //printf("%d\n",cnt);
    //printf("%.12f\n",sum/tt);
    return 0;
}
/*
*/