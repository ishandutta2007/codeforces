#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
vector<int> al[100005];
int height[100005];
int decomp[100005][20];
bool used[100005];
int parent[100005];
int subtree[100005];
int val[100005];
void dfs(int i,int j){
    subtree[i]=1;
    for (vector<int>::iterator it=al[i].begin();it!=al[i].end();it++){
        if (!used[*it] && *it!=j){
            dfs(*it,i);
            subtree[i]+=subtree[*it];
        }
    }
}
void centroid_decomp(int i,int p,int s){
    s>>=1;
    dfs(i,-1);
    int prev=-1;
    reloop:
    for (vector<int>::iterator it=al[i].begin();it!=al[i].end();it++){
        if (!used[*it] && *it!=prev && subtree[*it]>s){
            prev=i;
            i=*it;
            goto reloop;
        }
    }
    ///i is now the centroid
    used[i]=true;
    parent[i]=p;
    int prev_size=s-1;
    for (vector<int>::iterator it=al[i].begin();it!=al[i].end();it++){
        if (!used[*it]){
            if (*it!=prev){
                centroid_decomp(*it,i,subtree[*it]);
                s-=subtree[*it];
            }
        }
    }
    if (prev!=-1) centroid_decomp(prev,i,prev_size);
}
void dfs_decomp(int i){
    int node;
    for (vector<int>::iterator it=al[i].begin();it!=al[i].end();it++){
        if (height[*it]==-1){
            height[*it]=height[i]+1;
            decomp[*it][0]=i;
            node=i;
            for (int x=0;decomp[node][x]!=-1;x++){
                node=decomp[*it][x+1]=decomp[node][x];
            }
            dfs_decomp(*it);
        }
    }
}
int moveup(int i,int j){
    int k=0;
    while (j){
        if ((1<<k)&j){
            i=decomp[i][k];
            j^=(1<<k);
        }
        k++;
    }
    return i;
}
int lca(int i,int j){
    if (height[i]<height[j]) swap(i,j);
    i=moveup(i,height[i]-height[j]);
    if (i==j) return i;
    for (int x=19;x>=0;x--){
        if (decomp[i][x]!=decomp[j][x]){
            i=decomp[i][x];
            j=decomp[j][x];
        }
    }
    return decomp[i][0];
}
int dist(int i,int j){
    return height[i]+height[j]-(height[lca(i,j)]<<1);
}
void update(int i){
    int p=i;
    while (p!=-1){
        if (val[p]==-1) val[p]=dist(i,p);
        else val[p]=min(val[p],dist(i,p));
        p=parent[p];
    }
}
int query(int i){
    int p=i;
    int ans=1000000000;
    while (p!=-1){
        if (val[p]!=-1) ans=min(ans,val[p]+dist(i,p));
        p=parent[p];
    }
    return ans;
}
int main(){
    //freopen("input.txt","r",stdin);
    int n,q;
    scanf("%d%d",&n,&q);
    int a,b;
    for (int x=1;x<n;x++){
        scanf("%d%d",&a,&b);
        al[a].push_back(b);
        al[b].push_back(a);
    }
    memset(height,-1,sizeof(height));
    memset(decomp,-1,sizeof(decomp));
    height[1]=0;
    dfs_decomp(1);
    memset(parent,-1,sizeof(parent));
    centroid_decomp(1,-1,n);
    memset(val,-1,sizeof(val));
    update(1);
    while (q--){
        scanf("%d%d",&a,&b);
        if (a==1){
            update(b);
        }
        else{
            printf("%d\n",query(b));
        }
    }
}