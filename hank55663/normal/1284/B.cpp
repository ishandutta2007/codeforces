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
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MXN 200005
int main(){ 
    int n;
    scanf("%d",&n);
    vector<int> v1,v2;
    LL cnt=0;
    for(int i = 0;i<n;i++){
        int k;
        scanf("%d",&k);
        vector<int> v;
        int ok=0;
        for(int j=0;j<k;j++){
            int x;
            scanf("%d",&x);
            if(!v.empty()&&v.back()<x)ok=1;
            v.pb(x);
        }
        cnt+=ok;
        if(!ok){
            v1.pb(v.back());
            v2.pb(v[0]);
            //p.pb(mp(v.back(),v[0]));
        }
    }
    LL ans=cnt*n*2-cnt*cnt;
    sort(v1.begin(),v1.end());
    for(auto it:v2){
        ans+=lower_bound(v1.begin(),v1.end(),it)-v1.begin();
    }
    printf("%lld\n",ans);
}