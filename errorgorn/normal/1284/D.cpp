#pragma GCC target ("avx2")
#pragma GCC optimization ("Ofast")
#pragma GCC optimization ("unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")


#include <cstdio>
#include <vector>
#include <utility>
#include <set>
#include <algorithm>
using namespace std;
typedef pair<int,int> ii;

struct lec{
    int a,b;
    int c,d;
    
    lec(int aa,int bb,int cc,int dd){
        a=aa,b=bb,c=cc,d=dd;
    }
    
};
int n;
vector<lec*> v1,v2,p1,p2;

struct node{
    int s,e,m;
    bool blocked,split;
    node *l,*r;
    node(int _s,int _e){
        s=_s,e=_e,m=(s+e)>>1; //going to lazily build the ST
        blocked=false;
        split=false;
    }
    void update(int i,int j){
         if (i==s && j==e){
            blocked=true;
         }
         else{
            if (!split){
                split=true;
                l=new node(s,m);
                r=new node(m+1,e);
            }
            if (j<=m) l->update(i,j);
            else if (i>m) r->update(i,j);
            else l->update(i,m),r->update(m+1,j);
         }
    }
    bool query(int i,int j){
        if (blocked) return true;
        else if (split){
            if (j<=m) return l->query(i,j);
            else if (m<i) return r->query(i,j);
            else return l->query(i,m)||r->query(m+1,j);
        }
        else return false;
    }
}*root;


bool test(vector<lec*> &i,vector<lec*> &j){
    root=new node(0,1000000000);
    sort(i.begin(),i.end(),[](lec *i,lec *j){
        return i->b<j->b; 
    });
    
    sort(j.begin(),j.end(),[](lec *i,lec *j){
        return i->a<j->a; 
    });
    
    while (!i.empty()){
        while (i.back()->b<j.back()->a){
            root->update(j.back()->c,j.back()->d);
            j.pop_back();
        }
        if (root->query(i.back()->c,i.back()->d)) return true;
        i.pop_back();
    }
    return false;
}

int main(){
    scanf("%d",&n);
    int a,b,c,d;
    for (int x=0;x<n;x++){
        scanf("%d%d%d%d",&a,&b,&c,&d);
        v1.push_back(new lec(a,b,c,d));
        v2.push_back(new lec(a,b,c,d));
        p1.push_back(new lec(c,d,a,b));
        p2.push_back(new lec(c,d,a,b));
    }
    
    if (test(v1,v2)||test(p1,p2)) printf("NO\n");
    else printf("YES\n");
}