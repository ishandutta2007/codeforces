#include<cstdio>
#include<map>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define N 262144
#define inf 1000000000
using namespace std;
map<int,int>mp;
int n,k,d,l,r,T,s,t1,t2;
int p[N],p1[N],p2[N],q1[N],q2[N],a[N*2],b[N*2],L[N*2],R[N*2];
inline void dw(int x){
    a[x*2+1]+=b[x];b[x*2+1]+=b[x];
    a[x*2]+=b[x];b[x*2]+=b[x];b[x]=0;
}
inline void up(int x){
    if(a[x*2]<a[x*2+1])a[x]=a[x*2];else a[x]=a[x*2+1];
}
void f(int x,int y,int l,int r){
    if(l==L[x]&&r==R[x]){a[x]+=y;b[x]+=y;return;}dw(x);
    if(r<=R[x*2]){f(x*2,y,l,r);up(x);return;}
    if(l>=L[x*2+1]){f(x*2+1,y,l,r);up(x);return;}
    f(x*2,y,l,R[x*2]);f(x*2+1,y,L[x*2+1],r);up(x);
}
int q(int x,int y,int l,int r){
    if(R[x]==2){
        R[x]=2;
    }
    if(l==L[x]&&r==R[x]){if(a[x]>y)return -1;
        while(L[x]!=R[x]){dw(x);x*=2;if(a[x]>y)x++;}
        return L[x];
    }dw(x);
    if(r<=R[x*2])return q(x*2,y,l,r);
    if(l>=L[x*2+1])return q(x*2+1,y,l,r);
    T=q(x*2,y,l,R[x*2]);
    if(T==-1)return q(x*2+1,y,L[x*2+1],r);else return T;
}
int main(){
    scanf("%d%d%d",&n,&k,&d);s=1;r=-1;
    rep(i,1,n){scanf("%d",&p[i]);p[i]+=inf;}
    if(d==0){s=1;l=1;r=1;
        rep(i,2,n){
            if(p[i]==p[i-1])s++;else s=1;
            if(s>r-l+1)l=i-s+1,r=i;
        }
        printf("%d %d\n",l,r);return 0;
    }
    L[1]=1;R[1]=N;
    rep(i,1,N-1){
        L[i*2]=L[i];R[i*2]=(L[i]+R[i])/2;
        L[i*2+1]=R[i*2]+1;R[i*2+1]=R[i];
    }
    rep(i,1,n)a[i+N-1]=i;
    dep(i,N-1,1)up(i);
    rep(i,1,n){
        for(;t1&&p[i]/d>=p1[t1];t1--)
            f(1,p[i]/d-p1[t1],q1[t1-1]+1,q1[t1]);
        for(;t2&&p[i]/d<=p2[t2];t2--)
            f(1,p2[t2]-p[i]/d,q2[t2-1]+1,q2[t2]);
        p1[++t1]=p[i]/d;q1[t1]=i;
        p2[++t2]=p[i]/d;q2[t2]=i;
        if(i>1&&p[i]%d!=p[i-1]%d)s=i;
        if(mp[p[i]]+1>s)s=mp[p[i]]+1;mp[p[i]]=i;
        T=q(1,i+k,s,i);if(i-T+1>r-l+1)l=T,r=i;
    }
    printf("%d %d\n",l,r);
}