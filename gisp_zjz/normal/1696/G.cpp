#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int>pi;
typedef vector<int> vi;
const int inf=1e9+10;
const int maxn=1e6+10;
const int M=998244353;
int kase=0;
bool vis[maxn];
int n;
double a[maxn];
double X,Y;
struct node{
    db s[3][3];
}T[maxn*4];
node w[4];
void Max(db &x,db y){if (x<y)x=y;}
node _merge(node u,node v){
    node ret;
    for (int x=0;x<3;x++)
    for (int y=0;y<3;y++){
        ret.s[x][y]=0;
        for (int p=0;p<3;p++)
        for (int q=0;q<3;q++){
            if (p+q>2) continue;
            Max(ret.s[x][y],u.s[x][p]+v.s[q][y]);
        }
    }
    return ret;
}
void build(int x,int l,int r){
    if (l==r){
        for (int i=0;i<3;i++)
            for (int j=0;j<3;j++)
                T[x].s[i][j]=0;
        T[x].s[1][1]=(db)a[l]/(X+Y);
        T[x].s[2][2]=(db)a[l]/Y;
        return;
    }
    int mid=(l+r)>>1;
    build(x*2,l,mid);
    build(x*2+1,mid+1,r);
    T[x]=_merge(T[x*2],T[x*2+1]);
}
void modify(int x,int l,int r,int p){
    if (l==r){
        for (int i=0;i<3;i++)
            for (int j=0;j<3;j++)
                T[x].s[i][j]=0;
        T[x].s[1][1]=(db)a[l]/(X+Y);
        T[x].s[2][2]=(db)a[l]/Y;
        return;
    }
    int mid=(l+r)>>1;
    if (p<=mid) modify(x*2,l,mid,p);
    else modify(x*2+1,mid+1,r,p);
    T[x]=_merge(T[x*2],T[x*2+1]);
}
node qry(int x,int l,int r,int L,int R){
    if (L<=l&&r<=R) return T[x];
    int mid=(l+r)>>1;
    if (R<=mid) return qry(x*2,l,mid,L,R);
    if (L>mid) return qry(x*2+1,mid+1,r,L,R);
    return _merge(qry(x*2,l,mid,L,R),qry(x*2+1,mid+1,r,L,R));
}
int Q;
void solve(){
    cin >> n >> Q; 
    cin >> X >> Y; if (X>Y) swap(X,Y);
    for (int i=1;i<=n;i++) cin >> a[i];
    build(1,1,n);
    while (Q--){
        int op; cin >> op;
        if (op==1){
            int k; double v; cin >> k >> v;
            a[k]=v;
            modify(1,1,n,k);
        } else {
            int l,r; cin >> l >> r;
            node tmp=qry(1,1,n,l,r);
            db ans=0;
            for (int i=0;i<3;i++)
                for (int j=0;j<3;j++)
                    Max(ans,tmp.s[i][j]);
            printf("%.10f\n",ans);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _=1;
    while (_--) solve();
}