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
#define S_MUL 0.6f
#define S_LEN 10000
#define T_CNT 8
#define E_CNT 8
void solve(){
    char c[200005];
    int ans=0;
    scanf("%s",c);
    for(int i=0;c[i]!=0;i++)ans+=c[i]-'a'+1;
    int n=strlen(c);
    if(n%2==0){
        printf("Alice %d\n",ans);
    }
    else{
        int a=min(c[0],c[n-1])-'a'+1;
        ans-=2*a;
        if(ans>0)printf("Alice %d\n",ans);
        else printf("Bob %d\n",-ans);
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
*/