#include <cstdio>
#include <utility>
#include <vector>
using namespace std;
typedef pair<int,int> ii;
vector<int> v[150005];
bool visited[150005];
struct ufds{
    int p[150005];
    int r[150005];
    ii range[150005];
    ufds(){
        for (int x=0;x<150005;x++){
            p[x]=x;
            r[x]=0;
            range[x]=ii(x,x);
        }
    }
    int parent(int i){return (p[i]==i)?i:p[i]=parent(p[i]);}
    void unions(int i,int j){
        i=parent(i),j=parent(j);
        v[range[i].first].push_back(range[j].first);
        v[range[j].first].push_back(range[i].first);
        if (r[i]<r[j]){
            p[i]=j;
            range[j].first=range[i].second;
        }
        else{
            p[j]=i;
            range[i].first=range[j].second;
            if (r[i]==r[j]) r[i]++;
        }
    }
}*root;
int main(){
    //freopen("input.txt","r",stdin);
    int n;
    scanf("%d",&n);
    root=new ufds();
    int a,b;
    for (int x=1;x<n;x++){
        scanf("%d%d",&a,&b);
        root->unions(a,b);
    }
    /*for (int x=1;x<=n;x++){
        for (int y=0;y<v[x].size();y++){
            printf("%d ",v[x][y]);
        }
        printf("\n");
    }*/
    int k;
    for (int x=1;x<=n;x++){
        if (v[x].size()==1){
            k=x;
            break;
        }
    }
    while (true){
        printf("%d ",k);
        visited[k]=true;
        for (int y=0;y<v[k].size();y++){
            if (v[k][y]!=-1 && !visited[v[k][y]]){
                k=v[k][y];
                goto _end;
            }
        }
        return 0;
        _end:;
    }
}