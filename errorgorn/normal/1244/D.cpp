#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
int n;
int R[100005];
int G[100005];
int B[100005];
vector<int> al[100005];
int child[100005];
void dfs(int i,int j){
    for (vector<int>::iterator it=al[i].begin();it!=al[i].end();it++){
        if (*it!=j){
            child[i]=*it;
            dfs(*it,i);
        }
    }
}
const string mask[]={"ABC","ACB","BAC","BCA","CAB","CBA"};
int color[6][100005];
int main(){
    scanf("%d",&n);
    for (int x=1;x<=n;x++) scanf("%d",&R[x]);
    for (int x=1;x<=n;x++) scanf("%d",&G[x]);
    for (int x=1;x<=n;x++) scanf("%d",&B[x]);
    int a,b;
    for (int x=1;x<n;x++){
        scanf("%d%d",&a,&b);
        al[a].push_back(b);
        al[b].push_back(a);
    }
    for (int x=1;x<=n;x++){
        if (al[x].size()>2){
            printf("-1\n");
            return 0;
        }
    }
    int start;
    for (int x=1;x<=n;x++){
        if (al[x].size()==1){
            start=x;
            dfs(x,-1);
            break;
        }
    }
    long long best=1000000000000000000;
    int curr;
    long long val;
    int bc;
    for (int x=0;x<6;x++){
        curr=start;
        val=0;
        for (int y=0;y<n;y++){
            if (mask[x][y%3]=='A'){
                val+=R[curr];
                color[x][curr]=1;
            }
            else if (mask[x][y%3]=='B'){
                val+=G[curr];
                color[x][curr]=2;
            }
            else{
                val+=B[curr];
                color[x][curr]=3;
            }
            curr=child[curr];
        }
        if (val<best){
            bc=x;
            best=val;
        }
    }
    printf("%lld\n",best);
    for (int x=1;x<=n;x++){
        printf("%d ",color[bc][x]);
    }
}