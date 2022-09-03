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
#define MXN 10005
//#define less Less
#define N (1<<20)
#include <bits/extc++.h>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> set_t;
bool cmp(const pii &p,const pii &q){
     if(p.y!=q.y)
    return p.y>q.y;
    return p.x<q.x;
}
int main(){
    int n;
    scanf("%d",&n);
    pii p[200005];
    for(int i =0;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        p[i]=mp(x,y);
    }
    sort(p,p+n,cmp);
    int l =0;
    LL ans=0;
    set_t s;
    for(int i = 0;i<n;i++){
        s.insert(p[i].x);
        if(i==n-1||p[i+1].y!=p[i].y){
            ans+=(LL)s.size()*((LL)s.size()+1)/2;
            LL last=0;
            while(l<=i){
                LL x=s.order_of_key(p[l].x);
                ans-=(x-last)*(x-last+1)/2;
                last=x+1;
                l++;
            }
            ans-=(LL)(s.size()-last)*((LL)s.size()-last+1)/2;
        }
    }
    printf("%lld\n",ans);
    
}
/*
1 
2 6 
3 5 
4
*/