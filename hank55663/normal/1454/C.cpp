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
#define next Next
using namespace std;
int last[200005];
int cnt[200005];
void solve(){
    int n;
    scanf("%d",&n);
    fill(last,last+n+1,0);
    fill(cnt,cnt+n+1,0);
    for(int i = 1;i<=n;i++){
        int x;
        scanf("%d",&x);
        if(last[x]!=i-1)cnt[x]++;
        last[x]=i;
    }
    int ans=1e9;
    for(int i = 1;i<=n;i++){
        if(last[i]!=0){
            if(last[i]==n)
            ans=min(ans,cnt[i]);
            else
            ans=min(ans,cnt[i]+1);
        }
    }
    printf("%d\n",ans);
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
}