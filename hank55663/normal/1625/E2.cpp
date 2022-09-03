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
int bln[300005];
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
    bln[l]=num;
    bln[i]=num;
    i++;
    return num;
}
int in[300005],out[300005];
LL val[300005];
int idx2=0;
LL sum1[300005],sum2[300005];
int pr[300005];
LL cnt[300005];
int number[300005];
vector<int> SS[300005];
void add(int x,int k,vector<int> &v){
    for(int i = x;i<v.size();i+=i&-i){
        v[i]+=k;
    }
}
int query(int x,vector<int> &v){
    int res=0;
    for(int i = x;i>0;i-=i&-i){
        res+=v[i];
    }
    return res;
}
void dfs(int x){
    in[x]=++idx2;
    int tot=0;
    SS[x].resize(v[x].size()+1);
    for(auto it:v[x]){
        dfs(it);
        pr[it]=x;
        val[x]+=val[it];
        sum1[p[it].x]=sum1[p[it].x-1];
        sum2[p[it].x]=sum2[p[it].x-1];
        sum1[p[it].y]=sum1[p[it].x]+1;
        sum2[p[it].y]=sum2[p[it].x]+val[it];
        number[it]=++tot;
        //printf("add %d %d %d\n",x,tot,1);
        add(tot,1,SS[x]);
    }
    out[x]=idx2;
    cnt[x]=v[x].size();
    val[x]+=v[x].size()*(v[x].size()-1)/2+1;
}  
LL S[300005];
void add(int x,int k){
    for(int i = x;i<300005;i+=i&-i)S[i]+=k;
}
LL query(int x){
    LL res=0;
    for(int i = x;i>0;i-=i&-i)res+=S[i];
    return res;
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
            int x=bln[l];
            int y=bln[r];
            int p=pr[x];
            LL tot=query(number[y],SS[p])-query(number[x]-1,SS[p]);
            //printf("%d %d %d %d\n",tot,y,x,p);
          //  printf("??%d\n",tot);
            printf("%lld\n",sum2[r]-sum2[l]-(query(r)-query(l-1))+(tot)*(tot-1)/2);
        }
        else {
            int l,r;
            scanf("%d %d",&l,&r);
            int x=pr[m[mp(l,r)]];
            if(x!=0)
            add(p[x].x,cnt[x]*(cnt[x]+1)/2-cnt[x]*(cnt[x]-1)/2-1);
            add(l,1);
            cnt[x]--;
            add(number[m[mp(l,r)]],-1,SS[x]);
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