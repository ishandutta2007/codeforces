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
void solve(){
    int n;
    scanf("%d",&n);
    vector<int> val[2];
    for(int i = 0;i<n;i++){
        int x;
        scanf("%d",&x);
        val[x&1].pb(x);
    }
    int ok=1;
    for(int t=0;t<2;t++){
        for(int j = 0;j+1<val[t].size();j++){
            if(val[t][j]>val[t][j+1])ok=0;
        }
    }
    if(ok)printf("YES\n");
    else printf("NO\n");
}
int main(){
    int t=1;0000;
    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}