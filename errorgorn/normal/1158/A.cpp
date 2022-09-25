#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
int n,m;
ll nrr[100005];
ll mrr[100005];
ll max_n=-1,min_m=1123456789,total_n,_2max_n=-1;
ll ans;
bool add=true;
int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d%d",&n,&m);
    for (int x=0;x<n;x++){
        scanf("%lld",&nrr[x]);
        if (nrr[x]>=max_n){
            _2max_n=max_n;
            max_n=nrr[x];
        }
        else if (nrr[x]>_2max_n){
            _2max_n=nrr[x];
        }
        total_n+=nrr[x];
    }
    for (int x=0;x<m;x++){
        scanf("%lld",&mrr[x]);
        min_m=min(min_m,mrr[x]);
    }
    if (max_n>min_m){
        printf("-1\n");
        return 0;
    }
    for (int x=0;x<m;x++){
        ans+=total_n+mrr[x]-max_n;
        if (mrr[x]==max_n){
            add=false;
        }
    }
    if (add){
        if (_2max_n==-1){
            printf("-1\n");
            return 0;
        }
        else{
            ans+=max_n-_2max_n;
        }
    }
    printf("%lld\n",ans);
}