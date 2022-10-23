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
    int n;
    scanf("%d",&n);
    int a[200005];
    int sum=0;
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    if(sum%2==0){
        vector<pii> v;
        for(int i = 1;i<n;i++){
            if(a[i]==0)v.pb(mp(i-1,i-1));
            else if(sum>0){
                if(a[i]==1)v.pb(mp(i-1,i)),i++,sum-=2;
                else v.pb(mp(i-1,i-1));
            }
            else if(sum<0){
                if(a[i]==-1)v.pb(mp(i-1,i)),i++,sum+=2;
                else v.pb(mp(i-1,i-1));
            }
            else v.pb(mp(i-1,i-1));
        }
        if(v.size()&&v.back().y==n-1);
        else v.pb(mp(n-1,n-1));
        printf("%d\n",v.size());
        for(auto it:v)printf("%d %d\n",it.x+1,it.y+1);
    }
    else{
        printf("-1\n");
    }
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}