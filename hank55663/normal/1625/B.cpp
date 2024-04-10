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
vector<int> v[150005];
void solve(){
    int n;
    scanf("%d",&n);
    int a[150005];
    for(int i = 0;i<n;i++)scanf("%d",&a[i]);
    for(int i = 0;i<n;i++){
        v[a[i]].pb(i);
    }
    int ans=-1;
    for(int i = 0;i<n;i++){
        for(int j = 0;j+1<v[a[i]].size();j++){
            ans=max(ans,v[a[i]][j]+n-v[a[i]][j+1]);
        }
        v[a[i]].clear();
    }
    printf("%d\n",ans);
}
int main(){
    int t=1;0000;
    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}