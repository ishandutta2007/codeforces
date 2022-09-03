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
    char c[55],t[55];
    scanf("%s %s",c,t);
    int n=strlen(c);
    if(strlen(t)==1){
        if(t[0]=='a')printf("1\n");
        else{
            printf("%lld\n",1ll<<n);
        }
    }
    else{
        for(int j = 0;t[j]!=0;j++){
            if(t[j]=='a'){
                printf("-1\n");
                return;
            }
        }
        printf("%lld\n",1ll<<n);
    }
}
int main(){
    srand(time(NULL));
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
  40018/76270
*/