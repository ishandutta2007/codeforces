#include <cstdio>
#include <map>
#include <utility>
#include <vector>
#include <stack>
using namespace std;
typedef pair<int,int> ii;

const int MAXN=300005;

long long ans;
long long fin[MAXN+5];

stack<ii> rb;

struct DSU{
    int p[MAXN*2];
    int r[MAXN*2];
    int xs[MAXN*2];
    int ys[MAXN*2];
    
    DSU(){
        for (int x=0;x<MAXN*2;x++){
            p[x]=x;
            r[x]=0;
            if (x<MAXN) xs[x]=1,ys[x]=0;
            else ys[x]=1,xs[x]=0;
        }
    }
    
    int parent(int i){return (p[i]==i)?i:parent(p[i]);}
    
    void unions(int i,int j){
        i=parent(i),j=parent(j);
        if (i==j) return;
        if (r[i]<r[j]){
            rb.push(ii(i,j));
            p[i]=j;
            ans-=(long long)xs[i]*ys[i];
            ans-=(long long)xs[j]*ys[j];
            xs[j]+=xs[i];
            ys[j]+=ys[i];
            ans+=(long long)xs[j]*ys[j];
        }
        else{
            rb.push(ii(j,i));
            p[j]=i;
            ans-=(long long)xs[i]*ys[i];
            ans-=(long long)xs[j]*ys[j];
            xs[i]+=xs[j];
            ys[i]+=ys[j];
            ans+=(long long)xs[i]*ys[i];
            if (r[i]==r[j]) r[i]++;
        }
    }
    
    void __rollback(ii i){
        ans-=(long long)xs[i.second]*ys[i.second];
        p[i.first]=i.first;
        xs[i.second]-=xs[i.first];
        ys[i.second]-=ys[i.first];
        ans+=(long long)xs[i.first]*ys[i.first];
        ans+=(long long)xs[i.second]*ys[i.second];
        if (r[i.first]+1==r[i.second]) r[i.second]--;
    }
}*ufds=new DSU();

struct node{
    int s,e,m;
    vector<ii> merges;
    node *l,*r;
    
    node(int _s,int _e){
        s=_s,e=_e,m=s+e>>1;
        if (s!=e){
            l=new node(s,m);
            r=new node(m+1,e);
        }
    }
    
    void update(int i,int j,int e1,int e2){
        if (s==i && e==j) merges.push_back(ii(e1,e2));
        else if (j<=m) l->update(i,j,e1,e2);
        else if (m<i) r->update(i,j,e1,e2);
        else l->update(i,m,e1,e2),r->update(m+1,j,e1,e2);
    }
    
    void recurse(){
        int curr_size=rb.size();
        for (auto &it:merges){
        }
        for (auto &it:merges){
            ufds->unions(it.first,it.second+MAXN);
        }
        if (s==e){
            fin[s]=ans;
        }
        else{
            l->recurse();
            r->recurse();
        }
        
        while (rb.size()!=curr_size){
            ufds->__rollback(rb.top());
            rb.pop();
        }
    }
}*root=new node(0,MAXN);

int n;
map<ii,int> m;
int main(){
    scanf("%d",&n);
    int a,b;
    for (int x=0;x<n;x++){
        scanf("%d%d",&a,&b);
        if (!m.count(ii(a,b))||m[ii(a,b)]==-1) m[ii(a,b)]=x;
        else {
            root->update(m[ii(a,b)],x-1,a,b);
            m[ii(a,b)]=-1;
        }
    }
    
    for (auto it:m){
        if (it.second==-1) continue;
        root->update(it.second,MAXN,it.first.first,it.first.second);
    }
    
    root->recurse();
    
    for (int x=0;x<n;x++){
        printf("%lld ",fin[x]);
    }
}