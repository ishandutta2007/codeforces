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
int cnt[500005];
void solve(){
    int n,x;
    scanf("%d %d",&n,&x);
    for(int i = 0;i<n;i++){
        int a;
        scanf("%d",&a);
        cnt[a]++;
    }
    for(int i = 1;i<x;i++){
        cnt[i+1]+=cnt[i]/(i+1);
        cnt[i]%=(i+1);
        if(cnt[i]){
            printf("No\n");
            return;
        }
    }
    printf("Yes\n");
}
int main(){
    int t=1;
   // scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}