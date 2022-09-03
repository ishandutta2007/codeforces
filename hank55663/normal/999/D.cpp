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
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int a[200005];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int cnt[200005];
    MEM(cnt);
    for(int i=0;i<n;i++){
        cnt[a[i]%m]++;
    }
    set<int> s;
    for(int i=0;i<m;i++){
        if(cnt[i]<n/m){
            s.insert(i);
        }
    }
    LL ans=0;
    for(int i=0;i<n;i++){
        if(cnt[a[i]%m]>n/m){
            cnt[a[i]%m]--;
            auto it=s.lower_bound(a[i]%m);
            if(it==s.end()){
                ans+=*s.begin()+m-a[i]%m;
                a[i]+=*s.begin()+m-a[i]%m;
                cnt[*s.begin()]++;
                if(cnt[*s.begin()]==n/m)
                s.erase(s.begin());
            }
            else{
                ans+=*it-a[i]%m;
                a[i]+=*it-a[i]%m;
                cnt[*it]++;
                if(cnt[*it]==n/m)
                s.erase(it);
            }
        }
    }
    printf("%lld\n",ans);
    for(int i=0;i<n;i++)
    printf("%d ",a[i]);
    printf("\n");
}