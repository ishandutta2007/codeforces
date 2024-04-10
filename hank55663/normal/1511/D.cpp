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
const int mod=1e9+7;
vector<int> v[26];
int Index[26];
vector<int> ans;
void dfs(int x){
    //printf("%d\n",x);
    while(Index[x]!=v[x].size()){
        Index[x]++;
        int last=Index[x]-1;
        dfs(v[x][last]);
        ans.pb(v[x][last]);
    }
}
int cnt[26][26];
void solve(){
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i = 0;i<k;i++){
        for(int j = 0;j<k;j++){
            v[i].pb(j);
        }
    }
    //ans.pb(0);
    dfs(0);
    int last=0;
    printf("a");
    for(int i = 1;i<n;i++){
        printf("%c" ,ans[(i-1)%ans.size()]+'a');
        if(i!=0){
            cnt[last][ans[(i-1)%ans.size()]]++;
        }
        last=ans[(i-1)%ans.size()];
    }
   /* int Max=0,Min=1e9;
    for(int i =0;i<k;i++){
        for(int j = 0;j<k;j++){
            Max=max(Max,cnt[i][j]);
            Min=min(Min,cnt[i][j]);
        }
    }
    printf("\n");
    printf("%d %d\n",Max,Min);*/
    printf("\n");
    
}
int main(){
    int t=1;
    //scanf("%d",&t);
    //for(int i = 2)
    while(t--){
        solve();
    }
}