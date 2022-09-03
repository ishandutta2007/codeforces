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
    int a[200005];
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    int ok=1;
    for(int i = 2;i<n;i++){
        if(a[i]>a[i-1]&&a[i]>a[i+1])ok=0;
    }
    if(ok){
        printf("0\n");
        for(int i =1;i<=n;i++){
            printf("%d ",a[i]);
        }
        printf("\n");
        return;
    }
    int ans=0;
    for(int i = 2;i<n;i++){
        if(a[i]>a[i-1]&&a[i]>a[i+1]){
            a[i+1]=max(a[i],a[i+2]);
            ans++;
        }
    }
    printf("%d\n",ans);
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