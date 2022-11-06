#include<cstdio>
#include<vector>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define mx 100001
using namespace std;
vector<int>e[mx];
int n,m,k,x,y,w,t[mx],d[mx],v[mx],s[mx];
double l,r,mid;
void del(int x){
    v[x]=0;s[x]=0;w--;
    rep(i,0,d[x]-1){
        int tt=e[x][i];
        if(v[tt]){
            s[tt]--;if(d[tt]*mid>s[tt])del(tt);
        }
    }
}
int main(){
    scanf("%d%d%d",&n,&m,&k);
    rep(i,1,k){scanf("%d",&x);t[x]=1;}
    rep(i,1,m){
        scanf("%d%d",&x,&y);
        e[x].push_back(y);d[x]++;
        e[y].push_back(x);d[y]++;
    }
    l=0;r=1;mid=(l+r)/2;
    for(;r-l>1e-9;mid=(l+r)/2){
        rep(i,1,n)v[i]=1-t[i],s[i]=0;w=0;
        rep(i,1,n)if(v[i]){
            w++;rep(j,0,d[i]-1)if(v[e[i][j]])s[i]++;
        }
        rep(i,1,n)if(v[i])if(d[i]*mid>s[i])del(i);
        if(!w)r=mid;else l=mid;
    }mid-=1e-9;
    rep(i,1,n)v[i]=1-t[i],s[i]=0;w=0;
    rep(i,1,n)if(v[i]){
        w++;rep(j,0,d[i]-1)if(v[e[i][j]])s[i]++;
    }
    rep(i,1,n)if(v[i])if(d[i]*mid>s[i])del(i);
    printf("%d\n",w);rep(i,1,n)if(v[i])printf("%d ",i);printf("\n");
}