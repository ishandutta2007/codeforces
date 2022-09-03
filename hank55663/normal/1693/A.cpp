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
#define index Index
#define MXN 1000000
void solve(){
    int n;
    scanf("%d",&n);
    int a[200005];
    for(int i = 0;i<n;i++)scanf("%d",&a[i]);
    long long sum=0;
    for(int i = 0;i<n;i++){
                if(sum==0&&i!=0&&a[i]){
            printf("No\n");
            return;
        }
        sum+=a[i];
        if(sum<0){
            printf("No\n");
            return;
        }

    }
    if(sum==0)printf("Yes\n");
    else printf("No\n");
}
int main(){
 //   srand(time(NULL));
    int t=1;0000;
    scanf("%d",&t);
    //int res=0;
   
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}