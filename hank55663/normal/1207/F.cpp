#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define less Less
#define EPS 1e-4
#define arg ARG
#define pdd pair<double,double>
#define cpdd const pdd
int ans[705][705];
int a[500005];
int main(){
    int q;
    scanf("%d",&q);
    while(q--){
        int op;
        scanf("%d",&op);
        if(op==1){
            int x,y;
            scanf("%d %d",&x,&y);
            a[x]+=y;
            for(int i = 1;i<=700;i++){
                ans[i][x%i]+=y;
            }
        }
        else{
            int x,y;
            scanf("%d %d",&x,&y);
            if(x>700){
                int res=0;
                for(int i=y;i<=500000;i+=x)res+=a[i];
                printf("%d\n",res);
            }
            else{
                printf("%d\n",ans[x][y]);
            }
        }
    }
}
/*
100
2 3
0 500000000 1000000000
1000000000 1000000000 1000000000
24
 */