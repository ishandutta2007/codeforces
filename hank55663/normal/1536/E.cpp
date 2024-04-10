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
    int n,m;
    scanf("%d %d",&n,&m);
    char c[2005][2005];
    int ans=1,cnt=0;
    for(int i = 0;i<n;i++){
        scanf("%s",c[i]);
        for(int j = 0;j<m;j++){
            if(c[i][j]=='#')ans=ans*2%mod,cnt++;
        }
    }
    if(cnt==n*m)ans=(ans-1+mod)%mod;
    printf("%d\n",ans);
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--)
        solve();
}
/*
2 3 5 6 1 4
*/