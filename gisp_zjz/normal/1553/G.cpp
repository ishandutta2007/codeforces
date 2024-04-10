#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
typedef vector<int>vi;
const int M=998244353;
const int N=1000005;
const int maxn=2e6+10;
bool p[maxn];
vector<int> fac[maxn];
int _,n,pre[maxn],q,a[maxn];
set<pi> E;
int ffind(int x){
    if (pre[x]==x) return x;
    return pre[x]=ffind(pre[x]);
}
void _union(int x,int y){
    x=ffind(x); y=ffind(y);
    if (x!=y) pre[y]=x;
}
int main(){
    for (int i=2;i<=N;i++) if (!p[i]){
        fac[i].pb(i);
        for (int j=2;j*i<=N;j++) fac[i*j].pb(i),p[i*j]=1;
    }
    scanf("%d%d",&n,&q);
    for (int i=1;i<=N+n;i++) pre[i]=i;
    for (int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        for (auto x:fac[a[i]]) _union(x,N+i);
    }
    for (int i=1;i<=n;i++){
        int x=ffind(N+i);
        for (auto y:fac[a[i]+1]){
            int z=ffind(y);
            if (x<z) E.insert((pi){x,z}); else if (x>z) E.insert((pi){z,x});
            for (auto yy:fac[a[i]+1]){
                int zz=ffind(yy);
                if (z<zz) E.insert((pi){z,zz}); else if (z>zz) E.insert((pi){zz,z});
            }
        }
    }
    while (q--){
        int s,t;scanf("%d%d",&s,&t);
        int x=ffind(N+s),y=ffind(N+t);
        if (x>y) swap(x,y);
        if (x==y) puts("0");
        else if (E.find((pi){x,y})==E.end()) puts("2");
        else puts("1");
    }
    return 0;
}