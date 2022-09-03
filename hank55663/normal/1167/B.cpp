#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define N 131072
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
int main(){
    int a[4];
    printf("? 1 2\n");
    fflush(stdout);
    scanf("%d",&a[0]);
    printf("? 2 3\n");
    fflush(stdout);
    scanf("%d",&a[1]);
    printf("? 3 4\n");
    fflush(stdout);
    scanf("%d",&a[2]);
    printf("? 4 5\n");
    fflush(stdout);
    scanf("%d",&a[3]);
    int ans[6]={4,8,15,16,23,42};
    do{
        if(ans[0]*ans[1]==a[0]&&ans[1]*ans[2]==a[1]&&ans[2]*ans[3]==a[2]&&ans[3]*ans[4]==a[3]){
            printf("! %d %d %d %d %d %d\n",ans[0],ans[1],ans[2],ans[3],ans[4],ans[5]);
            fflush(stdout);
            break;
        }
    }while(next_permutation(ans,ans+6));
}