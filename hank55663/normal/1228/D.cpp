




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
#define KK 500
#define N 100005
#define MXN 2000005
vector<int> v[100005];
LL mod;
int base=668776;
LL Hash(vector<int> &v){
    LL res=0;
    for(auto it:v){
        res=(res*base+it)%mod;
    }
    return res;
}
int main(){
    srand(time(NULL));
    mod=rand()+1e12+7;
    while(true){
        int ok=1;
        for(LL i = 2;i*i<=mod;i++){
            if(mod%i==0)ok=0;
        }
        if(ok)break;
        mod++;
    }
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 0;i<m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
    }
    map<LL,vector<int> > mm;
    for(int i = 1;i<=n;i++){
        sort(v[i].begin(),v[i].end());
        mm[Hash(v[i])].pb(i);
    }
    if(mm.size()!=3){
        printf("-1\n");
        return 0;
    }
    vector<LL> vv;
    for(auto& it:mm){
        vv.pb(it.y.size());
        if(v[it.y[0]].size()!=n-it.y.size()){
            printf("-1\n");
            return 0;
        }
    }
    if(vv[0]*vv[1]+vv[1]*vv[2]+vv[0]*vv[2]!=m){
        printf("-1\n");
        return 0;
    }
    int ans[100005];
    int cnt=1;
    for(auto& it:mm){
        for(auto it2:it.y){
            ans[it2]=cnt;
        }
        cnt++;
    }
    for(int i = 1;i<=n;i++)
        printf("%d ",ans[i]);
    printf("\n");
    return 0;
}