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
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define index Index
int f[400005];
int Find(int x){
    if(f[x]==x)return x;
    return f[x]=Find(f[x]);
}
void solve(){
    int n,m;
    vector<pair<pii,int> > v;
    scanf("%d %d",&n,&m);
    for(int i = 1;i<=2*n;i++)f[i]=i;
    for(int i = 1;i<n;i++){
        int x,y,w;
        scanf("%d %d %d",&x,&y,&w);
        if(w==-1);
        else{
            int a=Find(x),b=Find(x+n);
            int c=Find(y),d=Find(y+n);
            if(__builtin_popcount(w)&1){
                f[a]=d;
                c=Find(c),b=Find(b);
                f[c]=b;
            }
            else{
                f[a]=c;
                b=Find(b),d=Find(d);
                f[b]=d;
            }
        }
        v.pb(mp(mp(x,y),w));
    }
    for(int i = 0;i<m;i++){
        int x,y,w;
        scanf("%d %d %d",&x,&y,&w);
        int a=Find(x),b=Find(x+n);
            int c=Find(y),d=Find(y+n);
        if(w==0){
             f[a]=c;
                b=Find(b),d=Find(d);
                f[b]=d;
        }
        else{
            f[a]=d;
                c=Find(c),b=Find(b);
                f[c]=b;
        }
    }
    for(int i = 1;i<=n;i++){
        if(Find(i)==Find(i+n)){
            printf("NO\n");
            return;
        }
    }
    printf("YES\n");
    for(auto it:v){
        if(it.y!=-1)printf("%d %d %d\n",it.x.x,it.x.y,it.y);
        else{
            if(Find(it.x.x)==Find(it.x.y))printf("%d %d 0\n",it.x.x,it.x.y);
            else if(Find(it.x.x)==Find(it.x.y+n))printf("%d %d 1\n",it.x.x,it.x.y);
            else{
                printf("%d %d 0\n",it.x.x,it.x.y);
                int x=it.x.x,y=it.x.y;
                int a=Find(x),b=Find(x+n);
            int c=Find(y),d=Find(y+n);
            f[a]=c;
                b=Find(b),d=Find(d);
                f[b]=d;
            }
        }
    }
}
int main(){
    int t=1;0000;
    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}
/*
ACBABC
ACBCAB
ACABCB
*/