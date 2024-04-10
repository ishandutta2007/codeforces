#include<cstdio>
#include<cstring>
#include<vector>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define mx 1000002
using namespace std;
vector<int>r[mx];char c[mx];
int a[mx],ls[mx],lx[mx],b[mx],g[mx],l,p,k,kk,s;
int main(){
    scanf("%s",c);l=strlen(c);k=0;
    rep(i,0,l-1)if(c[i]=='(')a[i]=kk+1,b[p++]=i,k=1;if(k)kk++,k=0;
    rep(i,0,l-1)if(c[i]==')')a[i]=kk+1,b[p++]=i,k=1;if(k)kk++,k=0;
    rep(j,0,20){
        k=1<<j;if(k>=l)break;
        rep(i,1,kk)r[i].clear();s=0;
        rep(i,0,l-1)p=(b[i]-k+l)%l,r[a[p]].push_back(p);
        p=0;rep(i,1,kk){
            int sz=r[i].size()-1;
            g[r[i][0]]=++s;b[p++]=r[i][0];
            rep(ii,1,sz){
                int w=r[i][ii];b[p++]=w;
                if(a[(w+k)%l]!=a[(r[i][ii-1]+k)%l])g[w]=++s;else g[w]=s;
            }
        }
        rep(i,0,l-1)a[i]=g[i];kk=s;
    }
    a[0]=0;rep(i,1,l)if(c[i-1]=='(')a[i]=1;else a[i]=-1;
    rep(i,2,l)a[i]+=a[i-1];ls[0]=l;lx[l+1]=l;if(a[l]>0)p=0;else p=a[l];
    rep(i,1,l)if(ls[i-1]<a[i])ls[i]=ls[i-1];else ls[i]=a[i];
    dep(i,l,1)if(lx[i+1]<a[i])lx[i]=lx[i+1];else lx[i]=a[i];
    rep(i,0,l-1){
        int ii=b[i]+1;
        if(lx[ii]-a[ii-1]>=p&&ls[ii-1]+a[l]-a[ii-1]>=p){
            if(a[l]<0)rep(j,1,-a[l])printf("(");
            rep(j,ii-1,l-1)printf("%c",c[j]);
            rep(j,0,ii-2)printf("%c",c[j]);
            if(a[l]>0)rep(j,1,a[l])printf(")");return 0;
        }
    }
}