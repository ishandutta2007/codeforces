
#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
vector<int> v[1005];
int f[1005];
int Size[1005];
int Find(int x){
    if(f[x]==x)return x;
    return f[x]=Find(f[x]);
}
void solve(int T){
    int n;
    scanf("%d",&n);
    for(int i = 0;i<=n-1;i++)v[i].clear();
    for(int i = 1;i<=n;i++){
        int d;
        scanf("%d",&d);
        v[d].pb(i);
        f[i]=i;
        Size[i]=1;
    }
    for(int i = n-1;i>=0;i--){
        for(auto it:v[i]){
            while(true){
                int x=Find(it);
                if(Size[x]>=i)break;
                printf("? %d\n",it);
                fflush(stdout);
                int y;
                scanf("%d",&y);
                y=Find(y);
                f[x]=y;
                Size[y]+=Size[x];
            }
        }
    }
    printf("!");
    for(int i = 1;i<=n;i++)printf(" %d",Find(i));
    printf("\n");
    fflush(stdout);
}
int main(){
    int t=1;
    scanf("%d",&t);
    for(int T=1;T<=t;T++){
       // cerr<<T<<endl;
        solve(T);
    }
   // printf("%d\n",s.size());
}

/*
1 2 3 4
*/