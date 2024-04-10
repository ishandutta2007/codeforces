#include <cstdio>

#include <set>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<long long,long long> ii;

struct node{
    long long s,e,m;
    long long val=0;
    node *l=nullptr,*r=nullptr;

    node (long long _s,long long _e){
        s=_s,e=_e,m=s+e>>1;
    }

    void split(){
        l=new node(s,m);
        r=new node(m+1,e);
    }

    long long query(long long i){
        if (s==e) return s;
        else if (l!=nullptr && l->val>=i) return l->query(i);
        else return r->query(i);
    }

    void update(long long i,long long j){
        if (s==e) val=j;
        else{
            if (l==nullptr) split();
            if (i<=m) l->update(i,j);
            else r->update(i,j);
            val=max(l->val,r->val);
        }
    }
}*root=new node(1,1000000000000000000);

int n;
set<ii> s;

int main(){
    s.insert(ii(1000000000000000000,1));

    scanf("%d",&n);

    long long a,b;
    set<ii>::iterator it;
    for (int x=0;x<n;x++){
        scanf("%lld%lld",&a,&b);
        it=s.lower_bound(ii(a,-1));

        if (a<(*it).second || (*it).first<a+b-1){
            a=root->query(b);
            it=s.lower_bound(ii(a,-1));
        }

        root->update((*it).second,a-(*it).second);
        root->update(a+b,(*it).first-(a+b-1));
        if (a!=(*it).second) s.insert(ii(a-1,(*it).second));
        s.insert(ii((*it).first,a+b));
        s.erase(it);

        printf("%lld %lld\n",a,a+b-1);
    }
}