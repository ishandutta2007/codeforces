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
    int a[3];
    scanf("%d %d %d",&a[0],&a[1],&a[2]);
    if(a[1]-a[0]==a[2]-a[1]){
        printf("YES\n");
    }
    else{
        if((a[1]*2-a[2])%a[0]==0&&(a[1]*2-a[2])>=a[0]){
            printf("YES\n");
        }
        else if((a[1]*2-a[0])%a[2]==0&&(a[1]*2-a[0])>=a[2]){
            printf("YES\n");
        }
        else if((a[2]+a[0])%2==0&&(a[2]+a[0])/2%a[1]==0&&(a[2]+a[0])/2>=a[1]){
            printf("YES\n");
        }
        else printf("NO\n");

    }
}
int main(){
    int t=1;0000;
    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}