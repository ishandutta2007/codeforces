#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef double db;
const int maxn=1e5+10;
const db pi=acos(-1.0);
db l,r,mid;
int n,k,a[maxn],b[maxn];
struct node{
    db x;
    int val;
};
bool cmp(node u,node v){return u.x<v.x;}
db f(db x){
    while (x<0) x+=pi*2;
    while (x>pi) x-=pi*2;
    return x;
}
vector<node> event;
void ins(db L,db R){
    event.pb((node){L,1});
    event.pb((node){R,-1});
}
int solve(db R){
    event.clear();
    for (int i=1;i<=n;i++){
        if (!a[i]&&!b[i]) continue;
        db x=a[i],y=b[i];
        db d=sqrt(x*x+y*y);
        if (d/2>=R) continue;
        db p=atan2(x,y);
        db q=acos(d/2/R);
        db L=f(p-q),R=f(p+q);
        if (L<R) ins(L,R),ins(L+pi*2,R+pi*2); else ins(L,R+pi*2);
    }
    sort(event.begin(),event.end(),cmp);
    int now=0,ret=0;
    for (auto x:event){
        now+=x.val;
        ret=max(ret,now);
    }
    return ret;
}
int main(){
    cin >> n >> k;
    for (int i=1;i<=n;i++){
        cin >> a[i] >> b[i];
        if (!a[i]&&!b[i]) --k;
    }
    l=0; r=2e5;
    for (int i=0;i<40;i++){
        mid=(l+r)*0.5;
        if (solve(mid)>=k) r=mid; else l=mid;
    }
    printf("%.10f\n",l);
    return 0;
}