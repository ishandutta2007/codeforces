#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define pb push_back
using namespace std;
set <int> s[125];
const int maxn=2e5+3;
long long ans;
vector <int> g,h;
int pos,a[125][125],f[10],d[10],c[10],tmp[10],n,k,b[maxn];
bool vis[120];
int calc(){
    bool v[5];
    for (int i=0;i<k;i++) v[i]=0;
    int ret=0;
    for (int i=0;i<k;i++){
        int w=0;
        for (int j=0;j<d[i];j++) if (!v[j]) w++;
        ret+=w*f[k-1-i];
        v[d[i]]=1;
    }
    return ret;
}
void get(int x){
    int xx=x;
    bool v[5];
    for (int i=0;i<k;i++) v[i]=0;
    for (int i=0;i<k;i++){
        int w=x/f[k-1-i];
        int j=0;
        while (w||v[j]){
            if (!v[j]) w--;
            j++;
        }
        v[j]=1; d[i]=j;
        x%=f[k-1-i];
    }
}
void dfs(int x){
    for (auto y:g){
        int z=a[x][y];
        if (!vis[z]) vis[z]=1,h.pb(z),dfs(z);
    }
}

int main(){
    scanf("%d%d",&n,&k);
    f[0]=1; for (int i=1;i<=k;i++) f[i]=f[i-1]*i;
    for (int i=1;i<=n;i++){
        for (int j=0;j<k;j++) {scanf("%d",&d[j]);d[j]--;}
        b[i]=calc();
        s[b[i]].insert(i);
    }
    for (int i=0;i<f[k];i++) s[i].insert(n+1);
    for (int p=0;p<f[k];p++){
        get(p);
        for (int j=0;j<k;j++) c[j]=d[j];
        for (int q=0;q<f[k];q++){
            get(q);
            for (int j=0;j<k;j++) tmp[j]=c[d[j]];
            for (int j=0;j<k;j++) d[j]=tmp[j];
            a[p][q]=calc();
        }
    }
    for (int i=1;i<=n;i++){
        g.clear(); h.clear();
        memset(vis,0,sizeof(vis));
        vis[0]=1; pos=i; h.pb(0);
        while (1){
            int nxt=n+1,x=-1;
            for (int j=0;j<f[k];j++) if (!vis[j]){
                int pp=*(s[j].lower_bound(pos));
                if (pp<nxt) nxt=pp,x=j;
            }
            ans+=(nxt-pos+1)*1ll*h.size();
            //cout<<nxt<<' '<<x<<' '<<pos<<endl;
            if (x==-1) break;
            g.pb(x);
            for (int i=0;i<h.size();i++){
                int t=h[i];
                int p=a[t][x];
                if (!vis[p]) h.pb(p),vis[p]=1,dfs(p);
            }
            //for (auto tmp:h)cout<<tmp<<' ';cout<<"H"<<endl;
            pos=nxt+1;
        }
        ans--;
    }
    printf("%lld\n",ans);
}