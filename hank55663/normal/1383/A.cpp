#include<bits/stdc++.h>
/*#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
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
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MAXN 205
//#define N 262144
#define ULL unsigned long long
int f[30];
int Size[30];
int Find(int x){
    if(f[x]==x)return x;
    return f[x]=Find(f[x]);
}
void solve(){
    int n;
    scanf("%d",&n);
    char a[100005],b[100005];
    scanf("%s %s",a,b);
    for(int i = 0;i<20;i++)f[i]=i,Size[i]=1;
    for(int i = 0;i<n;i++){
        if(a[i]>b[i]){
            printf("-1\n");
            return ;
        }
    }
    
    for(int i = 0;i<n;i++){
        if(a[i]!=b[i]){
            int x=Find(a[i]-'a'),y=Find(b[i]-'a');
            //printf("%d %d\n",x,y);
            if(x!=y){
                f[x]=y;
                Size[y]+=Size[x];
               // printf("%d %d\n",y,Size[y]);
            }
        }
    }
    int ans=0;
    for(int i =0;i<20;i++){
        if(f[i]==i)ans+=Size[i]-1;
    }
    printf("%d\n",ans);
}
int main(){
    int t;
    scanf("%d",&t);
    //Find();
    while(t--){
        solve();
    }
}