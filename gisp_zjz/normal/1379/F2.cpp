#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const int maxn=1e6+5;
int n,m,q,b[maxn],N;
set <ll> S;
struct query{
    int x,y,o,v;
}a[maxn];
struct node{
    int x,y,id,tp,val;
    //0 modify 1 query
};
ll ans[maxn];
bool cmp1(node u,node v){
    if (u.x!=v.x) return u.x<v.x;
    return u.tp<v.tp;
}
bool cmp2(node u,node v){
    if (u.x!=v.x) return u.x>v.x;
    return u.tp<v.tp;
}
void add(int x,int y){
    while (x<=N) b[x]+=y,x+=x&(-x);
}
int qry(int x){
    int ret=0;
    while (x) ret+=b[x],x-=x&(-x);
    return ret;
}

void solve(int l,int r){
    if (l==r) return;
    int mid=(l+r)>>1;
    solve(l,mid);
    solve(mid+1,r);
    vector <int> nx,ny; nx.clear(); ny.clear();
    for (int i=l;i<=r;i++) nx.pb(a[i].x),ny.pb(a[i].y);
    sort(nx.begin(),nx.end());
    nx.erase(unique(nx.begin(),nx.end()),nx.end());
    sort(ny.begin(),ny.end());
    ny.erase(unique(ny.begin(),ny.end()),ny.end());
    vector <node> tmp1,tmp2;
    tmp1.clear();tmp2.clear();
    for (int i=l;i<=mid;i++) {
        int x=lower_bound(nx.begin(),nx.end(),a[i].x)-nx.begin()+1;
        int y=lower_bound(ny.begin(),ny.end(),a[i].y)-ny.begin()+1;
        if (a[i].o==1) {
            tmp1.pb((node){x,y,0,0,a[i].v});
        } else {
            tmp2.pb((node){x,y,0,0,a[i].v});
        }
    }
    for (int i=mid+1;i<=r;i++) {
        int x=lower_bound(nx.begin(),nx.end(),a[i].x)-nx.begin()+1;
        int y=lower_bound(ny.begin(),ny.end(),a[i].y)-ny.begin()+1;
        if (a[i].o==0) {
            tmp1.pb((node){x,y,i,1,a[i].v});
        } else {
            tmp2.pb((node){x,y,i,1,a[i].v});
        }
    }
    N=ny.size();
    for (int i=1;i<=N;i++) b[i]=0;
    sort(tmp1.begin(),tmp1.end(),cmp1);
    for (auto v:tmp1){
        if (v.tp==0) add(v.y,v.val);
        else ans[v.id]+=qry(v.y)*v.val;
    }
    for (int i=1;i<=N;i++) b[i]=0;
    sort(tmp2.begin(),tmp2.end(),cmp2);
    for (auto v:tmp2){
        if (v.tp==0) add(v.y,v.val);
        else ans[v.id]+=(qry(N)-qry(v.y-1))*v.val;
    }
}
int main(){
    scanf("%d%d%d",&n,&m,&q);
    for (int i=1;i<=q;i++){
        int x,y; scanf("%d%d",&x,&y);
        ll id=1ll*x*2*m+y;
        if (S.find(id)==S.end()){
            S.insert(id);
            a[i].v=1;
        } else {
            S.erase(id);
            a[i].v=-1;
        }
        a[i].x=(x+1)/2;
        a[i].y=(y+1)/2;
        a[i].o=x%2;
    }
    solve(1,q);
    for (int i=1;i<=q;i++) ans[i]+=ans[i-1];
    for (int i=1;i<=q;i++) if (ans[i]) puts("NO"); else puts("YES");
    return 0;
}