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
int S[200005];
void solve(){
    int n;
    scanf("%d",&n);
    fill(S,S+n+1,0);
    int c[200005];
    int ans[200005];
    LL sum=0;
    for(int i = 1;i<=n;i++){
        scanf("%d",&c[i]);
        sum+=c[i];
    }
    sum/=n;
    LL val=0;
    for(int i =n;i>=1;i--){
        val+=S[i];
       // printf("%d %d\n",c[i],val);
            S[i-1]--,S[i-sum]++;
        if(c[i]+val==i)ans[i]=1,sum--;
        else ans[i]=0;
    
    }
    //printf("\n");
    for(int i = 1;i<=n;i++)printf("%d ",ans[i]);
    printf("\n");
}
int main(){
    int t=1;0000;
    scanf("%d",&t);

    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}
/*
UKOKCUEUKCKPNKPKPDEUFUFJUFBFPDPBFIFP
*/