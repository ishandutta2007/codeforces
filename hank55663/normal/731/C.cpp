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
#define less Less
#define EPS 1e-3
#define arg ARG
#define pdd pair<double,double>
#define cpdd const pdd
int f[200005];
map<int,int> mm[200005];
int Find(int x){
    if(f[x]==x)return x;
    return f[x]=Find(f[x]);
}
int main() {
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    int c[200005];
    for(int i = 1;i<=n;i++){
        scanf("%d",&c[i]);
        f[i]=i;
    }
    for(int i =0;i<m;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        int fa=Find(a),fb=Find(b);
        f[fa]=fb;
    }
    for(int i = 1;i<=n;i++){
        mm[Find(i)][c[i]]++;
    }
    int ans=0;
    for(int i = 1;i<=n;i++){
        if(f[i]==i){
            int sum=0;
            int Max=0;
            for(auto it:mm[i]){
                if(it.y>Max){
                    Max=it.y;
                }
                sum+=it.y;
            }
            ans+=sum-Max;
        }
    }
    printf("%d\n",ans);
    return 0;
}