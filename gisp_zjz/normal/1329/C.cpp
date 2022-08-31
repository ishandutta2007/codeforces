#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
const int M=1000000007;
const int maxn=1234567;
vector <int> ans;
int n,m,f,g,a[maxn],sz[maxn],sz2[maxn];
void build(int x){
    if (x>=n/2) sz[x]=1;
    else {
        build(x*2); build(x*2+1);
        sz[x]=1+sz[x*2]+sz[x*2+1];
    }
}
void build2(int x){
    if (x>=m/2) sz2[x]=1;
    else {
        build2(x*2); build2(x*2+1);
        sz2[x]=1+sz2[x*2]+sz2[x*2+1];
    }
}
int nxt(int x){
    if (x>=n/2) return x;
    if (!a[x*2]&&!a[x*2+1]) return x;
    return a[x*2]>a[x*2+1]?x*2:x*2+1;
}
int go(int x){
    if (nxt(x)==x) return x;
    return go(nxt(x));
}
void del(int x){
    int y=nxt(x);
    if (y!=x){
        int y=nxt(x);
        a[x]=a[y]; sz[x]--;
        del(y);
    } else {
        a[x]=0;
        sz[x]--;
    }
}
void work(int x){
    if (x>=m) return;
    while (sz2[x]<sz[x]){
        if (go(x)>=m) ans.pb(x),del(x);
        else {
            work(x*2);
            work(x*2+1);
            break;
        }
    }
}
int main(){
    int _;scanf("%d",&_);
    while (_--){
        scanf("%d%d",&f,&g);
        n=1<<f; m=1<<g;
        for (int i=1;i<n;i++) scanf("%d",&a[i]);
        ans.clear();
        build(1);build2(1);
        //for (int i=1;i<n;i++)cout<<sz[i]<<' '<<sz2[i]<<endl;
        work(1);
        ll sum=0;
        for (int i=1;i<m;i++) sum+=a[i];
        printf("%lld\n",sum);
        for (auto x:ans) printf("%d ",x); puts("");
    }
    return 0;
}