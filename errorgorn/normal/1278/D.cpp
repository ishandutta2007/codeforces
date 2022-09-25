#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <utility>
#include <vector>
using namespace std;
typedef pair<int,int> ii;
int n;
ii arr[500005];
int E=0; ///keep track of edges added

void quit(){
    printf("NO\n");
    exit(0);
}

struct ufds{
    int p[500005];
    int r[500005];

    ufds(){
        for (int x=0;x<500005;x++){
            p[x]=x;
            r[x]=0;
        }
    }
    int parent(int i){return (p[i]==i)?i:p[i]=parent(p[i]);}
    void unions(int i,int j){
        i=parent(i),j=parent(j);
        if (i==j) quit();
        if (r[i]<r[j]){
            p[i]=j;
        }
        else{
            p[j]=i;
            if (r[i]==r[j]) r[i]++;
        }
    }
}*dsu=new ufds();


struct node{
    int s,e,m;
    vector<int> edges;
    node *l, *r;
    
    node(int _s,int _e){
        s=_s,e=_e,m=(s+e)>>1;
        if (s!=e){
            l=new node(s,m);
            r=new node(m+1,e);
        }
    }
    
    void update(int i,int j){ //add vertice j at i
        edges.push_back(j);
        if (s==e) return;
        if (i<=m) l->update(i,j);
        else r->update(i,j);
    }
    
    void query(int i,int j,int k){
        if (s==i && e==j){
            E+=edges.size();
            for (auto &it:edges){
                dsu->unions(k,it);
            }
        }
        else if (j<=m) l->query(i,j,k);
        else if (m<i) r->query(i,j,k);
        else l->query(i,m,k),r->query(m+1,j,k);
    }
}*root;

int main(){
    scanf("%d",&n);
    for (int x=0;x<n;x++){
        scanf("%d%d",&arr[x].first,&arr[x].second);
    }
    
    sort(&arr[0],&arr[n]);
    root=new node(0,2*n);
    
    for (int x=0;x<n;x++){
        root->query(arr[x].first,arr[x].second,x);
        root->update(arr[x].second,x);
    }
    
    if (E==n-1) printf("YES\n");
    else printf("NO\n");
}