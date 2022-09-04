#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define index Index
using namespace std;
typedef long long LL;
int main(){
    int n,a,b;
    scanf("%d %d %d",&n,&a,&b);
    if(a!=1&&b!=1){
        printf("NO\n");
        return 0;
    }
    else if((n==2||n==3)&&a==1&&b==1){
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    int ans[1005][1005];
    MEM(ans);
    if(b==1&&a!=1){
        for(int i=a;i<=n;i++){
            for(int j=a;j<=n;j++){
                if(i!=j)
                    ans[i][j]=1;
            }
        }
    }
    else if(a==1&&b!=1){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i!=j)
                    ans[i][j]=1;
            }
        }
        for(int i=b;i<=n;i++){
            for(int j=b;j<=n;j++){
                if(i!=j)
                    ans[i][j]=0;
            }
        }
    }
    else{
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(abs(i-j)==1)
                ans[i][j]=1;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        printf("%d",ans[i][j]);
        printf("\n");
    }
}