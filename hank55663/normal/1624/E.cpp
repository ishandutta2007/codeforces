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
int dp[1005];
int from[1005];
void solve(){
    MEM(dp);
    int n,mm;
    scanf("%d %d",&n,&mm);
    char c[1005][1005];
    map<string,pair<int,pii> > m;    
    for(int i = 0;i<n;i++){
        scanf("%s",c[i]);
        for(int j = 0;c[i][j]!=0;j++){
            if(c[i][j+1]!=0){
                string tmp;
                tmp+=c[i][j];
                tmp+=c[i][j+1];
                m[tmp]=mp(i+1,mp(j+1,j+2));
                if(c[i][j+2]!=0){
                    tmp+=c[i][j+2];
                     m[tmp]=mp(i+1,mp(j+1,j+3));
                }
            }
            // for(auto it:m)printf("%s %d %d %d\n",it.x.c_str(),it.y.x,it.y.y.x,it.y.y.y);
        }
        
    }
   
    char res[100005];
    scanf("%s",res+1);
    dp[0]=1;
    for(int i=2;i<=mm;i++){
        string tmp="";
        tmp+=res[i-1];
        tmp+=res[i];
        if(m.find(tmp)!=m.end()&&dp[i-2]){
            dp[i]=1;
            from[i]=i-2;
        }
        if(i>2){
            tmp=res[i-2]+tmp;
             if(m.find(tmp)!=m.end()&&dp[i-3]){
                dp[i]=1;
                from[i]=i-3;
            }
        }
    }
    if(dp[mm]==0){
        printf("-1\n");
        return;
    }
    int now=mm;
    vector<pair<int,pii> > v;
    while(now){
        string tmp;
        tmp+=res[now-1];
        tmp+=res[now];
        if(from[now]==now-2){
            v.pb(m[tmp]);
        }
        else{
            tmp=res[now-2]+tmp;
            v.pb(m[tmp]);
        }
        now=from[now];
    }
    reverse(v.begin(),v.end());
    printf("%d\n",v.size());
    for(auto it:v){
        printf("%d %d %d\n",it.y.x,it.y.y,it.x);
    }
}
int main(){
    int t=1;0000;
    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}