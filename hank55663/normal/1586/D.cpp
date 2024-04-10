#include<bits/stdc++.h>
#pragma optimize(Ofast)
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
#define MXN 500005

void solve(){
    int n;
    scanf("%d",&n);
    int go[105];
    int Next[105];
    int ans[105];
    MEMS(Next);
    MEM(ans);
    for(int i = 1;i<=n;i++){
        printf("?");
        for(int j = 1;j<=n;j++){
            if(j==i){
                printf(" 2");
            }
            else{
                printf(" 1");
            }
        }
        printf("\n");
        fflush(stdout);
        int x;
        scanf("%d",&x);
        if(x!=i){
            go[i]=x;
            Next[x]=i;
        }
    }
    int now=0;
    int i=n;
    //printf("%d\n",111211);
    while(true){
        while(Next[now]!=-1){
            now=Next[now];
            ans[now]=i--;
       //     printf("ans %d\n",now);
        }
        if(i==0)break;
        printf("?");
        for(int j = 1;j<=n;j++){
            if(ans[j])printf(" 1");
            else printf(" 2");
        }
        printf("\n");
        fflush(stdout);
        scanf("%d",&now);
        ans[now]=i--;
    }
    printf("! ");
    for(int j = 1;j<=n;j++){
        printf("%d ",ans[j]);
    }
    printf("\n");
}
int main(){
    int t=1;0000;
 //   scanf("%d",&t);
    for(int i = 1;i<=t;i++){
       // cerr<<i<<endl;
        solve();
    }
    return 0;
}
/*
[[([(([([([
1 8
3 4
1 8
2 7
5 6
*/