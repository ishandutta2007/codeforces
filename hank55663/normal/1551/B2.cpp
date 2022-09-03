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
vector<int> v[200005];
void solve(){
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i = 1;i<=n;i++)v[i].clear();
    int cnt[200005];
    fill(cnt,cnt+n+1,0);
    int a[200005];
    for(int i= 0;i<n;i++){
        scanf("%d",&a[i]);
        cnt[a[i]]++;
        v[a[i]].pb(i);
    }
    int ans[200005];
    fill(ans,ans+n,0);
   // int ans=0;
    int tot=0;
    vector<int> tmp;
    for(int i = 1;i<=n;i++){
        if(cnt[i]>=k){
           // ans++;
            for(int j =0;j<k;j++)ans[v[i][j]]=j+1;
        }
        else{ tot+=cnt[i];
        for(auto it:v[i])tmp.pb(it);
        }
    }
    for(int i = 0;i+k<=tmp.size();i+=k){
        for(int j = i;j<i+k;j++){
            ans[tmp[j]]=j-i+1;
        }
    }
    for(int i = 0;i<n;i++)printf("%d ",ans[i]);
    printf("\n");
    //printf("%d\n",ans+tot/k);
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    //printf("%.12f\n",sum/tt);
    return 0;
}
/*
3 3 3 4 4 4 5 5 5 6 6 6
3 3 7 3 25
*/