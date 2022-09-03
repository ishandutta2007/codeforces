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
#define last Last
#define MXN 200005
const int mod=1e9+7;
vector<int> v[2005];
void solve(){
    int n;
    scanf("%d",&n);
    printf("? 1\n");
    fflush(stdout);
    vector<int> odd,even;
    int ans[2005];
    for(int i = 1;i<=n;i++){
        scanf("%d",&ans[i]);
        if(ans[i]%2==0)even.pb(i);
        else odd.pb(i);
    }
    if(odd.size()<even.size()){
        for(auto it:odd){
            printf("? %d\n",it);
            fflush(stdout);
            for(int i = 1;i<=n;i++){
                int x;
                scanf("%d",&x);
                if(x==1)v[it].pb(i);
            }
        }
    }
    else{
        for(auto it:even){
            if(it==1){
                for(int i = 1;i<=n;i++){
                    if(ans[i]==1)v[1].pb(i);
                }
            }
            else{
                printf("? %d\n",it);
                fflush(stdout);
                for(int i = 1;i<=n;i++){
                    int x;
                    scanf("%d",&x);
                    if(x==1)v[it].pb(i);
                }
            }
        }
    }
    printf("!\n");
    for(int i = 1;i<=n;i++){
        for(auto it:v[i]){
            printf("%d %d\n",i,it);
        }
    }
    fflush(stdout);
}
/*
void solve(){
    int n;
    scanf("%d",&n);
    int a[400005];
    a[0]=a[n+1]=0;
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    LL ans=0;
    for(int i = 1;i<=n;i++){
        if(a[i]>a[i-1]&&a[i]>a[i+1]){
            int Max=max(a[i-1],a[i+1]);
            ans+=a[i]-Max;
            a[i]=Max;
        }
    }
    for(int i = 1;i<=n+1;i++){
        ans+=abs(a[i]-a[i-1]);
    }
    printf("%lld\n",ans);
}
*/
/*
ax+by<=c;
bx+ay<=d;
*/
int main(){
    int t=1;
    //scanf("%d",&t);
    while(t--)
        solve();
}
/*
2 3 5 6 1 4
*/