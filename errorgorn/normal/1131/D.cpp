#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n,m;
char grid[1005][1005];
vector<int> al[2005];
bool recstack[2005]; //this is to keep track of looping
struct ufds{
    int p[2005];
    int r[2005];
    int val[2005];
    ufds(){
        for (int x=0;x<2005;x++){
            p[x]=x;
            r[x]=0;
            val[x]=-1;
        }
    }
    int parent(int i){return p[i]==i?i:p[i]=parent(p[i]);}
    bool same(int i,int j){return parent(i)==parent(j);}
    void unions(int i,int j){
        i=parent(i);
        j=parent(j);
        if (i==j) return;
        if (r[i]<r[j]){
            p[i]=j;
        }
        else{
            p[j]=i;
        }
    }
    int getvalue(int i){return val[parent(i)];}
    bool setvalue(int i,int j){val[parent(i)]=j;}
} *root;
int dp(int i){
    i=root->parent(i);
    if (recstack[i]){
        return -1;
    }
    else if (root->getvalue(i)!=-1) return root->getvalue(i);
    else if (!al[i].size()){
        root->setvalue(i,1);
        return 1;
    }
    recstack[i]=true;
    int ans=-1;
    int k;
    for (vector<int>::iterator it=al[i].begin();it!=al[i].end();it++){
        k=dp(*it);
        if (k==-1) return -1;
        ans=max(ans,k+1);
    }
    recstack[i]=false;
    root->setvalue(i,ans);
    return ans;
}
int main(){
    //freopen("input.txt","r",stdin);
    char in[64];
    gets(in);
    sscanf(in,"%d%d",&n,&m);
    root=new ufds();
    for (int x=0;x<n;x++){
        gets(grid[x]);
        for (int y=0;y<m;y++){
            if (grid[x][y]=='=') root->unions(x,y+1000);
        }
    }
    for (int x=0;x<n;x++){
        for (int y=0;y<m;y++){
            if (grid[x][y]!='=' && root->same(x,y+1000)){
                printf("No\n");
                return 0;
            }
            if (grid[x][y]=='<'){
                al[root->parent(y+1000)].push_back(root->parent(x));
                //printf("%d %d\n",root->parent(y+1000),root->parent(x));
            }
            else if (grid[x][y]=='>'){
                al[root->parent(x)].push_back(root->parent(y+1000));
                //printf("%d %d\n",root->parent(x),root->parent(y+1000));
            }
        }
    }
    for (int x=0;x<n;x++){
        if (dp(x)==-1){
            printf("No\n");
            return 0;
        }
    }
    for (int y=0;y<m;y++){
        if (dp(y+1000)==-1){
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
    for (int x=0;x<n;x++) printf("%d ",dp(x));
    printf("\n");
    for (int y=0;y<m;y++) printf("%d ",dp(y+1000));
    printf("\n");
}