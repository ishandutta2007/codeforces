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
#define MXN 3000000
void solve(){
    int loc[2022];
    int n;
    scanf("%d",&n);
    int a[2022];
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i = 1;i<=n;i++){
        if((a[i]-i)%2!=0){
            printf("-1\n");
            return ;
        }
    }
    vector<int> v;
    for(int i = n;i>1;i-=2){
        for(int j = 1;j<=i;j++){
            if(a[j]==i){
                if(j!=1){
                    v.pb(j);
                    reverse(a+1,a+j+1);
                }
            }
        }
       // for(int j = 1;j<=n;j++)printf("%d ",a[j]);
        // printf("a %d\n",i);
        for(int j = 1;j<=i;j++){
            if(a[j]==i-1){
                if(j-1!=1){
                    v.pb(j-1);
                    reverse(a+1,a+j);
                  //  for(int j = 1;j<=n;j++)printf("%d ",a[j]);
       //  printf("b\n");
                }
                v.pb(j+1);
                reverse(a+1,a+j+2);
             //   for(int j = 1;j<=n;j++)printf("%d ",a[j]);
       //  printf("c\n");
                v.pb(3);
                reverse(a+1,a+4);
              // for(int j = 1;j<=n;j++)printf("%d ",a[j]);
       //  printf("d\n");
                v.pb(i);
                reverse(a+1,a+i+1);
               //for(int j = 1;j<=n;j++)printf("%d ",a[j]);
      //   printf("e\n");
         break;
            }
        }
        // for(int j = 1;j<=n;j++)printf("%d ",a[j]);
        // printf("\n");
    }
   // for(int j = 1;j<=n;j++)printf("%d ",a[j]);
    printf("%d\n",v.size());
    for(auto it:v)printf("%d ",it);
    printf("\n");
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}
/*
6 4 2 3 5 1
*/