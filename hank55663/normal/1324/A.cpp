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
#define MXN 205
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int even=0,odd=0;
        for(int i = 1;i<=n;i++){
            int x;
            scanf("%d",&x);
            if(x&1)odd++;
            else even++;
        }
        if(!odd || !even){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
}
/*
4+3+3+4+3+2+2+1
*/