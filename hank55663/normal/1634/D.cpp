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
    int n;
    scanf("%d",&n);
    int Max=0,Maxi;
    int cnt=0;;
    for(int i = 3;i<=n;i++){
        printf("? 1 2 %d\n",i);
        fflush(stdout);
        int x;
        scanf("%d",&x);
        if(x>Max){
            Max=x;
            Maxi=i;
            cnt=0;
        }
        if(x==Max)cnt++;
        //if(x!=n-1)alln=0;
    }
  /*  if(cnt==n-2){
        printf("! 1 2\n");
        fflush(stdout);
    }
    else*/{
        int y=1;
        //int alln=1;
        int Max=0,Maxi2;
        int cnt=0;
        for(int i = 2;i<=n;i++){
            if(i==Maxi)continue;
            printf("? 1 %d %d\n",Maxi,i);
            fflush(stdout);
            int x;
            scanf("%d",&x);
            if(x>Max){
                Max=x;
                Maxi2=i;
                cnt=0;
            }
            if(x==Max)cnt++;
           // if(x!=n-1)alln=0;
        } if(cnt==n-2){
            printf("! 1 %d\n",Maxi);
           //  assert(a[Maxi]==0||a[1]==0);
            
        }
        else
        if(Maxi2==2){
            int a=3;
            if(a==Maxi)a++;
            printf("? %d %d %d\n",Maxi,Maxi2,a);
            fflush(stdout);
            int x;
            scanf("%d",&x);
            if(x==Max){
                printf("! %d %d\n",Maxi,Maxi2);
            }
            else{
                printf("! 1 2\n");
            }
        }
        else printf("! %d %d\n",Maxi,Maxi2);
         fflush(stdout);
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
3 1 2 4 5

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