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
LL S[1<<18];
void add(int x,int k){
    for(int i=x;i<(1<<18);i+=i&-i){
        S[i]+=k;
    }
}
int query(LL target){
    LL temp=0,res=0;
    for(int i=17;i>=0;i--){
        if(temp+S[res+(1<<i)]<target){
            res+=(1<<i);
            temp+=S[res];
        }
    }
    //printf("%lld\n",temp);
    return res+1;
}
LL querysum(int x){
    LL res=0;
    for(int i=x;i>0;i-=i&-i)
    res+=S[i];
    return res;
}
int main(){
    int n,q;
    scanf("%d %d",&n,&q);
    int a[200005];
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        add(i,a[i]);
    }
    while(q--){
        int p,x;
        scanf("%d %d",&p,&x);
        add(p,-a[p]);
        a[p]=x;
        add(p,a[p]);
        LL now=a[1];
        int ok=0;
        while(true){
          //  printf("%d\n",now);
            int index=query(2*now);
            //printf("%d\n",index);
            if(index==262144)
            break;
            if(querysum(index-1)==a[index]){
                printf("%d\n",index);
                ok=1;
                break;
            }
            now=querysum(index);
        }
        if(!ok)
        printf("-1\n");
    }
}