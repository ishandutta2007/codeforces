#include<bits/stdc++.h>
using namespace std;
const int maxn=505;
bool f[505],g[505];
int d[maxn],pre[maxn],tmp[maxn],n,k,cc,a[maxn],ans;
void work(int w){
    int p=w,q=k-w; //flip p 0s, q 1s
    memset(g,0,sizeof(g));
    for (int i=1;i<=n;i++){
        if (f[i]==0&&p>0) p--,g[i]=1;
        if (f[i]==1&&q>0) q--,g[i]=1;
    }
    printf("?");
    for (int i=1;i<=n;i++) if (g[i]){
        printf(" %d",i); f[i]^=1;
    }
    puts(""); fflush(stdout);
    int x; scanf("%d",&x); ans^=x;
}
int main(){
    cin >> n >> k;
    memset(d,-1,sizeof(d));
    d[0]=0; queue<int> q; q.push(0);
    while (!q.empty()){
        int x=q.front(); q.pop();
        for (int j=0;j<=k;j++){ // flip j 0s, k-j 1s
            if (n-x<j||x<k-j) continue;
            int y=x+j-(k-j);
            if (d[y]==-1){
                d[y]=d[x]+1;
                pre[y]=x;
                tmp[y]=j;
                q.push(y);
            }
        }
    }
    if (d[n]==-1){puts("-1");return 0;}
    int r=n;
    while (r){
        a[++cc]=tmp[r];
        r=pre[r];
    }
    for (int i=cc;i;i--) work(a[i]);
    printf("! %d\n",ans);
    return 0;
}