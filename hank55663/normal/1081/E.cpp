
 /*#include<utility>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
#include<iostream>
#include<string.h>*/
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
typedef long long LL ;
int main(){
    vector<LL> v;
    set<LL> s;
    for(LL i=1;i<=200000;i++)
    v.pb(i*i),s.insert(i*i);
    int now=0;
    int n;
    scanf("%d",&n);
    LL ans[100005];
    ans[0]=0;
    LL sum[100005];
    sum[0]=0;
    for(int i=2;i<=n;i+=2)
    scanf("%lld",&ans[i]);
    for(int i=1;i<=n;i+=2){
        while(now!=v.size()){
            if(s.find(v[now]+ans[i+1])!=s.end()){
                break;
            }
            now++;
        }
        if(now==v.size()){
            printf("No\n");
            return 0;
        }
        ans[i]=v[now]-sum[i-1];
        sum[i]=sum[i-1]+ans[i];
        sum[i+1]=sum[i]+ans[i+1];
        LL target=v[now]+ans[i+1];
        while(v[now]!=target)now++;
    }
    printf("Yes\n");
    for(int i=1;i<=n;i++)
    printf("%lld ",ans[i]);
}
/*
0 1 0
0 0 1
1 0 1
*/