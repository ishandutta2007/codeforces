#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define NO_FATHER 0
#define NO_LENGTH 0
#define INFINITY 0x3f3f3f3f
#define int long long
using namespace std;
int n,k,q,h[100005],ecnt,vst[100005],subcnt[100005],ans,d[100005],cnt[100005],core,minsum;
struct Edge{
    int to,next,value;
}e[200005];
void Add_Edge(int x,int y,int z){
    e[++ecnt].to=y;
    e[ecnt].value=z;
    e[ecnt].next=h[x];
    h[x]=ecnt;
}
void FindCenter(int point,int father,int size){
    int sum=0;
    subcnt[point]=1;
    for(int i=h[point];i;i=e[i].next){
        int y=e[i].to;
        if(vst[y]||y==father)continue;
        FindCenter(y,point,size);
        subcnt[point]+=subcnt[y];
        sum=max(sum,subcnt[y]);
    }
    sum=max(sum,size-subcnt[point]);
    if(sum<minsum){
        minsum=sum;
        core=point;
    }
}
void AddUp(int point,int father,int dist){
    d[++d[0]]=dist;
    cnt[point]=1;
    for(int i=h[point];i;i=e[i].next){
        int y=e[i].to;
        if(vst[y]||y==father)continue;
        AddUp(y,point,dist+e[i].value);
        cnt[point]+=cnt[y];
    }
}
int GetAnswer(int root,int length){
    int ret=0;
    d[0]=0;
    AddUp(root,NO_FATHER,length);
    sort(d+1,d+d[0]+1);
    int l=1,r=d[0];
    while(l<r){
        if(d[l]+d[r]<=k)ret+=r-l,l++;
        else r--;
    }
    return ret;
}
void DFS(int point,int size){
    minsum=INFINITY;
    FindCenter(point,NO_FATHER,size);
    ans+=GetAnswer(core,NO_LENGTH);
    vst[core]=1;
    for(int i=h[core];i;i=e[i].next){
        int y=e[i].to;
        if(!vst[y]){
            ans-=GetAnswer(y,e[i].value);
            DFS(y,cnt[y]);
        }
    }
}
signed main(){
	int l;
    scanf("%lld%lld",&n,&l);
    for(int i=1;i<n;i++){
        int x,y,z;
        scanf("%lld%lld",&x,&y);
        Add_Edge(x,y,1);
        Add_Edge(y,x,1);
    }
//    for(int i=1;i<=q;i++){
//        int l;
//        scanf("%d",&l);
        k=l;
        ans=0;
        memset(vst,0,sizeof(vst));
        DFS(1,n);
        int dd=ans;
        ans=0;
        k=l-1;
        memset(vst,0,sizeof(vst));
        DFS(1,n);
//        if(ans==dd)puts("NAY");
//        else puts("AYE");
        printf("%lld",dd-ans);
    return 0;
}