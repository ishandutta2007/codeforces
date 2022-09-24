#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<utility>
using namespace std;
int n,X,Y,K,p[100005],h[100005],cnt,in1[100005],out1[100005],used[100005];
int size[100005];
long long pwk[100005]= {1},ny[100005]= {1};
long long Power(long long x,long long y) {
    if(!y)return 1;
    long long ret=Power(x,y/2);
    if(y&1)return ret*ret%Y*x%Y;
    else return ret*ret%Y;
}
struct TMP {
    int num;
    long long value;
    bool operator <(const TMP yy) const {
        return value<yy.value;
    }
}tmp1[100005],tmp2[100005];
int tot=0;
//vector<TMP> tmp;
struct Edge {
    int to,next;
} e[200005];
void Add_Edge(int x,int y) {
    e[++cnt].to=y;
    e[cnt].next=h[x];
    h[x]=cnt;
}
void FindCenter(int now,int fa,int all,int &minn,int &center) {
    int maxx=0;
    for(int i=h[now]; i; i=e[i].next) {
        int y=e[i].to;
        if(y==fa||used[y])continue;
        FindCenter(y,now,all,minn,center);
        maxx=max(maxx,size[y]);
    }
    maxx=max(maxx,all-size[now]);
    if(maxx<minn)minn=maxx,center=now;
}
void GetSize(int now,int fa) {
    size[now]=1;
    for(int i=h[now]; i; i=e[i].next) {
        int y=e[i].to;
        if(y==fa||used[y])continue;
        GetSize(y,now);
        size[now]+=size[y];
    }
}
void DFS(int now,int fa,int depth,long long vu,long long vd) {
    //vu:
    //vd:
    vu=(vu*K%Y+p[now])%Y;
    if(depth)vd=(vd+p[now]*pwk[depth-1]%Y)%Y;
    tmp1[++tot].num=now,tmp1[tot].value=(X-vu+Y)*ny[depth+1]%Y;
    tmp2[tot].num=now,tmp2[tot].value=vd;
    for(int i=h[now]; i; i=e[i].next) {
        int y=e[i].to;
        if(y==fa||used[y])continue;
        DFS(y,now,depth+1,vu,vd);
    }
}
void Calc(int now,int depth,long long vu,long long vd,int dlt) {
    //vu:
    //vd:
    tot=0;
    vu=(vu*K%Y+p[now])%Y;
    if(depth)vd=(vd+p[now]*pwk[depth-1]%Y)%Y;
    tmp1[++tot].num=now,tmp1[tot].value=(X-vu+Y)*ny[depth+1]%Y;
    tmp2[tot].num=now,tmp2[tot].value=vd;
    for(int i=h[now]; i; i=e[i].next) {
        int y=e[i].to;
        if(used[y])continue;
        DFS(y,now,depth+1,vu,vd);
    }
    sort(tmp1+1,tmp1+tot+1);
    sort(tmp2+1,tmp2+tot+1);
    int ts=0;
    for(int i=1,j=1;i<=tot;i++){
        while(j<=tot&&tmp2[j].value<=tmp1[i].value){
            if(j==1||tmp2[j].value!=tmp2[j-1].value)ts=0;
            ts++,j++;
        }
        if(j!=1&&tmp2[j-1].value==tmp1[i].value)out1[tmp1[i].num]+=ts*dlt;
        //cout<<tmp1[i].num<<' '<<tmp1[i].value<<endl;
    }
    ts=0;
    for(int i=1,j=1;j<=tot;j++){
        while(i<=tot&&tmp1[i].value<=tmp2[j].value){
            if(i==1||tmp1[i].value!=tmp1[i-1].value)ts=0;
            ts++,i++;
        }
        if(i!=1&&tmp1[i-1].value==tmp2[j].value)in1[tmp2[j].num]+=ts*dlt;
    }
}
void Dianfenzhi(int now) {
    int minn=0x3f3f3f3f,center=0;
    FindCenter(now,0,size[now],minn,center);
    used[center]=1;
    GetSize(center,0);
    Calc(center,0,0,0,1);
    //cout<<now<<' '<<center<<endl;
    for(int i=h[center]; i; i=e[i].next) {
        int y=e[i].to;
        if(!used[y])Calc(y,1,p[center],0,-1);
    }
    for(int i=h[center]; i; i=e[i].next) {
        int y=e[i].to;
        if(!used[y])Dianfenzhi(y);
    }
}
int main() {
    scanf("%d%d%d%d",&n,&Y,&K,&X);
    X%=Y,K%=Y;
    for(int i=1; i<=n; i++)scanf("%d",&p[i]),pwk[i]=pwk[i-1]*K%Y,p[i]%=Y,ny[i]=Power(pwk[i],Y-2);
    for(int i=1,x,y; i<n; i++) {
        scanf("%d%d",&x,&y);
        Add_Edge(x,y);
        Add_Edge(y,x);
    }
    GetSize(1,0);
    Dianfenzhi(1);
    long long ans=0;
    for(int i=1; i<=n; i++) {
        int in0=n-in1[i],out0=n-out1[i];
        ans+=2ll*in0*in1[i]+2ll*out0*out1[i]+1ll*in0*out1[i]+1ll*in1[i]*out0;
    }
    printf("%lld\n",1ll*n*n*n-ans/2);
    return 0;
}