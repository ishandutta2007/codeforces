#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define forg(i,x) for(int i=fir[x];i;i=nxt[i])
#define uu unsigned
#define scanf a1234=scanf
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
int a1234;
char buf[1<<18],*bufs=buf,*buft=buf;
inline int gc(){
    return bufs==buft&&(buft=(bufs=buf)+fread(buf,1,1<<18,stdin)),bufs==buft?-1:*bufs++;
}
inline void xxx(){for(;;);}
inline int rd(int l,int r){return rand()%(r-l+1)+l;}

const int mxn=6e5+3;
char s[mxn];
int l1,l2,l3,n,m;
int len[mxn],fa[mxn],ts[mxn][26],pos[mxn];
int tt,lst;
int tmp[mxn],pu[mxn];
int siz[mxn][3];
inline void extend(int c){
    int p=lst,q,np,nq;
    if(ts[p][c]){
        q=ts[p][c];
        if(len[q]==len[p]+1)lst=q;else{
            lst=nq=++tt,len[nq]=len[p]+1;
            fa[nq]=fa[q],memcpy(ts[nq],ts[q],sizeof(ts[q]));
            fa[q]=nq;
            for(;ts[p][c]==q;p=fa[p])ts[p][c]=nq;
        }
    }else{
        lst=np=++tt; len[np]=len[p]+1;
        for(;p&&!ts[p][c];p=fa[p])ts[p][c]=np;
        if(!p)fa[np]=1;else{
            q=ts[p][c];
            if(len[q]==len[p]+1)fa[np]=q;else{
                nq=++tt; len[nq]=len[p]+1;
                fa[nq]=fa[q],memcpy(ts[nq],ts[q],sizeof(ts[q]));
                fa[q]=fa[np]=nq;
                for(;ts[p][c]==q;p=fa[p])ts[p][c]=nq;
            }
        }
    }
}

int to[mxn],nxt[mxn],fir[mxn],gn;
inline void gadd(int x,int y){to[++gn]=y,nxt[gn]=fir[x],fir[x]=gn;}

int main(){
#undef assert
    scanf("%s",s+1),l1=strlen(s+1); scanf("%s",s+l1+1),l2=strlen(s+1); scanf("%s",s+l2+1),l3=strlen(s+1); n=l3; m=min(min(l1,l2-l1),l3-l2);
    tt=lst=1; for(int i=1;i<=l1;++i)extend(s[i]-'a'),pos[i]=lst,siz[lst][0]=1;
    lst=1; for(int i=l1+1;i<=l2;++i)extend(s[i]-'a'),pos[i]=lst,siz[lst][1]=1;
    lst=1; for(int i=l2+1;i<=l3;++i)extend(s[i]-'a'),pos[i]=lst,siz[lst][2]=1;
    for(int i=1;i<=tt;++i)++tmp[len[i]];
    for(int i=1;i<=n;++i)tmp[i]+=tmp[i-1];
    for(int i=1;i<=tt;++i)pu[tmp[len[i]]--]=i;
    for(int i=2;i<=tt;++i)gadd(fa[i],i);
//    assert(len[1]==0);    for(int i=2;i<=tt;++i)assert(len[i]);
    for(int i=tt,x;i>1;--i)x=pu[i],siz[fa[x]][0]+=siz[x][0],siz[fa[x]][1]+=siz[x][1],siz[fa[x]][2]+=siz[x][2];
//    printf("%d %d %d\n",l1,l2-l1,l3-l2);for(int i=0;i<3;++i)printf("%d ",siz[1][i]);puts("");for(int i=0;i<3;++i)printf("%d ",siz[0][i]);puts("");
/*
    for(int i=1;i<=m;++i){
        long long ans=0;
        for(int j=1;j<=tt;++j)if(len[j]>=i&&len[fa[j]]<i)ans+=1ll*siz[j][0]*siz[j][1]*siz[j][2];
        printf("%lld\n",ans);
    }*/
    int p=1;
    long long ans=0;
    for(int i=1;i<=m;++i){
        for(;len[pu[p]]==i-1;++p){
            int x=pu[p];
            if(x!=1)ans-=1ll*siz[x][0]*siz[x][1]*siz[x][2];
            forg(j,x)ans+=1ll*siz[to[j]][0]*siz[to[j]][1]*siz[to[j]][2];
        }
        printf("%lld ",ans%1000000007);
    } puts("");
    return 0;
}