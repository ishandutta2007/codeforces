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
void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    char s[200005],t[200005];
    scanf("%s %s",s,t);
    int dp1[200005],dp2[200005];
    int now=0;
    for(int i = 0;i<n;i++){
        if(s[i]==t[now]){
            dp1[now]=i;
            now++;
            //printf("%d ",i);
        }
        if(now==m)break;
    }
   // printf("\n");
    now=m-1;
    for(int i = n-1;i>=0;i--){
      //  printf("%c %c %d\n",s[i],t[now],now);
        if(s[i]==t[now]){
            dp2[now]=i;
          //  printf("%d ",i);
            now--;
        }
        if(now==-1)break;
    }
   // printf("\n");
    int Max=0;
    for(int i = 0;i<m-1;i++){
        Max=max(Max,dp2[i+1]-dp1[i]);
    }
    printf("%d\n",Max);
}
int main(){
    int t=1;
  //  scanf("%d",&t);
    while(t--){
        solve();
    }
    //printf("8192\n");
    //printf("%d\n",cnt);
    //printf("%.12f\n",sum/tt);
    return 0;
}
/*
3 1 4 2
3 3 4 4
*/