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
    int a[55];
    for(int i = 0;i<n;i++)scanf("%d",&a[i]);
    if(n%2==1){
        printf("Mike\n");
    }
    else{
        int cnt[2]={1000000000,1000000000};
        for(int i = 0;i<n;i++){
            cnt[i&1]=min(cnt[i&1],a[i]);
        }
        if(cnt[0]>cnt[1]){
            printf("Mike\n");
        }
        else if(cnt[0]<cnt[1]){
            printf("Joe\n");
        }
        else{
            int x,y;
            for(int i = 0;i<n;i+=2){
                if(a[i]==cnt[0]){
                    x=i;
                    break;
                }
            }
            for(int i = 1;i<n;i+=2){
                if(a[i]==cnt[0]){
                    y=i;
                    break;
                }
            }
            if(x<y)printf("Joe\n");
            else printf("Mike\n");
        }
    }
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