#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define N 131072
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
int f[500005];
int Size[500005];
int Find(int x){
    if(f[x]==x)return x;
    return f[x]=Find(f[x]);
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 1;i<=n;i++){
        f[i]=i;
        Size[i]=1;
    }
    while(m--){
        int x;
        scanf("%d",&x);
        vector<int> v;
        for(int i =0;i<x;i++){
            int a;
            scanf("%d",&a);
            v.pb(a);
        }
        for(auto it:v){
            int fx=Find(v[0]);
            int fy=Find(it);
            if(fx!=fy){
                f[fy]=fx;
                Size[fx]+=Size[fy];
            }
        }
    }
    for(int i =1;i<=n;i++){
        printf("%d ",Size[Find(i)]);
    }
    printf("\n");
}