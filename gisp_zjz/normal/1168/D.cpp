#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+1;
int dep[maxn],pre[maxn],pp[maxn],op[maxn],n,q,s[maxn][27][2],tot[maxn],d,cf;
vector<int> h[maxn];
char v[maxn];
char S[1];
void add(int u,int x,int o){
    s[u][x][o]++;
    if (s[u][x][o]>s[u][x][o^1]) {
        tot[u]++;
        if (tot[u]==d-dep[u]+1) cf++;
        if (u!=1) add(pp[u],x,op[u]);
    }
}
void sub(int u,int x,int o){
    s[u][x][o]--;
    if (s[u][x][o]>=s[u][x][o^1]){
        tot[u]--;
        if (tot[u]==d-dep[u]) cf--;
        if (u!=1) sub(pp[u],x,op[u]);
    }
}
int main(){
    cin >> n >> q;
    for (int i=2;i<=n;i++){
        cin >> pre[i] >> S;
        h[pre[i]].push_back(i);
        v[i]=S[0];
        dep[i]=dep[pre[i]]+1;
        d=max(d,dep[i]);
    }
    for (int i=2;i<=n;i++) if (h[i].size()==0&&dep[i]!=d){
        for (int j=1;j<=q;j++) puts("Fou");return 0;
    }
    pp[1]=1;
    for (int i=2;i<=n;i++){
        if (h[pre[i]].size()==2) op[i]=(h[pre[i]][0]==i)?0:1,pp[i]=pre[i];
        else pp[i]=pp[pre[i]],op[i]=op[pre[i]];
        if (v[i]!='?') add(pp[i],v[i]-'a'+1,op[i]);
    }
    //for (int i=2;i<=n;i++)cout<<pp[i]<<' '<<op[i]<<endl;
    while (q--){
        int u;
        cin >> u >> S;
        if (v[u]!='?') sub(pp[u],v[u]-'a'+1,op[u]);
        v[u]=S[0];
        if (v[u]!='?') add(pp[u],v[u]-'a'+1,op[u]);
        if (cf) puts("Fou");
        else {
            int ans=0;
            for (int i=1;i<=26;i++) ans+=i*(d-(tot[1]-max(s[1][i][0],s[1][i][1])));
            printf("Shi %d\n",ans);
        }
    }
    return 0;
}