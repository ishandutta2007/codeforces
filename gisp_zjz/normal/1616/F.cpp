#include<bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std;
typedef pair<int,int>pi;
typedef vector<int>vi;
const int M=998244353;
const int maxn=1e6+10;
int _,n,m,x[300],y[300],z[300],ans[300],id[100][100],ok;
struct eq{
    bitset<257>f,g;
    void init(){
        f.reset();
        g.reset();
    }
    eq operator+(eq x){
        eq tmp;
        tmp.f=(g&x.g)|(f&(~(x.f|x.g)))|((~(f|g))&x.f);
        tmp.g=(f&x.f)|(g&(~(x.f|x.g)))|((~(f|g))&x.g);
        return tmp;
    }
    eq operator-(eq x){
        eq tmp;
        tmp.f=(g&x.f)|(f&(~(x.f|x.g)))|((~(f|g))&x.g);
        tmp.g=(f&x.g)|(g&(~(x.f|x.g)))|((~(f|g))&x.f);
        return tmp;
    }
}a[257];
void work(eq tmp){
    for (int i=0;i<m;i++) if (tmp.f[i]||tmp.g[i]){
        if (!(a[i].f[i]|a[i].g[i])){
            a[i]=tmp;
            return;
        }
        if (a[i].f[i]^tmp.f[i]) tmp=tmp+a[i]; else tmp=tmp-a[i];
    }
    if (tmp.f[m]||tmp.g[m]) ok=0;
}
int main(){
    cin >> _;
    while (_--){
        ok=1;
        cin >> n >> m;
        for (int i=0;i<m;i++) a[i].init();
        memset(id,-1,sizeof(id));
        for (int i=0;i<m;i++){
            cin >> x[i] >> y[i] >> z[i];
            id[x[i]][y[i]]=id[y[i]][x[i]]=i;
        }
        for (int i=0;i<m;i++)
            if (z[i]!=-1){
                eq tmp; tmp.init();
                tmp.f[i]=1;
                if (z[i]==1) tmp.f[m]=1;
                if (z[i]==2) tmp.g[m]=1;
                work(tmp);
            }
        for (int i=1;i<=n;i++)
            for (int j=i+1;j<=n;j++)
                for (int k=j+1;k<=n;k++){
                    int x=id[i][j],y=id[i][k],z=id[j][k];
                    if (x==-1||y==-1||z==-1) continue;
                    eq tmp; tmp.init();
                    tmp.f[x]=tmp.f[y]=tmp.f[z]=1;
                    work(tmp);
                }
        if (!ok) {puts("-1");continue;}
        for (int i=m-1;i>=0;i--){
            if (!(a[i].f[i]|a[i].g[i])) {ans[i]=0;continue;}
            ans[i]=2*a[i].g[m]+a[i].f[m];
            for (int j=i+1;j<m;j++){
                if (a[i].f[j]) ans[i]=(ans[i]+3-ans[j])%3;
                if (a[i].g[j]) ans[i]=(ans[i]+ans[j])%3;
            }
            if (a[i].g[i]) ans[i]=(3-ans[i])%3;
        }
        for (int i=0;i<m;i++) printf("%d ",(ans[i]+2)%3+1); puts("");
    }
    return 0;
}