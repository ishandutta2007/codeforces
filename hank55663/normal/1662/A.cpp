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
//#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
void solve(){
    int Max[15];
    MEMS(Max);
    int n;
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        Max[y]=max(Max[y],x);
    }
    int sum=0;
    for(int j = 1;j<=10;j++){
        if(Max[j]==-1){
            printf("MOREPROBLEMS\n");
            return;
        }
        else{sum+=Max[j];}
    }
    printf("%d\n",sum);
}
int main(){
  //  srand(time(NULL));
    int t=1;0000;
    scanf("%d",&t);

    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}
/*
1101011?0 5 1
001101?00 3 1
101000110 4 0
001011010 4 0
0101?01?? 3 3
00?1000?0 1 2
223413320
  1 1 131
*/