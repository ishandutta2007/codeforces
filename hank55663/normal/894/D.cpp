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
#define MEM(x) memset(x,0,sizeof(x))
vector<pii> v[1000005];
int p[1000005];
int plen[1000005];
vector<int > vv[1000005];
vector<LL > pre[1000005];
void dfs(int x){
    int a=0,aa,b=0,bb;
    for(auto it:v[x]){
        dfs(it.x);
        if(a==0)a=it.x,aa=it.y;
        else b=it.x,bb=it.y;
    }
    vv[x].pb(0);
    int l=0,r=0;
    LL tot=0;
    pre[x].pb(0);
    while(l!=vv[a].size()||r!=vv[b].size()){
        if(r==vv[b].size()||(l!=vv[a].size()&&vv[a][l]+aa<vv[b][r]+bb)){
            vv[x].pb(vv[a][l]+aa);
            l++;
        }
        else{
            vv[x].pb(vv[b][r]+bb);
            r++;
        }
        tot+=vv[x].back();
        pre[x].pb(tot);
    }
}
LL query(int x,LL h){
    int len=upper_bound(vv[x].begin(),vv[x].end(),h)-vv[x].begin();
    return h*len-pre[x][len-1];
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 1;i<n;i++){
        int x;
        scanf("%d",&x);
        v[(i+1)/2].pb(mp(i+1,x));
        p[i+1]=(i+1)/2;
        plen[i+1]=x;
    }
    dfs(1);
    while(m--){
        int a,h;
        scanf("%d %d",&a,&h);
        LL res=0;
        res+=query(a,h);
        //printf("%lld\n",res);
        while(a!=1){
            int temp=a;
            h-=plen[a];
            a/=2;
            if(h>=0)
            res+=h;
            if(temp==a*2){
                if(a*2+1<=n){
                int hh=h-plen[a*2+1];
                if(hh>=0){
                    res+=query(a*2+1,hh);
                }
                }
            }
            else{
                if(a*2<=n){
                int hh=h-plen[a*2];
                if(hh>=0){
                    res+=query(a*2,hh);
                }
                }
            }
           // printf("%lld\n",res);
        };
        printf("%lld\n",res);
    }
}
/*
1 4 2 3
1 3 6 12
k(a+b) = a*b;
k*a+k*b = a*b;
b= (k*a)/(a-k);

k*(k+i)/i
*/