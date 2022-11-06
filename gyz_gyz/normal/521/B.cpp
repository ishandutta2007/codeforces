#include<cstdio>
#include<map>
#include<set>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
using namespace std;
const long long md=1000000009ll;
map<int,int>w[300000];
set<int>a;
int x[300000],y[300000],m;
long long ans;
inline void tr(int i){
    int tmp=0;
    rep(j,-1,1)
        if(w[y[i]+1][x[i]+j]>m)tmp=1;
    if(!tmp)a.insert(i);
}
inline void fz(int i){
    int tmp=0;
    rep(j,-1,1)
        if(w[y[i]-1][x[i]+j])tmp++;
    if(tmp==1){
        w[y[i]][x[i]]=i+m+1;tmp=0;
        rep(j,-1,1)
            if(w[y[i]-1][x[i]+j]){
                if(w[y[i]-1][x[i]+j]>m){
                    tmp=w[y[i]-1][x[i]+j]-m-1;
                }else tmp=w[y[i]-1][x[i]+j]-1;
            }
        a.erase(tmp);
    }       
}
int main(){
    scanf("%d",&m);
    rep(i,0,m-1){
        scanf("%d%d",&x[i],&y[i]);
        w[y[i]][x[i]]=i+1;
    }
    rep(i,0,m-1){
        if(!y[i])continue;
        int tmp=0;
        rep(j,-1,1)
            if(w[y[i]-1][x[i]+j])tmp++;
        if(tmp==1)w[y[i]][x[i]]=i+m+1;
    }
    rep(i,0,m-1)tr(i);
    rep(i,0,m-1){
        int rr;
        if(i%2)rr=*(a.begin());else rr=*(--a.end());
        a.erase(rr);ans=(ans*m+rr)%md;
        int tmp=0;if(w[y[rr]][x[rr]]>m)tmp=1;
        w[y[rr]][x[rr]]=0;
        if(tmp)rep(j,-1,1)
            if(w[y[rr]-1][x[rr]+j]){
                if(w[y[rr]-1][x[rr]+j]>m){
                    tr(w[y[rr]-1][x[rr]+j]-m-1);
                }else tr(w[y[rr]-1][x[rr]+j]-1);
            }
        tmp=0;
        rep(j,-1,1)
            if(w[y[rr]+1][x[rr]+j]){
                if(w[y[rr]+1][x[rr]+j]>m){
                    fz(w[y[rr]+1][x[rr]+j]-m-1);
                }else fz(w[y[rr]+1][x[rr]+j]-1);
            }               
    }
    printf("%I64d",ans);
}