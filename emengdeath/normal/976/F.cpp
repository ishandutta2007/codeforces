#include<bits/stdc++.h>
using namespace std;
const int N=4e3+10;
const int MAXN=1e9;
int n,m,ans,flow,sum,L;
int g[N],a[N*200][4],vh[N],dis[N],di[N],pre[N],his[N],e[N][2],in[N],d[N];
void ins(int x,int y,int z,int zz){
    a[++sum][0]=y,a[sum][1]=z,a[sum][2]=g[x],g[x]=sum;
    a[sum][3]=zz;
    a[++sum][0]=x,a[sum][1]=0,a[sum][2]=g[y],g[y]=sum;
    a[sum][3]=0;
}
void clear(){
    for (int i=0;i<N;i++)
        vh[i]=di[i]=pre[i]=his[i]=dis[i]=0;
}
void sap(int s,int t){
    static int x,argue,mn,k;
    static bool p;
    clear();
    flow=0;
    argue=MAXN,x=s;
    vh[0]=t+1;
    while (dis[s]<=t+1){
        p=0;
        his[x]=argue;
        for (int i=di[x];i;i=a[i][2])
            if (a[i][1]&&dis[x]==dis[a[i][0]]+1){
                p=1,argue=min(argue,a[i][1]),di[x]=i,pre[a[i][0]]=x;
                x=a[i][0];
                if (x==t){
                    flow+=argue;
                    while (x!=s){
                        x=pre[x];
                        a[di[x]][1]-=argue;
                        a[di[x]^1][1]+=argue;
                    }
                    argue=MAXN;
                }
                break;
            }
        if (!p){
            if (!(--vh[dis[x]]))break;
            mn=t+2;
            for (int i=g[x];i;i=a[i][2])
                if (a[i][1]&&dis[a[i][0]]<mn)
                    mn=dis[a[i][0]],k=i;
            ++vh[dis[x]=++mn];
            di[x]=k;
            if (x!=s)
                x=pre[x],argue=his[x];
        }
    }
}
void work(int num){
    sum=1;
    for (int i=0;i<=n+m+3;i++)g[i]=0;
    for (int i=1;i<=n;i++)
        ins(0,i,in[i]-num,0);
    for (int i=1;i<=m;i++)
        ins(i+n,n+m+1,in[i+n]-num,0);
    for (int i=1;i<=L;i++)ins(e[i][0],e[i][1]+n,1,i);
    sap(0,n+m+1);
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m>>L; 
    cout<<0<<endl;
    for (int i=1;i<=L;i++)
        cin>>e[i][0]>>e[i][1],in[e[i][0]]++,in[e[i][1]+n]++;
    int mn=in[1];
    for (int i=1;i<=n+m;i++)mn=min(mn,in[i]);
    for (int num=1;num<=mn;num++){
        work(num);
        d[0]=0;
        for (int i=1;i<=sum;i++)
            if (a[i][3]>0&&a[i][1]){
                d[++d[0]]=a[i][3];
            }
        cout<<d[0];
        for (int i=1;i<=d[0];i++)
            cout<<' '<<d[i];
        cout<<endl;
    }
    return 0;
}