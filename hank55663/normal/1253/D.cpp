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
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MXN 300000
#define N 100005
int f[200005];
int l[200005];
int r[2000005];
int Find(int x){
    if(f[x]==x)return x;
    return f[x]=Find(f[x]);
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 1;i<=n;i++){
        f[i]=l[i]=r[i]=i;
    }
    for(int i = 0;i<m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        if(Find(x)!=Find(y)){
            int fy=Find(y);
            int fx=Find(x);
            f[Find(x)]=Find(y);
            r[fy]=max(r[fy],r[fx]);
        }
    }
    int ans=0;
    for(int i = 1;i<=n;i++){
        int k=i;
     //   printf("%d\n",k);
        while(r[Find(k)]!=k){
            k++;
            int fk=Find(k),fi=Find(i);
            if(fk!=fi){
               // printf("%d %d %d\n",i,k,r[fk]);
                ans++;
                f[fk]=fi;
                r[fi]=max(r[fi],r[fk]);
            }
        }
        i=k;
    }
    printf("%d\n",ans);
}