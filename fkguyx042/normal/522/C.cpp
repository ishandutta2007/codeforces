#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define N 250005
#define For(i,l,r) for(int i=l;i<=r;i++)
using namespace std;
int vis[N],a[N];
int t[N],r[N],ans[N];
int main(){
    int T; scanf("%d",&T);
    while(T--){
        int n,m; scanf("%d%d",&n,&m); n--;
        For(i,1,m) scanf("%d",&a[i]),ans[i]=vis[i]=0;
        
        int flag=0,cnt=0;
        For(i,1,n) scanf("%d%d",&t[i],&r[i]);
        For(i,1,n){
            if(!flag && r[i]){
                flag=1;
                For(j,i,n) vis[t[j]]=1;
                int ret=0x7f7f7f7f;
                For(j,1,m) if(!vis[j] && a[j]<=cnt) ans[j]=1;
                For(j,1,m) if(!vis[j]) ret=min(ret,a[j]);
                cnt-=ret;
            }
            if(!t[i]) cnt++;
            else a[t[i]]--;
        }
        For(i,1,m) if(ans[i] || a[i]<=cnt) printf("Y");else printf("N");
        printf("\n");
    }
}