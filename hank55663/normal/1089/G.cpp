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
    int t;
    scanf("%d",&t);
    while(t--){
        int k;
        scanf("%d",&k);
        int a[7];
        int tot=0;
        for(int i = 0;i<7;i++){
            scanf("%d",&a[i]);
            tot+=a[i];
        }
        int ans=7*k;
        for(int i = 0;i<7;i++){
            int sum=(k-1)/tot*7;
            int num=0;
            for(int j=0;j<7&&num<(k-1)%tot+1;j++){
                sum++;
                if(a[j])num++;
            }
            //int tmp=a[0];
            for(int j=0;j<6;j++){
                swap(a[j],a[j+1]);
            //    printf("%d ",a[j]);
            }
          //  printf("%d ",a[6]);
          //  printf("%d\n",sum);
            ans=min(ans,sum);
        }
        printf("%d\n",ans);
    }
}