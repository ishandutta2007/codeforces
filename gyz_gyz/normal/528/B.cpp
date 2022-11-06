#include<cstdio>
#include<set>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define mx 200001
#define a(i) (a[i].a)
#define b(i) (a[i].b)
#define l (c.lower_bound(rr))
using namespace std;
struct pp{int a,b;}a[mx];int b[mx],n,ans;
struct pr{int a,b;
    inline friend bool operator < (const pr &a,const pr &b){
        return a.a!=b.a?a.a<b.a:a.b>b.b;
    }
}rr;set<pr>c;
inline bool cmp(pp a,pp b){return a.a<b.a;}
int main(){
    scanf("%d",&n);
    rep(i,1,n)scanf("%d%d",&a(i),&b(i));
    sort(a+1,a+n+1,cmp);
    rep(i,1,n){
        rr.a=a(i)-b(i);rr.b=0;
        if(l==c.begin())b[i]=1;else b[i]=(*(--l)).b+1;
        rr.a=a(i)+b(i);rr.b=b[i];
        if(l==c.begin()||(*(--l)).b<b[i]){
            while(l!=c.end()&&(*l).b<=b[i])c.erase(*l);
            c.insert(rr);
        }
    }
    rep(i,1,n)if(b[i]>ans)ans=b[i];
    printf("%d\n",ans);
}