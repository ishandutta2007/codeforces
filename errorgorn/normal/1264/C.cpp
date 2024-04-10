#include <cstdio>
#include <utility>
#include <iostream>
#include <set>
using namespace std;
typedef pair<long long, long long> ii;
int n,q;
int arr[200005];
const int MOD=998244353;

long long qexp(int b,int pow){
    if (pow==0) return 1;
    if (pow==1) return b;
    
    long long h=qexp(b,pow>>1);
    h=(h*h)%MOD;
    if (pow&1) h=(h*b)%MOD;
    return h;
}

struct node{
    int s,e,m;
    ii curr,checkpoint;
    node *l, *r;
    
    ii inline merge(ii j,ii i){
        ii res;
        res.first=(i.first*j.first)%MOD;
        res.second=(i.second*j.first+j.second)%MOD;
        return res;
    }
    
    node(int _s,int _e){
        s=_s,e=_e,m=(s+e)>>1;
        if (s!=e){
            l=new node(s,m);
            r=new node(m+1,e);
            
            curr=merge(l->curr,r->curr);
            checkpoint=merge(l->checkpoint,r->checkpoint);
        }
        else{
            curr=ii(arr[s],1);
            checkpoint=ii(arr[s],(1-arr[s]+MOD)%MOD);
        }
    }
    
    ii curr_query(int i,int j){
        if (s==i && e==j) return curr;
        else if (j<=m) return l->curr_query(i,j);
        else if (m<i) return r->curr_query(i,j);
        else return merge(l->curr_query(i,m),r->curr_query(m+1,j));
    }
    
    ii check_query(int i,int j){
        if (s==i && e==j) return checkpoint;
        else if (j<=m) return l->check_query(i,j);
        else if (m<i) return r->check_query(i,j);
        else return merge(l->check_query(i,m),r->check_query(m+1,j));
    }
    
}*root;

inline long long query(int i,int j){
    //cerr<<i<<" "<<j<<endl;
    long long curr=root->curr_query(i,j).second;
    long long checkpoint=root->check_query(i,j).second;

    return (qexp((1-checkpoint+MOD)%MOD,MOD-2)*curr)%MOD;
}

set<int> s;
bool toggled[200005];

int main(){
    scanf("%d%d",&n,&q);
    for (int x=1;x<=n;x++){
        scanf("%d",&arr[x]);
    }
    
    long long inv=qexp(100,MOD-2);
    for (int x=1;x<=n;x++) arr[x]=(arr[x]*inv)%MOD;
    root=new node(1,n);
    
    s.insert(1);
    s.insert(n+1);
    long long ans=query(1,n);
    
    int t;
    int f,b;
    set<int>::iterator it;
    while (q--){
        scanf("%d",&t);
        if (toggled[t]){
            s.erase(t);
            it=s.upper_bound(t);
            b=*it;
            f=*(--it);
            ans=(ans-query(f,t-1)+MOD)%MOD;
            ans=(ans-query(t,b-1)+MOD)%MOD;
            ans=(ans+query(f,b-1))%MOD;
        }
        else{
            it=s.upper_bound(t);
            b=*it;
            f=*(--it);
            ans=(ans+query(f,t-1))%MOD;
            ans=(ans+query(t,b-1))%MOD;
            ans=(ans-query(f,b-1)+MOD)%MOD;
            s.insert(t);
        }
        toggled[t]^=true;
        printf("%lld\n",ans);
    }
}