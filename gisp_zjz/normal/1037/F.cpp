#include<bits/stdc++.h>
#define maxn 2222222
#define M 1000000007

using namespace std;
typedef long long ll;
ll pow_(ll x,ll y){
    ll rt=1;
    while (y){
        if (y&1) rt=rt*x%M;
        x=x*x%M;
        y>>=1;
    }
    return rt;
}
struct node{
    int x,pos;
}a[maxn];
bool cmp(node u,node v){
    if (u.x!=v.x) return u.x>v.x; else return u.pos<v.pos;
}
int b[maxn],c[maxn],n,k,l,r,p;
ll ans,e,pos,D,X,L,R,Y;

void add1(int x,int y){
    while (x) b[x]=min(b[x],y),x-=x&(-x);
}
int qry1(int x){
    int rt=n+1;
    while (x<maxn) rt=min(rt,b[x]),x+=x&(-x);
    return rt;
}
void add2(int x,int y){
    while (x<maxn) c[x]=max(c[x],y),x+=x&(-x);
}
int qry2(int x){
    int rt=0;
    while (x) rt=max(rt,c[x]),x-=x&(-x);
    return rt;
}
ll calc(ll x,ll y){
    //cout << x << ' '<< y << endl;
    ll rt=0; D=k;
    e=min(x,y); pos=0; X=(e+k-1)/k;
    L=1; R=L+D*(X-1);
    rt=rt+(L+R)*X/2;
    Y=(max(x,y)+1+k-1)/k;
    X=(max(x,y)+1+k-1)/k-X;
    rt=rt+(e+1)*X;
    X=(x+y+1+k-1)/k-Y;
    L=(x+y)-(x+y)/k*k+1; R=L+D*(X-1);
    rt=rt+(L+R)*X/2;
    //cout << rt << endl;
    return (rt-1)%M;
}
int main(){
    cin >> n >> k; k--;
    for (int i=1;i<=n;i++) {
        scanf("%d",&a[i].x); a[i].pos=i;
    }
    sort(a+1,a+n+1,cmp);
    for (int i=0;i<maxn;i++) b[i]=n+1,c[i]=0;
    for (int i=1;i<=n;i++){
        p=a[i].pos;
        r=qry1(p); l=qry2(p);
        (ans+=calc(p-l-1,r-p-1)*a[i].x)%=M;
        add1(p,p); add2(p,p);
        //cout << qry1(1) << ' ' << qry1(2) << ' ' << qry1(3) << endl;
    }
    cout << ans << endl;
}