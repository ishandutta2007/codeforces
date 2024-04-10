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
    int n,k;
    scanf("%d %d",&n,&k);
    vector<pii> v;
    int cnt=0;
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        if(x==1)
        cnt++;
        else{
            if(cnt)
            v.pb(mp(1,cnt));
            v.pb(mp(x,1));
            cnt=0;
        }
    }
    if(cnt)
    v.pb(mp(1,cnt));
    int ans=0;
    for(int j=0;j<v.size();j++){
        for(int kk=0;kk<v[j].y;kk++){
            v[j].y-=kk;
            //printf("%d %d\n",j,k);
            LL pro=1,sum=0;
            for(int i=j;i<j+80&&i<v.size();i++){
                if(v[i].x==1){
                    if(pro%k==0){
                        LL target=pro/k;
                        if(target>sum&&target<=sum+v[i].y)
                        ans++;
                    }
                    sum+=v[i].y;
                }
                else{
                    LL last=pro;
                    pro*=v[i].x;
                    if(pro%v[i].x!=0||pro/v[i].x!=last||pro>(LL)2e18+1)
                    break;
                    sum+=v[i].x;
             //       printf("%lld %lld %lld %lld\n",sum,k,pro,ans);
                    if(pro==sum*k){
                        ans++;
                    }
                }
           //  printf("%d %lld %lld\n",ans,pro,sum);
            }
            v[j].y+=kk;
            //printf("\n");
        }
      
    }
    printf("%d\n",ans);
}