#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define forg(i,x) for(register int i=fir[x];i;i=nxt[i])
#define uu unsigned
#define scanf a1234=scanf
#define rint register int
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
int a1234;
inline void xxx(){for(;;);}
inline int rd(int l,int r){return rand()%(r-l+1)+l;}


int n,gn,l[55],r[55],len[55];
struct thr{
    int x,y,l;
    thr(){}
    thr(int a,int b,int c){x=a,y=b,l=c;}
}ed[100000];
 
int main(){
    puts("YES");
    int lx,rx;scanf("%d%d",&lx,&rx);
    len[1]=len[2]=1;
    for(int i=3;i<=30;++i)len[i]=len[i-1]*2;
    for(int i=2;i;++i){
        n=i;
        l[i]=r[i-1]+1,r[i]=r[i-1]+len[i];
        if(r[i]<=rx-lx){
            int k=l[i];
            for(int j=1;j<i;++j)ed[++gn]=thr(j,i,k-l[j]),k+=len[j];
        }else{
//            cout<<i<<' '<<rx-lx-r[i-1]<<endl;
            int k=l[i];
            for(int t=rx-lx-r[i-1],j=2;t;t>>=1,++j)if(t&1){
                ed[++gn]=thr(j,i,k-l[j]),k+=len[j];
            }
        }
        if(r[i]>=rx-lx)break;
    }
    ++n;for(int i=1;i<n;++i)ed[++gn]=thr(i,n,lx);
    printf("%d %d\n",n,gn);
    for(int i=1;i<=gn;++i)printf("%d %d %d\n",ed[i].x,ed[i].y,ed[i].l);
    return 0;
}