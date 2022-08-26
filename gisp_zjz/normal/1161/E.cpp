#include<bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std;
const int maxn=505050;
typedef pair<int,int> pi;
vector <pi> h;
vector <int> ans[3];
int pre[maxn],T,n,tot,p[maxn],color[maxn],v[maxn];
bool vis[maxn];
char s[maxn];
int ffind(int x){
    if (pre[x]==x) return x;
    pre[x]=ffind(pre[x]);
    return pre[x];
}
void _union(int x,int y){
    pre[y]=x;
}
void ask(){
    if (h.size()==0) return;
    printf("Q %d",h.size());
    for (auto x:h) printf(" %d %d",x.F+1,x.S+1); puts("");
    fflush(stdout); h.clear();
    scanf("%s",s);
}
void print(){
    printf("A %d %d %d\n",ans[0].size(),ans[1].size(),ans[2].size());
    for (auto x:ans[0]) printf("%d ",x+1); puts("");
    for (auto x:ans[1]) printf("%d ",x+1); puts("");
    for (auto x:ans[2]) printf("%d ",x+1); puts("");
    for (int i=0;i<3;i++) ans[i].clear();
    fflush(stdout);
}

int main(){
    cin >> T;
    int pos;
    while (T--){
        memset(vis,0,sizeof(vis));
        cin >> n;
        for (int i=0;i<n;i++) pre[i]=i;
        for (int i=0;i*2+1<n;i++) h.pb((pi){i*2,i*2+1});
        ask();
        for (int i=0;i*2+1<n;i++) if (s[i]=='1') _union(i*2,i*2+1),vis[i*2+1]=1;
        for (int i=0;i*2+2<n;i++) h.pb((pi){i*2+1,i*2+2});
        ask();
        for (int i=0;i*2+2<n;i++) if (s[i]=='1') _union(i*2+1,i*2+2),vis[i*2+2]=1;
        tot=0;
        for (int i=0;i<n;i++) if (!vis[i]) p[tot++]=i;
        for (int i=0;i<tot-2;i++) if (i%4<2) h.pb((pi){p[i],p[i+2]});
        ask(); pos=0;
        for (int i=0;i<tot-2;i++) if (i%4<2) v[i+2]=(s[pos++]=='1');
        for (int i=0;i<tot-2;i++) if (i%4>=2) h.pb((pi){p[i],p[i+2]});
        ask(); pos=0;
        for (int i=0;i<tot-2;i++) if (i%4>=2) v[i+2]=(s[pos++]=='1');
        color[p[0]]=0;
        if (tot>1){
            color[p[1]]=1;
            for (int i=2;i<tot;i++)
                if (v[i]) color[p[i]]=color[p[i-2]];
                else color[p[i]]=3-color[p[i-1]]-color[p[i-2]];
        }
        for (int i=0;i<n;i++) ans[color[ffind(i)]].pb(i);
        print();
    }
    return 0;
}