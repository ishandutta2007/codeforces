
#pragma GCC optimize("Ofast") 
#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> set_t;
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<double,double>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define index Index
#define Line pll
typedef long long LL;
int main(){
    int n;
    scanf("%d",&n);
    LL l[100005];
    for(int i=0;i<n;i++)
    scanf("%lld",&l[i]);
    int type[100005];
    vector<int> v;
    for(int i=0;i<n;i++){
        char c;
        scanf(" %c",&c);
        if(c=='G'){
            type[i]=5;
            v.pb(i);
        }
        else if(c=='W')
        type[i]=3;
        else
        type[i]=1;
    }
    LL ans=0;
    LL energy=0;
    int havewater=0;
    LL w=0,g=0,wg=0;
    for(int i=0;i<n;i++){
        if(type[i]==1){
            LL inw=min(w,l[i]);
            ans+=inw+inw;
            w-=inw;
            l[i]-=inw;
            //printf("%lld\n",l[i]);
            LL ing=min(g,l[i]);
            ans+=ing*3;
            g-=ing;
            l[i]-=ing;
            LL inwg=min(wg,l[i]);
            ans+=inwg+inwg+inwg;
            wg-=inwg;
            l[i]-=inwg;
            if(havewater){
                ans+=l[i]*4;
            }
            else{
                ans+=l[i]*6;
            }
        }
        else if(type[i]==3){
            ans+=l[i]*2;
            havewater=1;
            w+=l[i];
        }
        else{
            LL inw=min(w,l[i]);
            ans+=inw+inw;
            w-=inw;
            l[i]-=inw;
            wg+=inw*2;
            ans+=l[i]*3;
            g+=l[i];
        }
    }
    printf("%lld\n",ans);
}