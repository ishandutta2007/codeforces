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
void solve(){
    int n,l;
    scanf("%d %d",&n,&l);
    int x[105];
    for(int i = 0;i<n;i++)scanf("%d",&x[i]);
    int ans=0;
    for(int i = 0;i<l;i++){
        int cnt=0;
        for(int j = 0;j<n;j++){
            if(x[j]&(1<<i)){
                cnt++;
            }
        }
        if(cnt*2>=n)ans+=(1<<i);
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