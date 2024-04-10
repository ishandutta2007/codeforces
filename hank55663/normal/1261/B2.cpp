#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acosl(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MXN 200005

#include <bits/extc++.h>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> set_t;

struct cmp{
    bool operator()(const pii &a,const pii &b){
        if(a.x!=b.x)return a.x<b.x;
        else return a.y>b.y;
    }
};
int main(){
    int n;
    scanf("%d",&n);
    int a[200005];
    std::priority_queue<pii,vector<pii>,cmp> pq;
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
        pq.push(mp(a[i],i));
    }
    int q;
    scanf("%d",&q);
    pair<pii,int> p[200005];
    for(int i = 0;i<q;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        p[i]=mp(mp(x,y),i);
    }
    sort(p,p+q);
    int now=0;
    set_t s;
    int ans[200005];
    for(int i = 0;i<q;i++){
        while(now<p[i].x.x){
            pii p=pq.top();
           // printf("%d\n",p.y);
            pq.pop();
            s.insert(p.y);
            now++;
        }
        ans[p[i].y]=a[*s.find_by_order(p[i].x.y-1)];
    }
    for(int i = 0;i<q;i++){
        printf("%d\n",ans[i]);
    }
}
/*
9 4 
1 0 1 0 1 0 0 1 1
1 2
2 4
2 3
4 5
1 6
6 7
6 8
7 9

*/