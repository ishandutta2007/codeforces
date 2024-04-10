#include<bits/stdc++.h>
#define F first
#define S second
#define maxn 1222222

using namespace std;
int l[maxn],r[maxn],f[maxn],n,d,ans[maxn],tp[maxn];
char s[5];

void dfs(int x){
    if (tp[x]==5) return;
    if (tp[x]==1){
        dfs(l[x]);
        dfs(r[x]);
        f[x]=f[l[x]]&f[r[x]];
    }
    else if (tp[x]==2){
        dfs(l[x]);
        dfs(r[x]);
        f[x]=f[l[x]]|f[r[x]];
    }
    else if (tp[x]==3){
        dfs(l[x]);
        dfs(r[x]);
        f[x]=f[l[x]]^f[r[x]];
    }
    else{
        dfs(l[x]);
        f[x]=f[l[x]]^1;
    }
}

void solve(int x){
    if (tp[x]==5) {ans[x]=1;return;}
    if (tp[x]==1){
        if (f[x]) solve(l[x]),solve(r[x]);
        else if (f[l[x]]) solve(r[x]);
        else if (f[r[x]]) solve(l[x]);
    }
    else if (tp[x]==2){
        if (!f[x]) solve(l[x]),solve(r[x]);
        else if (!f[l[x]]) solve(r[x]);
        else if (!f[r[x]]) solve(l[x]);
    }
    else if (tp[x]==3){
        solve(l[x]); solve(r[x]);
    }
    else solve(l[x]);
}

int main(){
    cin >> n;
    for (int i=1;i<=n;i++){
        scanf("%s",s);
        if (s[0]=='A') {
            tp[i]=1;
            scanf("%d%d",&l[i],&r[i]);
        }
        else if (s[0]=='O'){
            tp[i]=2;
            scanf("%d%d",&l[i],&r[i]);
        }
        else if (s[0]=='X'){
            tp[i]=3;
            scanf("%d%d",&l[i],&r[i]);
        }
        else if (s[0]=='N'){
            tp[i]=4;
            scanf("%d",&l[i]);
        }
        else {
            tp[i]=5;
            scanf("%d",&f[i]);
        }
    }
    dfs(1); d=f[1];
    solve(1);
    for (int i=1;i<=n;i++) if (tp[i]==5) printf("%d",d^ans[i]); printf("\n");
    return 0;
}