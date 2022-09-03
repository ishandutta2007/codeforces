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
    char at[100005];
    scanf("%s",at);
    char c[10005];
    scanf("%s",c);
    int loc[365];
    for(int i = 0;at[i]!=0;i++)loc[at[i]]=i;
    int ans=0;
    for(int i = 0;c[i+1]!=0;i++){
        ans+=abs(loc[c[i]]-loc[c[i+1]]);
    }
    printf("%d\n",ans);
}

int main(){

    int t=1;0000;
    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
       // cerr<<i<<endl;
        solve();
    }
    return 0;
}
/*
ACBABC
ACBCAB
ACABCB
*/