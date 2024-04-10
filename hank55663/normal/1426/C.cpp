#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define pll pair<LL,LL>
#define mp make_pair
#define x first
#define y second
#define pii pair<int,int>
using namespace std;
void solve(){
    int n;
    scanf("%d",&n);
    int ans=1e9;
    for(int i = 1;i*i<=n;i++){
        int x=(n+i-1)/i;
        ans=min(ans,x+i-2);
    }
    printf("%d\n",ans);
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
       // printf("Case #%d: ",T++);
        solve();
    }
}