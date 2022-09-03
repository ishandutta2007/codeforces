#include<bits/stdc++.h>
#pragma optimize(Ofast)
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
#define MXN 500005
LL dp[65][6];
int mod=1e9+7;
int go(string str){
    if(str=="green")return 0;
    if(str=="red")return 1;
    if(str=="white")return 2;
    if(str=="blue")return 3;
    if(str=="orange")return 4;
    if(str=="yellow")return 5;
    assert(0);
}
map<LL,int> m;
set<LL> s;
vector<LL> cal(LL x,LL k){
    if(s.find(x)==s.end()){
      //  printf("%d %d!\n",x,k);
       // for(int j =0;j<6;j++)printf("%lld ",dp[k][j]);
      //  printf("\n");
        return vector<LL>{dp[k][0],dp[k][1],dp[k][2],dp[k][3],dp[k][4],dp[k][5]};
    }
    else{
        if(k==1){
            vector<LL> ans(6,0);
            ans[m[x]]++;
          //  printf("%d?\n",x);
          //  for(int j =0;j<6;j++)printf("%lld ",ans[j]);
          //  printf("\n");
            return ans;
        }
        vector<LL> v1=cal(x*2,k-1),v2=cal(x*2+1,k-1);
        LL res[6]={0,0,0,0,0,0};
        for(int j = 0;j<6;j++){
            LL a=0,b=0;
            for(int x = 0;x<6;x++){
                if(x!=j&&x!=(j+3)%6)a+=v1[x],b+=v2[x];
            }
            res[j]=(a%mod)*(b%mod)%mod;
        }
        vector<LL> ans(6,0);
        if(m.find(x)!=m.end()){
            ans[m[x]]=res[m[x]];
        }
        else{
            for(int j = 0;j<6;j++)ans[j]=res[j];
        }
       //  printf("%d\n",x);
        //    for(int j =0;j<6;j++)printf("%lld ",ans[j]);
         //   printf("\n");
        return ans;
    }
}
void solve(){
    for(int i = 0;i<6;i++){
        dp[1][i]=1;
    }
    int k;
    scanf("%d",&k);
    for(int i = 2;i<=k;i++){
        for(int j = 0;j<6;j++){
            dp[i][j]=(((dp[i-1][0]+dp[i-1][1]+dp[i-1][2]+dp[i-1][3]+dp[i-1][4]+dp[i-1][5])-dp[i-1][j]-dp[i-1][(j+3)%6])%mod+mod)%mod;
            dp[i][j]=dp[i][j]*dp[i][j]%mod;
            dp[i][j]=(dp[i][j]%mod+mod)%mod;
        }
    }
    int n;
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        LL v;
        string str;
        scanf("%lld",&v);
        cin>>str;
        m[v]=go(str);
        while(v){
            s.insert(v);
            v>>=1;
        }
    }
    LL res=0;
    for(auto it:cal(1,k)){
        res+=it;
        res%=mod;
    }
    printf("%lld\n",res);    
}
int main(){

    int t=1;0000;
 //   scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        //cerr<<i<<endl;
        solve();
    }
    return 0;
}
/*
60.0 0.0 50.0 170.0 
3
40.0 0.0 0.0 0.0
5.0 20.0 5.0 170.0
95.0 0.0 95.0 80.0


0.0 1.0 4.0 1.0 
1
0.0 0.0 4.0 0.0
*/