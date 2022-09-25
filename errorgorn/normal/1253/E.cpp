#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m;
int pos[100];
int range[100];
bool filled[100005];
int memo[100005];
int dp(int i){
    if (i>m) return 0;
    if (memo[i]!=-1) return memo[i];
    if (filled[i]) return memo[i]=dp(i+1);

    int ans=m-i+1;
    int diff;
    for (int x=0;x<n;x++){
        if (i<pos[x]-range[x]){
            diff=pos[x]-range[x]-i;
            //printf("staellite %d: %d %d\n",x,pos[x]-range[x]-diff,pos[x]+range[x]+diff);
            ans=min(ans, diff+dp(pos[x]+range[x]+diff+1));
        }
    }

    return memo[i]=ans;
}

int main(){
    scanf("%d%d",&n,&m);
    for (int x=0;x<n;x++){
        scanf("%d%d",&pos[x],&range[x]);
        for (int y=max(1,pos[x]-range[x]);y<=min(m,pos[x]+range[x]);y++){
            filled[y]=true;
        }
    }

    memset(memo,-1,sizeof(memo));
    printf("%d\n",dp(1));
}