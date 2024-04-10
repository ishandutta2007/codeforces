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
map<pii,int> m;
pii p[300005];
char c[300005];
vector<int> v[300005];
int i;
int idx=1;
int dfs(){
    int num=++idx;
    int l=i;
    i++;
    while(c[i]=='('){
        int x=dfs();
        if(x!=-1)
        v[num].pb(x);
    }
    if(c[i]==0){
        for(auto it:v[num]){
            v[0].pb(it);
        }
        v[num].clear();
        idx--;
        return -1;
    }
    //printf("%d %d %d\n",num,l,i);
    m[mp(l,i)]=num;
    p[num]=mp(l,i);
    i++;
    return num;
}
int in[300005],out[300005];
LL val[300005];
int idx2=0;
LL sum1[300005],sum2[300005];
int pr[300005];
void dfs(int x){
    in[x]=++idx2;
    for(auto it:v[x]){
        dfs(it);
        pr[it]=x;
        val[x]+=val[it];
        sum1[p[it].x]=sum1[p[it].x-1];
        sum2[p[it].x]=sum2[p[it].x-1];
        sum1[p[it].y]=sum1[p[it].x]+1;
        sum2[p[it].y]=sum2[p[it].x]+val[it];
    }
    out[x]=idx2;
    val[x]+=v[x].size()*(v[x].size()-1)/2+1;
}  
void solve(){
    int n,q;
    scanf("%d %d",&n,&q);
    scanf("%s",c+1);
    i=1;
    while(i!=n+1){
        if(c[i]==')'){
            i++;
            continue;
        }
        int x=dfs();
        if(x!=-1)
        v[0].pb(x);
    }
    p[0]=mp(0,n+1);
    dfs(0);
    while(q--){
        int op;
        scanf("%d",&op);
        if(op==2){
            int l,r;
            scanf("%d %d",&l,&r);
            LL tot=sum1[r]-sum1[l];
            printf("%lld\n",sum2[r]-sum2[l]+(tot)*(tot-1)/2);
        }
    }
}
int main(){
    int t=1;0000;
   // scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}