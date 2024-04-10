#include<cstdio>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define mx 131072
#define ll long long
#define lb(x) ((x)&(-(x)))
#define tc(x) (((x)-1)%n+1)
#define inf 1000000000
using namespace std;
ll k,r,t;int s[mx],L[mx*2],R[mx*2],n,m,P;
struct sx{ll x,y1,y2,z;
    sx operator * (const sx& b){sx a=*this,c;
        c.x=(a.x*b.x+a.y2*b.y1)%P;
        c.y1=(a.y1*b.x+a.z*b.y1)%P;
        c.y2=(a.x*b.y2+a.y2*b.z)%P;
        c.z=(a.y1*b.y2+a.z*b.z)%P;  
        return c;
    }
}a[mx*2],ww,ans;
struct pr{ll x;int y;}w[mx];
inline bool cmp(pr x,pr y){return x.x<y.x;}
sx q(int x,int l,int r){
    if(L[x]==l&&R[x]==r)return a[x];
    if(r<=R[x*2])return q(x*2,l,r);
    if(l>=L[x*2+1])return q(x*2+1,l,r);
    return q(x*2,l,R[x*2])*q(x*2+1,L[x*2+1],r);
}
sx p(ll x){
    if(x==1)return a[1];
    sx rr=p(x/2);rr=rr*rr;
    if(x&1)rr=rr*a[1];return rr;
}
int main(){
    scanf("%I64d%d%d",&k,&P,&n);
    if(k==0){printf("0\n");return 0;}
    rep(i,1,n)scanf("%d",&s[i]);scanf("%d",&m);
    rep(i,1,m){scanf("%I64d%d",&w[i].x,&w[i].y);w[i].x++;w[i].y%=P;}
    sort(w+1,w+m+1,cmp);
    rep(i,1,n)s[i]%=P;
    rep(i,1,mx){
        a[i+mx-1].x=1;a[i+mx-1].z=1;L[i+mx-1]=i;R[i+mx-1]=i;
    }
    rep(i,1,n){
        a[i+mx-1].x=0;a[i+mx-1].z=s[i%n+1];
        a[i+mx-1].y1=1;a[i+mx-1].y2=s[i];
    }
    dep(i,mx-1,1){
        L[i]=L[i*2];R[i]=R[i*2+1];a[i]=a[i*2]*a[i*2+1];
    }
    for(;w[m].x>k;m--)w[m].x=0,w[m].y=0;
    if(w[m].x!=k)w[++m].x=k,w[m].y=s[tc(k)];ans.x=1;ans.z=1;
    rep(i,1,m){
        r=(w[i].x-3)/n-(w[i-1].x)/n;
        if(i>1){
            if(w[i].x==w[i-1].x+1){
                ww.x=0;ww.z=w[i].y;ww.y1=1;
                ww.y2=w[i-1].y;ans=ans*ww;continue;
            }
            ww.x=0;ww.y1=1;ww.y2=w[i-1].y;
            ww.z=s[tc(w[i-1].x+1)];ans=ans*ww;  
        }
        if(r>0)ans=ans*q(1,tc(w[i-1].x+1),n);
        if(r>1)ans=ans*p(r-1);
        if(w[i-1].x+2<=w[i].x-1)
            if(r<=0)ans=ans*q(1,tc(w[i-1].x+1),tc(w[i].x-2));
            else ans=ans*q(1,1,tc(w[i].x-2));
        ww.x=0;ww.y1=1;ww.y2=s[tc(w[i].x-1)];ww.z=w[i].y;ans=ans*ww;
    }
    printf("%I64d\n",ans.z);
}