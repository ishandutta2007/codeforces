#include <stdio.h>
#include <algorithm>

using namespace std;

int g[210][210];
int n,m;
int comp[210];
int sz[210],asf[210];
bool pegueiAsf[210];
bool peguei[105];

void dfs(int x, int c){
    if (comp[x]!=-1) return;
    comp[x]=c;
    sz[c]++;
    if (x%2==0) asf[c]++;
    for (int i=0; i<n; i++){
        if (g[x][i]) dfs(i,c);
    }
}

bool first=true;
void print(int x){
    if (first) printf("%d",x);
    else printf(" %d",x);
    first=false;
}

int main(){
    scanf(" %d %d",&n,&m);
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++) g[i][j]=0;
    }
    for (int i=0; i<m; i++){
        int a,b,c;
        scanf(" %d %d %d",&a,&b,&c);
        a--; b--;
        if (!c){
            g[2*a+1][2*b] = 1;
            g[2*b+1][2*a] = 1;
            g[2*b][2*a+1] = 1;
            g[2*a][2*b+1] = 1;
        }
        else {
            g[2*a][2*b] = 1;
            g[2*b+1][2*a+1] = 1;
            g[2*b][2*a] = 1;
            g[2*a+1][2*b+1] = 1;
            
        }
    }
    n*=2;
    for (int i=0; i<n; i++){
        comp[i]=-1;
        sz[i]=asf[i]=0;
    }
    int ct=0;
    for (int i=0; i<n; i++){
        if (comp[i]==-1) dfs(i,ct++);
    }
    bool poss=true;
    for (int i=0; i<n/2; i++) if (comp[2*i]==comp[2*i+1]) poss=false;
    if (!poss) printf("Impossible\n");
    else {
        int ans=0;
        for (int i=0; i<105; i++) peguei[i]=false;
        for (int i=0; i<n/2; i++){
            if (!peguei[comp[2*i]] && !peguei[comp[2*i+1]]){
                int c = comp[2*i];
                peguei[c] = true;
            }
        }
        for (int i=0; i<ct; i++){
            if (!peguei[i]) continue;
            if (asf[i]<sz[i]-asf[i]) pegueiAsf[i]=true;
            else pegueiAsf[i]=false;
            ans+=min(asf[i],sz[i]-asf[i]);
        }
        printf("%d\n",ans);
        first = true;
        for (int i=0; i<n/2; i++){
            int x = i;
            int c1 = comp[2*i];
            int c2 = comp[2*i+1];
            if (pegueiAsf[c1] && peguei[c1]) print(x+1);
            else if(!pegueiAsf[c2] && peguei[c2]) print(x+1);
        }
        printf("\n");
    }
    return 0;
}