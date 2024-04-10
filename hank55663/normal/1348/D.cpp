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
#define pi acosl(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MAXN 205
#define N 262144
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i = 1;;i++){
            if((1ll<<(i+1))-1>=n){
                printf("%d\n",i);
                LL tmp=n;
                tmp-=i+1;
                LL tot=1;
                for(int j = 0;j<i;j++){
                    int add=min(tmp/(i-j),tot);
                    tot+=add;
                    tmp-=add*(i-j);
                    printf("%d ",add);
                }
                printf("\n");
                break;
            }
        }
    }
}