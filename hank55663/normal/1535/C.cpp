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
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define last Last
#define MXN 200005
const int mod=1e9+7;
void solve(){
    char c[200005];
    scanf("%s",c);
    LL ans=0;
    int sum=0;
    for(int i = 0;c[i]!=0;i++){
        if(c[i]=='?'||c[i]-'0'==i%2)sum++;
        else sum=0;
        ans+=sum;
    }
  //   printf("%lld\n",ans);
    sum=0;
    for(int i = 0;c[i]!=0;i++){
        if(c[i]=='?'||c[i]-'0'!=i%2)sum++;
        else sum=0;
        ans+=sum;
    }
    // printf("%lld\n",ans);
    sum=0;
    for(int i = 0;c[i]!=0;i++){
        if(c[i]=='?')sum++;
        else sum=0;
        ans-=sum;
    }
    printf("%lld\n",ans);
} 
/*
C[n-(k-1)*(i-1)][n-i-(k-1)*(i+1)]
//[n-k*i+i-k+1][i]
*/
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--)
        solve();
}
/*
2 3 5 6 1 4
*/