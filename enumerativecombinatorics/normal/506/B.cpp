#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>g[110000];
vector<int>rev[110000];
int v[110000];
int UF[110000];
int FIND(int a){
    if(UF[a]<0)return a;
    return UF[a]=FIND(UF[a]);
}
void UNION(int a,int b){
    a=FIND(a);b=FIND(b);if(a==b)return;
    UF[a]+=UF[b];UF[b]=a;
}
int num;
int con[110000];
void dfs(int a){
    v[a]=-2;
    for(int i=0;i<g[a].size();i++){
        if(!~v[g[a][i]]){
            dfs(g[a][i]);
        }
    }
    con[num]=a;
    v[a]=num++;
}
int hr[110000];
int cnt;
void dfs2(int a){
    v[a]=1;
    cnt++;
    for(int i=0;i<rev[a].size();i++){
        if(!~v[rev[a][i]]){
            dfs2(rev[a][i]);
        }
    }
}
int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    for(int i=0;i<a;i++)UF[i]=-1;
    for(int i=0;i<b;i++){
        int p,q;scanf("%d%d",&p,&q);
        p--;q--;
        g[p].push_back(q);
        rev[q].push_back(p);
        UNION(p,q);
    }
    for(int i=0;i<a;i++){
        v[i]=-1;
    }
    for(int i=0;i<a;i++){
        if(!~v[i]){
            dfs(i);
        }
    }
    int ssc=0;
    for(int i=0;i<a;i++)v[i]=-1;
    for(int i=a-1;i>=0;i--){
        if(!~v[con[i]]){
            cnt=0;
            dfs2(con[i]);
            if(cnt>1){
                hr[FIND(con[i])]=1;
            }
        }
    }
    int ret=0;
    for(int i=0;i<a;i++){
        if(UF[i]<0){
            int sz=-UF[i];
            ret+=sz-1+hr[i];
        }
    }
    printf("%d\n",ret);
}