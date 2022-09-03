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
    int a[505];
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    //printf("1\n");
    for(int i = 1;i<=n;i++){
        if(a[i]!=i){
            for(int j = i+1;j<=n;j++){
                if(a[j]==i){
                    reverse(a+i,a+j+1);
                    break;
                }
            }
            break;
        }
    }
    for(int i = 1;i<=n;i++)printf("%d ",a[i]);
    printf("\n");
}
int main(){
    int t=1;0000;
    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}