#include<bits/stdc++.h>

/*#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
#define mp make_pair
#define pb push_back
#define pll pair<LL,LL>
#define pii pair<int,int>
#define y second
#define x first
#define LL long long 
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
int val[300005];
int a[300005];
#include <bits/extc++.h>
using namespace __gnu_pbds;
typedef tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update> set_t;

int ans[300005];
void solve(){   
    int n,q;
    scanf("%d %d",&n,&q);
    for(int i = 1;i<=n;i++)scanf("%d",&a[i]);
    set_t s;
    for(int i = 1;i<=n;i++){
        if(a[i]>i){
            val[i]=-1;
        }
        else{
            int Max=i,Min=-1;
            while(Max>Min+1){
                int mid=(Max+Min)/2;
                int sum=s.size()-s.order_of_key(mp(mid,0));
                if(a[i]>=i-sum){
                    Min=mid;
                }
                else{
                    Max=mid;
                }
            }
            val[i]=Min;
            s.insert(mp(val[i],i));
        }
     //   printf("%d ",val[i]);
    }
   // printf("\n");
    pair<pii,int> query[300005];
    for(int i = 1;i<=q;i++){
        int l,r;
        scanf("%d %d",&l,&r);
        r = n-r;
        query[i]=mp(mp(r,l),i);
    }
    sort(query+1,query+q+1);
    int now=1;
    s.clear();
    for(int i = 1;i<=q;i++){
        while(query[i].x.x>=now){
            s.insert(mp(val[now],now));
            now++;
        }
        ans[query[i].y]=s.size()-s.order_of_key(mp(query[i].x.y,0));
    }
    for(int i = 1;i<=q;i++){
        printf("%d\n",ans[i]);
    }
}
int main(){
    int t=1;
    //scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*
100
5
5 4
4 2
4 2 3
5 4 2 3 1
*/