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
#define EPS 1e-4
#define arg ARG
#define pdd pair<double,double>
#define cpdd const pdd
#define MXN 300005
#define next Next
#define index Index
int s,t,ds,dt;
int f[200005];
vector<pii> edge;
int Find(int x){
    if(f[x]==x)return x;
    return f[x]=Find(f[x]);
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    vector<pii> tmp;
    for(int i = 1;i<=n;i++)
        f[i]=i;
    for(int i = 0;i<m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        tmp.pb(mp(x,y));
        //v[x].pb(y);
        //v[y].pb(x);
    }
    scanf("%d %d %d %d",&s,&t,&ds,&dt);
    int has=0;
    vector<int> vs,vt;
    for(auto it:tmp){
        int x=it.x,y=it.y;
       // scanf("%d %d",&x,&y);
        if(x!=s&&x!=t&&y!=s&&y!=t){
            if(Find(x)!=Find(y)){
                f[Find(x)]=Find(y);
                edge.pb(mp(x,y));
            }
        }
        else{
            if(x==s&&y==t){
                has=1;
                continue;
            }
            else if(x==t&&y==s){
                has=1;
                continue;
            }      
            if(x==s){
                vs.pb(y);
            }
            if(y==s){
                vs.pb(x);
            }
            if(x==t){
                vt.pb(y);
            }
            if(y==t){
                vt.pb(x);
            }
        }
    }   
   // printf("?\n");
    vector<int> tmps,tmpt;
    for(auto &it:vs){
        tmps.pb(it);
        it=Find(it);
    }
    for(auto &it:vt){
        tmpt.pb(it);
        it=Find(it);
    }
    sort(vs.begin(),vs.end());
    vs.resize(unique(vs.begin(),vs.end())-vs.begin());
    sort(vt.begin(),vt.end());
    vt.resize(unique(vt.begin(),vt.end())-vt.begin());
    //printf("?\n");
    int x=0,y=0;
    vector<int> ttmp;
    int need1[200005],need2[200005];
    fill(need1,need1+n+1,0);
    fill(need2,need2+n+1,0);
    while(x!=vs.size()||y!=vt.size()){
        if(x==vs.size()){
            dt--;
            need2[vt[y]]=1;
            y++;
        }
        else if(y==vt.size()){
            ds--;
            need1[vs[x]]=1;
            x++;
        }
        else{
            if(vs[x]==vt[y]){
                ttmp.pb(vs[x]);
                x++;y++;
            }
            else if(vs[x]<vt[y]){
                need1[vs[x]]=1;
                ds--;
                x++;
            }
            else{
                need2[vt[y]]=1;
                dt--;
                y++;
            }
        }
    }
    if(ttmp.size()){
        need1[ttmp.back()]=need2[ttmp.back()]=1;
        dt--;
        ds--;
        ttmp.pop_back();
    }
    else{
        edge.pb(mp(s,t));
        ds--;
        dt--;
    }
    for(auto it:ttmp){
        if(ds<dt){
            dt--;
            need2[it]=1;
        }
        else{
            ds--;
            need1[it]=1;
        }
    }
    for(auto it:tmps){
        if(need1[Find(it)]){
            edge.pb(mp(it,s));
            need1[Find(it)]=0;
        }
    }
    for(auto it:tmpt){
        if(need2[Find(it)]){
            edge.pb(mp(it,t));
            need2[Find(it)]=0;
        }
    }
    if(ds>=0&&dt>=0){
        printf("Yes\n");
        for(auto it:edge){
            printf("%d %d\n",it.x,it.y);
        }
    }
    else{
        printf("No\n");
    }
}
/*

100
2 3
0 500000000 1000000000
1000000000 1000000000 1000000000
 */