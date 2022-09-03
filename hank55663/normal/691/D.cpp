#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acosl(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MXN 200005
int f[1000005];
int Find(int x){
    if(f[x]==x)return x;
    return f[x]=Find(f[x]);
}
set<int> s[1000005];
int p[1000005];
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 1;i<=n;i++){
        f[i]=i;
        scanf("%d",&p[i]);
    }
    for(int i = 0;i<m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        f[Find(x)]=Find(y);
    }
    for(int i = 1;i<=n;i++){
        s[Find(i)].insert(p[i]);
    }
    for(int i = 1;i<=n;i++){
        printf("%d ",*s[Find(i)].rbegin());
        s[Find(i)].erase(*s[Find(i)].rbegin());
    }
    printf("\n");
}
/*

23847657 
23458792534

102334155
111111111 
111111111
*/