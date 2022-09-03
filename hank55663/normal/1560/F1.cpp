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
int cnt[10];
void dfs(vector<int> &v,int k,vector<int> &ans,int bi,int i=0){
    //if(ans.size())printf("%d %d\n",ans.back(),bi);
    if(ans.size()==v.size())return;
    if(bi){
        for(int i = 0;i<=9;i++){
            cnt[i]++;
            int tot=0;
            for(int j=0;j<10;j++){
                if(cnt[j])tot++;
            }
            if(tot<=k){
                ans.pb(i);
                dfs(v,k,ans,1,i+1);
                return;
            }
            cnt[i]--;
        }
    }
    else{
        cnt[v[i]]++;
        int ok=1;
        int tot=0;
        for(int j = 0;j<10;j++)if(cnt[j])tot++;
        if(tot<k){
            ans.pb(v[i]);
            dfs(v,k,ans,bi,i+1);
            return;
        }
        else if(tot==k){
            int Mx=0;
            for(int j = 0;j<10;j++)if(cnt[j])Mx=j;
            for(int j = i+1;j<v.size();j++){
                if(v[j]>Mx){
                    ok=0;
                    break;
                }
                if(v[j]<Mx)break;
            }
            if(ok){
                ans.pb(v[i]);
                dfs(v,k,ans,bi,i+1);
                return;
            }
        }
        cnt[v[i]]--;
        for(int j = v[i]+1;j<=9;j++){
            cnt[j]++;
            int tot=0;
            for(int k=0;k<10;k++){
                if(cnt[k])tot++;
            }
            if(tot<=k){
                ans.pb(j);
                dfs(v,k,ans,1,i+1);
                return;
            }
            cnt[j]--;
        }
    }
}
void solve(){
    int n,k;
    scanf("%d %d",&n,&k);
    vector<int> v;
    while(n)v.pb(n%10),n/=10;
    reverse(v.begin(),v.end());
    vector<int> ans;
    dfs(v,k,ans,0);
    MEM(cnt);
    for(auto it:ans)printf("%d",it);
    printf("\n");
}
int main(){
    int t=1;//00;//00;
    scanf("%d",&t);
    while(t--){
        solve();
    }
 //   printf("0\n1\n2\n");
    //printf("8192\n");
    //printf("%d\n",cnt);
    //printf("%.12f\n",sum/tt);
    return 0;
}
/*
*/