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
#define index Index
void solve(){
    int n;
    scanf("%d",&n);
    int ans[100005];
    MEM(ans);
    for(int i = 1;i<=n;i++){
        if(ans[i]==0){
            vector<int> tmp;
            printf("? %d\n",i);
            fflush(stdout);
               int x;
            scanf("%d",&x);
         
            do{
                tmp.pb(x);
                printf("? %d\n",i);
                fflush(stdout);
                scanf("%d",&x);
            }while(tmp[0]!=x);
            int ok=0;
            int now=i;
            for(int j = 0;j<tmp.size();j++){
                if(!ok){
                    tmp.pb(tmp[j]);
                }
                else{
                    ans[now]=tmp[j];
                    now=tmp[j];
                }
                if(tmp[j]==i)ok=1;
            }
        }
    }
    printf("!");
    for(int i = 1;i<=n;i++)printf(" %d",ans[i]);
    printf("\n");
    fflush(stdout);
}
int main(){
    int t=1;0000;
    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}
/*
8876666554222188 
*/