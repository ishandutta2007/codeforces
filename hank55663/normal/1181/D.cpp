#include<bits/stdc++.h>
using namespace std;
#define LL long long
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
#define N 200005
#define rank Rank
#define index Index
pii p[500005];
LL pre[500005];
pll query[500005];
#include <bits/extc++.h>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> set_t;
LL ans[500005];
int main(){
    int n,m,q;
    scanf("%d %d %d",&n,&m,&q);
    for(int i = 1;i<=m;i++){
        p[i]=mp(0,i);
    }
    for(int i= 0;i<n;i++){
        int x;
        scanf("%d",&x);
        p[x].x++;
    }
    sort(p+1,p+m+1);
    LL sum=0;
    pre[0]=0;
    for(LL i = 1;i<=m;i++){
        sum+=p[i].x;
        pre[i]=p[i].x*i-sum;
        //printf("%d\n",pre[i]);
    }
    pre[m+1]=2e18;
    for(int i=0;i<q;i++){
        LL k;
        scanf("%lld",&k);
        query[i]=mp(k,i);
    }
    sort(query,query+q);
    set_t s;
    int now=0;
    for(int i =0;i<q;i++){
        LL k = query[i].x;
        k-=n;
        while(pre[now+1]<k){
            now++;
            s.insert(p[now].y);
        }
        k-=pre[now];
        k--;
        k%=now;
        ans[query[i].y]=*s.find_by_order(k);
    }
    for(int i = 0;i<q;i++)
    printf("%lld\n",ans[i]);
}