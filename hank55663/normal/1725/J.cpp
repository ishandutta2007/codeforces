#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
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
LL ans[100005];
LL Max[100005],Max2[100005],Max3[100005],Max4[100005];
vector<pii> v[100005];
void dfs(int x,int f){
    for(auto it:v[x]){
        if(it.x!=f){
            dfs(it.x,x);
            ans[x]=max(ans[x],ans[it.x]);
            LL val=Max[it.x]+it.y;
            if(val>=Max[x]){
                Max4[x]=Max3[x];
                Max3[x]=Max2[x];
                Max2[x]=Max[x];
                Max[x]=val;
            }
            else if(val>=Max2[x]){
                Max4[x]=Max3[x];
                Max3[x]=Max2[x];
                Max2[x]=val;
            }
            else if(val>=Max3[x]){
                Max4[x]=Max3[x];
                Max3[x]=val;
            }
            else if(val>=Max4[x]){
                Max4[x]=val;
            }
        }
    }
    ans[x]=max(ans[x],Max[x]+Max2[x]);
}
LL aans;
void dfs(int x,int f,LL M,LL a,LL M2){
    //aans=max(aans,M2+ans[x]);
    vector<LL> tmp{Max[x],Max2[x],Max3[x],Max4[x],M};
    sort(tmp.begin(),tmp.end());
    reverse(tmp.begin(),tmp.end());
    aans=max(aans,tmp[0]+tmp[1]+tmp[2]+tmp[3]);
    for(auto it:v[x]){
        if(it.x!=f){
            if(Max[it.x]+it.y==Max[x]){
                LL val=max(M+Max2[x],Max2[x]+Max3[x]);
                dfs(it.x,x,max(M,Max2[x])+it.y,max(a,val),max(M2,val)+it.y);
                aans=max(aans,it.y*2+ans[it.x]+max(a,val));
              //  printf("%d %d %d %d\n",x,it.x,ans[it.x],max(a,max(M+Max2[x],Max2[x]+Max3[x])));
            }
            else if(Max[it.x]+it.y==Max2[x]){
                 LL val=max(M+Max[x],Max[x]+Max3[x]);
                dfs(it.x,x,max(M,Max[x])+it.y,max(a,val),max(M2,val)+it.y);
                aans=max(aans,it.y*2+ans[it.x]+max(a,val));
               //  printf("%d %d %d %d\n",x,it.x,ans[it.x],max(a,max(M+Max[x],Max[x]+Max3[x])));
            }else{
                LL val=max(M+Max[x],Max[x]+Max2[x]);
                  dfs(it.x,x,max(M,Max[x])+it.y,max(a,val),max(M2,val)+it.y);
                aans=max(aans,it.y*2+ans[it.x]+max(a,val));
             //    printf("%d %d %d %d\n",x,it.x,ans[it.x],max(a,max(M+Max[x],Max[x]+Max2[x])));
            }
        }
    }
}
void solve(){
    int n;
    scanf("%d",&n);
    LL sum=0;
    for(int i = 1;i<n;i++){
        int x,y,w;
      //  w=rand()%1000000000+1;
        scanf("%d %d %d",&x,&y,&w);
       // x=i+1;
     //   y=rand()%i+1;
        v[x].pb(mp(y,w));
        v[y].pb(mp(x,w));
        sum+=w;
    }
    dfs(1,0);
    dfs(1,0,0,0,0);
    printf("%lld\n",sum*2-aans);
}
int main(){
    int t=1;
   // scanf("%d",&t);
    for(int T=1;T<=t;T++){
        solve();
    }
   // printf("%d\n",s.size());
}

/*
3 5 7 8
4999850001
*/