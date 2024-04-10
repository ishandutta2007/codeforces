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
#define index Index
#define MXN 10000
const int mod=998244353;
void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    map<pii,int> ans;
    vector<int> v;
    vector<vector<int> > res;
    int ok=1;
    for(int i = 0;i<n;i++){
        int a[200005],b[200005];
        vector<int> tmp;
        for(int j = 0;j<m;j++){
            scanf("%d",&a[j]);
            b[j]=a[j];
            tmp.pb(a[j]);
        }
        sort(b,b+m);
        res.pb(tmp);
        for(int j = 0;j<m;j++){
            if(a[j]!=b[j]){
                v.pb(j);
            }
        }
        if(v.size()>=3)ok=0;
        if(v.size()==2){
            ans[mp(v[0],v[1])]++;
        }
        v.clear();
    }
    if(!ok||ans.size()>=2){
        printf("-1\n");
    }
    else{
        if(ans.empty()){
            printf("1 1\n");
        }
        else{
            int a=ans.begin()->x.x,b=ans.begin()->x.y;
            for(auto &it:res){
                swap(it[a],it[b]);
                for(int j = 1;j<it.size();j++){
                    if(it[j]<it[j-1]){
                        printf("-1\n");
                        return;
                    }
                }
            }
            printf("%d %d\n",ans.begin()->x.x+1,ans.begin()->x.y+1);
        }
    }
}
int main(){
   // srand(time(NULL));
    int t=1;0000;
    scanf("%d",&t);

    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}