#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
typedef vector<int>vi;
const int M=998244353;
const int maxn=1e6+10;
int n,p[maxn],k,_,v0[maxn],v1[maxn],a[maxn],b[maxn],ind[maxn],tot;
void solve(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++) v0[i]=v1[i]=0,ind[i]=0;
    for (int i=1;i<=n;i++) {
        scanf("%d",&p[i]);
        ind[p[i]]++;
    }
    for (int i=1;i<=n;i++) if (!ind[i]&&!v1[p[i]]){
        v0[i]=1;
        v1[p[i]]=1;
    }
    for (int i=1;i<=n;i++) if (ind[i]&&!v1[p[i]]){
        v0[i]=1;
        v1[p[i]]=1;
    }
    tot=0; for (int i=1;i<=n;i++) if (!v0[i]) a[++tot]=i;
    tot=0; for (int i=1;i<=n;i++) if (!v1[i]) b[++tot]=i;
    if (tot==1&&a[1]==b[1]) assert(0);
    if (tot==1){
        p[a[1]]=b[1];
    } else if (tot>=2){
        int L=1,R=tot;
        for (int i=tot;i>=3;i--){
            if (a[i]!=b[L]) p[a[i]]=b[L++]; else p[a[i]]=b[R--];
        }
        if (a[1]!=b[L]&&a[2]!=b[R]){
            p[a[1]]=b[L];
            p[a[2]]=b[R];
        } else {
            p[a[1]]=b[R];
            p[a[2]]=b[L];
        }
    }
    printf("%d\n",n-tot);
    for (int i=1;i<=n;i++) printf("%d ",p[i]);puts("");
}
int main(){
    scanf("%d",&_);
    while (_--) solve();
    return 0;
}