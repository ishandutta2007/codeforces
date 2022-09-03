#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define x first
#define LL long long 
#define y second
#define sqr(x) ((x)*(x))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<double,double>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
void solve(int *a,int n){
    for(int i = 1;i<n;i++){
        if(a[i]==a[i+1]){
            printf("2\n");
            for(int j = 1;j<=n;j++){
                if(j<=i){
                    printf("%d ",j%2+1);
                }
                else{
                    printf("%d ",2-j%2);
                }
            }
            printf("\n");
            return ;
        }
    }
    if(a[1]==a[n]){
        printf("2\n");
        for(int i = 1;i<=n;i++){
            printf("%d ",i%2+1);
        }
        printf("\n");
        return ;
    }
    printf("3\n");
    for(int i = 1;i<n;i++){
        printf("%d ",i%2+1);
    }
    printf("3\n");
}
int main() {
	int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int a[200005];
        int same=1;
        for(int i = 1;i<=n;i++){
            scanf("%d",&a[i]);
            if(a[i]!=a[1])same=0;
        }
        if(same){
            printf("1\n");
            for(int i = 1;i<=n;i++)printf("1 ");
            printf("\n");
        }
        else if(n%2==0){
            printf("2\n");
            for(int i = 1;i<=n;i+=2){
                printf("1 2 ");
            }
            printf("\n");
        }
        else{
            solve(a,n);
        }
    }
}