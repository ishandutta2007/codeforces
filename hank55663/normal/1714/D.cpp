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
pair<pii,int> from[105];
void solve(){
    char t[105];
    int dp[105];
    scanf("%s",t+1);
    string s[15];
    int n;
    scanf("%d",&n);
    for(int i=  0;i<n;i++){
        char c[15];
        scanf("%s",c);
        s[i]=string(c);
    }
    int nn=strlen(t+1);
    fill(dp,dp+nn+1,1e9);
    dp[0]=0;
    for(int i = 1;i<=nn;i++){
        for(int j = 0;j<n;j++){
            int ok=1;
            for(int k = 0;k<s[j].size();k++){
                if(i<=k||s[j][s[j].size()-k-1]!=t[i-k]){
                    ok=0;
                }
            }
            if(ok&&i>=s[j].size()){
                for(int k = i-s[j].size();k<i;k++){
                    if(dp[i]>dp[k]+1){
                        dp[i]=dp[k]+1;
                        from[i]=mp(mp(j+1,i-s[j].size()+1),k);
                    }
                }
                
            }
        }
        //printf("%d ",dp[i]);
    }
    if(dp[nn]==1e9)dp[nn]=-1;
    printf("%d\n",dp[nn]);
    if(dp[nn]!=-1){
        int x=nn;
        vector<pii> ans;
        while(x!=0){
            ans.pb(from[x].x);
            x=from[x].y;
        }
        for(auto it:ans)printf("%d %d\n",it.x,it.y);
    }
}
int main(){
    int t=1;00000000;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    
}
/*
*/