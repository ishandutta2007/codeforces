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
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define less Less
#define EPS 1e-4
#define arg ARG
#define pdd pair<double,double>
#define cpdd const pdd
#define MXN 30005
#define next Next
#define index Index
bool cmp(const pii &a,const pii &b){
    return a.y<b.y;
}
int main(){
    int n;
    scanf("%d",&n);
    int a[200005];
    int last[200005];
    fill(last,last+n+1,-1);
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    int q;
    scanf("%d",&q);
    vector<pii> event;
    event.pb(mp(0,0));
    for(int i = 1;i<=q;i++){
        int op;
        scanf("%d",&op);
        if(op==1){
            int p,x;
            scanf("%d %d",&p,&x);
            auto it=lower_bound(event.begin(),event.end(),mp(0,last[p]),cmp);
            if(it!=event.end())
                a[p]=max(a[p],it->x);
            a[p]=x;
            last[p]=i;
        }
        else{
            int x;
            scanf("%d",&x);
            while(!event.empty()&&event.back().x<=x){
                event.pop_back();
            }
            event.pb(mp(x,i));
        }
    }
    for(int i = 1;i<=n;i++){
        auto it=lower_bound(event.begin(),event.end(),mp(0,last[i]),cmp);
        if(it!=event.end())
            a[i]=max(a[i],it->x);
        printf("%d ",a[i]);
    }
    printf("\n");
}
/*

100
2 3
0 500000000 1000000000
1000000000 1000000000 1000000000
 */