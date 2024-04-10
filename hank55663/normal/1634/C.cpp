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
const int mod=998244353;
void solve(){
    int n,k;
    scanf("%d %d",&n,&k);
    if(k==1){
        printf("YES\n");
        for(int j = 1;j<=n;j++){
            printf("%d\n",j);
        }
    }
    else if(n%2){
  //      if(n%2)
       printf("NO\n");

    }
    else{
        if(k==2){
            printf("YES\n");
            for(int j = 1;j<=n;j++){
                printf("%d %d\n",j,j+n);
            }

        }
        else{
             printf("YES\n");
            int odd=1,even=2;
            for(int j=1;j<=n;j++){
                for(int i = 1;i<=k;i++){
                    if(j&1){
                        printf("%d ",odd);
                        odd+=2;
                    }
                    else{
                        printf("%d ",even);
                        even+=2;
                    }
                }
                printf("\n");
            }
        }
    }
} 
/*
LLRLLR
012345
LRLL
*/
int main(){
   /* for(int i = 2;i<=1000000;i++){
        if(v[i].empty())
        for(int j = i;j<=1000000;j+=i )v[j].pb(i);
    }*/
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}
/*
(k_1x+b)k_2+b=y

36
0123
0123 4567

RRRRR
6 4 4 4
5 3 4 4
4 3 3 4
4 2 4 4
3 2 3 4
4 4 2 4


*/