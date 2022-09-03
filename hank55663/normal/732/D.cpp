#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define less Less
#define EPS 1e-3
#define arg ARG
#define pdd pair<double,double>
#define cpdd const pdd
vector<int> v[100005];
int main() {
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 1;i<=n;i++){
        int d;
        scanf("%d",&d);
        v[d].pb(i);
    }
    int a[100005];
    for(int i = 1;i<=m;i++)
        scanf("%d",&a[i]);
    int Max=n+1,Min=0;
    while(Max>Min+1){
        int mid=(Max+Min)/2;
        vector<pii> vv;
        int ok=1;
        for(int i = 1;i<=m;i++){
            if(upper_bound(v[i].begin(),v[i].end(),mid)==v[i].begin()){
                ok=0;
            }
            else{
                vv.pb(mp(*(upper_bound(v[i].begin(),v[i].end(),mid)-1),i));
            }
        }
        if(ok){
            int cnt=1;
            sort(vv.begin(),vv.end());
            for(auto it:vv){
                cnt+=a[it.y];
                if(cnt>it.x){
                    ok=0;
                    break;
                }
                cnt++;
            }
        }
        if(ok){
            Max=mid;
        }
        else{
            Min=mid;
        }
    }
    if(Max==n+1)Max=-1;
    printf("%d\n",Max);
    return 0;
}