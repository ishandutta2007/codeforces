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
#define last Last
#define MXN 200005
const int mod=1e9+7;

void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    char c[55][55];
    int odd[2]={0,0},even[2]={0,0};
    for(int i=0;i<n;i++){
        scanf("%s",c[i]);
        for(int j = 0;j<m;j++){
            if(c[i][j]=='W'){
                if((i+j)%2)odd[1]=1;
                else even[1]=1;
            }
            else if(c[i][j]=='R'){
                if((i+j)%2)odd[0]=1;
                else even[0]=1;
            }
        }
    }
    if(odd[0]&&even[0])printf("NO\n");
    else if(odd[1]&&even[1])printf("NO\n");
    else if(odd[0]&&odd[1])printf("NO\n");
    else if(even[0]&&even[1])printf("NO\n");
    else{
        printf("YES\n");
        int ok=1;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if((i+j)%2==0){
                    if(c[i][j]=='R')ok=0;
                }
                else{
                    if(c[i][j]=='W')ok=0;
                }
            }
        }
        if(ok){
            for(int i = 0;i<n;i++){
                for(int j = 0;j<m;j++){
                    if((i+j)%2==0){
                        printf("W");
                    }
                    else{
                        printf("R");
                    }
                }
                printf("\n");
            }
        }
        else{
             for(int i = 0;i<n;i++){
                for(int j = 0;j<m;j++){
                    if((i+j)%2==0){
                        printf("R");
                    }
                    else{
                        printf("W");
                    }
                }
                printf("\n");
            }
        }
    }
}
/*
void solve(){
    int n;
    scanf("%d",&n);
    int a[400005];
    a[0]=a[n+1]=0;
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    LL ans=0;
    for(int i = 1;i<=n;i++){
        if(a[i]>a[i-1]&&a[i]>a[i+1]){
            int Max=max(a[i-1],a[i+1]);
            ans+=a[i]-Max;
            a[i]=Max;
        }
    }
    for(int i = 1;i<=n+1;i++){
        ans+=abs(a[i]-a[i-1]);
    }
    printf("%lld\n",ans);
}
*/
/*
ax+by<=c;
bx+ay<=d;
*/
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--)
        solve();
}
/*
2 3 5 6 1 4
*/