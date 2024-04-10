#include<bits/stdc++.h>
//#include<bits/extc++.h>
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> set_t;
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<double,double>
#define pb push_back
#define x first
#define y second
//#define sqr(x) ((x)*(x))
#define EPS 1e-7
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define Line pair<pii,pii> 
typedef long long LL;
#define hash Hash
#define MAXN 605
int main(){
    int n;
    scanf("%d",&n);
    int d[130];
    for(int i=0;i<n;i++){
        scanf("%d",&d[i]);
    }
    sort(d,d+n);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int x=d[i],y=d[j];
            vector<int> fac;
            for(int k=1;k*k<=x;k++){
                if(x%k==0){
                    fac.pb(k);
                    if(k*k!=x)
                        fac.pb(x/k);
                }
            }
            for(int k=1;k*k<=y;k++){
                if(y%k==0){
                    fac.pb(k);
                    if(k*k!=y)
                        fac.pb(y/k);
                }
            }
            sort(fac.begin(),fac.end());
            if(fac.size()==n){
                int ok=1;
                for(int i=0;i<n;i++)
                    if(fac[i]!=d[i])
                        ok=0;
                if(ok){
                    printf("%d %d\n",d[i],d[j]);
                    return 0;
                }
            }
        }
    }
}