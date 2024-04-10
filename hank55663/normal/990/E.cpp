#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define index Index
using namespace std;
typedef long long LL;
LL a[1000005];
int ok[1000005];
int main(){
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    int ok[1000005];
    MEM(ok);
    for(int i=0;i<m;i++){
        int a;
        scanf("%d",&a);
        ok[a]=1;
    }
    vector<int> v;
    for(int i=0;i<n;i++){
        if(!ok[i])
            v.pb(i);
    }
    if(ok[0]){
        printf("-1\n");
        return 0;
    }
    for(int i=1;i<=k;i++){
        scanf("%lld",&a[i]);
    }
    LL ans = 1e18;
    int last_cnt = 0;
    for(int i=k;i>=1;i--){
        if((LL)max(last_cnt,n/i)*a[i]>ans)
        continue;
        int ook=1;
        int now=0,cnt=0;
        while(now<n){
            auto it=upper_bound(v.begin(),v.end(),now);
            it--;
            int last=now;
            now=*it+i;
            cnt++;
            if(last==now){
                ook=0;
                break;
            }
        }
        last_cnt=cnt;
        if(!ook)
        continue;
        ans=min(ans,(LL)cnt*a[i]);
    }
    if(ans==1e18)
    ans=-1;
    printf("%lld\n",ans);
}