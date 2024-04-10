#include<bits/stdc++.h>
#define maxn 500005
using namespace std;
vector <int> h[maxn];
int n,T,x[maxn],y[maxn],cnt,d[maxn],id;
queue <int> q;
bool f[maxn];
char s[maxn];

bool Check(int u){
    int Cnt=0;
    for (int i=0;i<h[u].size();i++){
        int v=h[u][i];
        if (d[v]>1) Cnt++;
    }
    return Cnt<=1;
}

bool check(){
    if (n<=4) return false;
    int cc=0;
    for (int i=1;i<=n;i++){
        if (d[i]>3) return true;
        if (d[i]==3) {
            if (Check(i)) cc++; else return true;
        }
    }
    return cc+n%2>=3;
}

void add_edge(int u,int v){
    h[u].push_back(v);
    h[v].push_back(u);
    d[u]++; d[v]++;
}

bool work(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++) f[i]=1;
    for (int i=1;i<n;i++){
        scanf("%d%d",&x[i],&y[i]);
        add_edge(x[i],y[i]);
    }
    scanf("%s",s+1); cnt=0;
    for (int i=1;i<=n;i++) if (s[i]=='W') cnt++,id=i;
    if (cnt>2) return true;
    if (cnt==2){
        int mx=0,Mx=0;
        for (int i=1;i<=n;i++){
            mx=max(mx,d[i]);
            if (s[i]=='W') Mx=max(Mx,d[i]);
        }
        if (mx==2&&Mx==1) return n%2==1; else return true;
    }
    if (cnt) n+=3,add_edge(id,n),add_edge(n,n-2),add_edge(n,n-1);
    return check();
}

int main(){
    cin >> T;
    while (T--){
        if (work()) puts("White"); else puts("Draw");
        for (int i=1;i<=n;i++) h[i].clear(),d[i]=0;
    }
}