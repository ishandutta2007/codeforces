#include<bits/stdc++.h>
#define mp make_pair
#define x first
#define y second
#define pll pair<LL,LL>
#define pii pair<int,int>
#define LL long long
#define pb push_back
#define pi acos(-1)
#define pdd pair<double,double>
#define MEM(x) memset(x,0,sizeof(x))
#define EPS 1e-7
using namespace std;
vector<int> v[200005];
int val[200005];
int a[200005];
int use[200005];
int S[200005];
void add(int x,int k){
    for(int i =x;i<200005;i+=i&-i){
        S[i]+=k;
    }
}
int query(int x){
    int res=0;
    for(int i = x;i>0;i-=i&-i){
        res+=S[i];
    }
    return res;
}
int in[200005];
int out[200005];
int t;
void dfs(int x,int f){
    in[x]=++t;
    for(auto it:v[x]){
        if(it!=f)
            dfs(it,x);
    }
    out[x]=t;
}
LL ans=0;
pii go(int x,int f){
    pii p=mp(0,0);
    if(val[x]<0){
        p.y++;
    }
    if(val[x]>0){
        p.x++;
    }
    for(auto it:v[x]){
        if(it!=f){
            pii p2=go(it,x);
            p.x+=p2.x;
            p.y+=p2.y;
        }
    }
    if(use[x]){
        ans+=min(p.x,p.y)*1ll*a[x]*2;
        int sub=min(p.x,p.y);
        p.x-=sub;
        p.y-=sub;
    }
    return p;
}
int main(){
    int n;
    scanf("%d",&n);
    int sum=0;
    for(int i = 1;i<=n;i++){
        int b,c;
       // scanf("%d %d",&b,&c);
        scanf("%d %d %d",&a[i],&b,&c);
        val[i]=b-c;
        sum+=val[i];
    }
    for(int i = 1;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
    }
    if(sum){
        printf("-1\n");
        return 0;
    }
    dfs(1,0);
    vector<pii> p;
    for(int i = 1;i<=n;i++){
        p.pb(mp(a[i],i));
    }
    sort(p.begin(),p.end());
    for(auto it:p){
        if(!query(in[it.y])){
        //    printf("%d\n",it.y);
            add(in[it.y],1);
            add(out[it.y]+1,-1);
            use[it.y]=1;
        }
    }
    go(1,0);
    printf("%lld\n",ans);
}
/*
2 11 14
9 3
0 1 2 3
0 1 2 3
0 1 2 3
0 1 2 3
0 1 2 3
3**5+3**5-2**5
000111222
001112220
*/