#include<cstdio>
#include<vector>
#include<cstring>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define mx 500
using namespace std;
vector<int>e[mx];
int vv[mx][mx],vis[mx],ct[mx],l,n,m,p1,p2,k,u;
char v[mx],s[mx],t1,t2;
void dfs(int x){
    int sz=e[x].size()-1;vis[x]=1;
    rep(i,0,sz)if(!vis[e[x][i]])dfs(e[x][i]);
}
int main(){
    scanf("%s",v);l=strlen(v)-1;
    scanf("%d%d",&n,&m);
    rep(i,1,m){
        scanf("%d %c %d %c",&p1,&t1,&p2,&t2);
        if(t1=='V')t1=0;else t1=1;
        if(t2=='V')t2=0;else t2=1;
        e[p1+t1*n].push_back(p2+t2*n);
        e[p2+(1-t2)*n].push_back(p1+(1-t1)*n);
    }
    scanf("%s",s+1);
    rep(i,1,n*2){
        rep(j,1,n*2)vis[j]=0;dfs(i);
        rep(j,1,n)if(vis[j]&&vis[j+n])ct[i]=1;
    }
    rep(i,1,n)if(ct[i]&&ct[i+n]){printf("-1\n");return 0;}
    rep(i,0,l)if(v[i]=='V')v[i]=0;else v[i]=1;
    rep(i,1,n)s[i]-='a';
    rep(i,1,n){
        rep(j,1,n*2)vis[j]=vv[i-1][j];dfs(i+v[s[i]]*n);
        rep(j,1,n)if(vis[j]&&vis[j+n]){k=i;break;}
        rep(j,1,n*2)vv[i][j]=vis[j];
    }
    rep(j,1,n)if(vis[j]&&vis[j+n]){u=1;break;}
    if(!u){rep(i,1,n)printf("%c",s[i]+'a');return 0;}
    rep(i,k+1,n)s[i]=0;s[k]++;
    while(k&&s[k]>l){s[k]=0;k--;s[k]++;}
    while(k){u=0;
        rep(j,1,n*2)vis[j]=vv[k-1][j];dfs(k+v[s[k]]*n);
        rep(j,1,n)if(vis[j]&&vis[j+n]){u=1;break;}if(!u)break;
        s[k]++;while(k&&s[k]>l){s[k]=0;k--;s[k]++;}
    }
    if(!k){printf("-1\n");return 0;}
    rep(i,1,n*2)vv[k][i]=vis[i];k++;
    while(k<=n){u=0;
        rep(j,1,n*2)vis[j]=vv[k-1][j];dfs(k+v[s[k]]*n);
        rep(j,1,n)if(vis[j]&&vis[j+n]){u=1;break;}
        if(u)s[k]++;else{rep(j,1,n*2)vv[k][j]=vis[j];k++;}
        if(s[k]>l){printf("-1\n");return 0;}
    }
    rep(i,1,n)printf("%c",s[i]+'a');
}