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
#define MXN 205
struct Line{
    LL a,b;
    LL x;
};
int op;
bool operator<(const Line &p,const Line &q){
    if(op==0)return p.a<q.a;
    else return p.x<q.x;
}
void add_Line(set<Line> &s,Line l){
    op=0;
    auto it=s.lower_bound(l);
    if(it!=s.end()&&it->a==l.a&&it->b>=l.b)return;
    else{
        if(it!=s.end()&&it->a==l.a&&it->b<l.b){
            s.erase(it);
        }
        it=s.lower_bound(l);
        if(it!=s.begin()&&it!=s.end()){
            auto it2=prev(it);
            LL x=(it2->b-l.b)/(l.a-it2->a),x2=(l.b-it->b)/(it->a-l.a);
            if(x>=x2)return;
        }

        while(it!=s.end()){
         //   printf("!\n");
            Line l1=*it;
            it=next(it);
            s.erase(l1);
            int x=(l.b-l1.b)/(l1.a-l.a);

            if(it!=s.end()&&it->x<=x)continue;
            else{
                l1.x=x;
                s.insert(l1);
                break;
            }
        }
        it=s.lower_bound(l);
        LL x=-1e9-7;
        while(it!=s.begin()){
            //printf("!\n");
            auto it2=prev(it);
            x=(it2->b-l.b)/(l.a-it2->a);
            if(it2->x>=x){
                s.erase(it2);
                x=-1e9-7;
            }
            else{
                break;
            }
        }
        l.x=x;
        s.insert(l);
    }
}
LL query(set<Line> &s,int p){
    if(s.empty())return -2e18;
    op=1;
    Line l;
    l.x=p;
    auto it=prev(s.upper_bound(l));
    return it->a*p+it->b;
}
LL ans[300005];
LL event[300005];
LL a[300005];
LL b[300005];
LL p[300005];
LL re[300005];
void dc(int l,int r){

    if(l==r)return ;
   
    int mid=(l+r)/2;
    dc(l,mid);
    dc(mid+1,r);
    // printf("!%d %d\n",l,r);
    multiset<pii> s;
    for(int i = l;i<=mid;i++){
        if(event[i]==1){
            s.insert(mp(a[i],b[i]));
        }
        else if(event[i]==2&&re[i]>=l&&re[i]<=mid){
            assert(s.find(mp(a[re[i]],b[re[i]]))!=s.end());
            s.erase(s.find(mp(a[re[i]],b[re[i]]))); 
        }
    }
    
    for(int i = mid+1;i<=r;i++){
        if(event[i]==2&&re[i]>=l&&re[i]<=mid){
            //printf("??\n");
assert(s.find(mp(a[re[i]],b[re[i]]))!=s.end());
            s.erase(s.find(mp(a[re[i]],b[re[i]])));
             
           // printf("???\n");
        }
    }
  //  printf("!!\n");
    set<Line> st;
    for(auto it:s){
        Line l;
        l.a=it.x;
        l.b=it.y;
        add_Line(st,l);
    }
    for(int i=r;i>mid;i--){
        if(event[i]==3){
            ans[i]=max(ans[i],query(st,p[i]));
        }
        else if(event[i]==2&&re[i]>=l&&re[i]<=mid){
            Line l;
            l.a=a[re[i]];
            l.b=b[re[i]];
            add_Line(st,l);
        }
    }
  //  printf("?%d %d\n",l,r);
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
        scanf("%lld",&event[i]);
        if(event[i]==1){
            scanf("%lld %lld",&a[i],&b[i]);
        }
        else if(event[i]==2){
            scanf("%lld",&re[i]);
        }
        else{
            scanf("%lld",&p[i]);
            ans[i]=-2e18;
        }
    }
    dc(1,n);
    for(int i = 1;i<=n;i++){
        if(event[i]==3){
            if(ans[i]==-2e18){
                printf("EMPTY SET\n");
            }
            else
            printf("%lld\n",ans[i]);
        }
    }
}
/*

*/