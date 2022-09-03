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
int mod=998244353;
int f[100005];
int Find(int x){
    if(f[x]==x)return x;
    return f[x]=Find(f[x]);
}
int main(){
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    int x[100005];
    for(int i=0;i<k;i++)
    scanf("%d",&x[i]);
    pair<int,pii> p[100005];
    for(int i=0;i<m;i++){
        int x,y,w;
        scanf("%d %d %d",&x,&y,&w);
        p[i]=mp(w,mp(x,y));
    }
    sort(p,p+m);
    int Max=m,Min=-1;
    while(Max>Min+1){
        int mid=(Max+Min)/2;
        for(int i=1;i<=n;i++)
        f[i]=i;
        for(int i=0;i<=mid;i++){
            f[Find(p[i].y.x)]=Find(p[i].y.y);
        }
        int ans=Find(x[0]);
        int ok=0;
        for(int i=1;i<k;i++){
            //printf("%d %d\n",ans,Find(x[i]));
            if(Find(x[i])!=ans)
            ok=1;
        }
        if(ok)Min=mid;
        else Max=mid;
       // printf("%d %d\n",Max,Min);
    }
    for(int i=0;i<k;i++)
    printf("%d ",p[Max].x);
    printf("\n");
}
/*
0 1 0
0 0 1
1 0 1
*/