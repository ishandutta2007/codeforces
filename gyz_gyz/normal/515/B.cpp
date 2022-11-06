#include<cstdio>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define mx 1000000
using namespace std;
long long a[mx],b[mx],ans;
int v1[mx],v2[mx],n,m,t,x,al;
int main(){
    scanf("%d%d",&n,&m);al=n+m;
    rep(i,0,n-1)a[i]=n*m;rep(i,0,m-1)b[i]=n*m;
    scanf("%d",&t);rep(i,1,t){
        scanf("%d",&x);a[x]=x;v1[x]=1;
        if(x<b[x%m])b[x%m]=x;v2[x%m]=1;
    }
    scanf("%d",&t);rep(i,1,t){
        scanf("%d",&x);b[x]=x;v2[x]=1;
        if(x<a[x%n])a[x%n]=x;v1[x%n]=1;
    }
    rep(i,0,n-1)al-=v1[i];rep(i,0,m-1)al-=v2[i];
    rep(i,0,n-1)if(v1[i]){
        int p=a[i];
        for(int j=(i+m)%n;!v1[j];j=(j+m)%n){
            p+=m;if(p>ans)ans=p;al--;
        }
    }
    rep(i,0,m-1)if(v2[i]){
        int p=b[i];
        for(int j=(i+n)%m;!v2[j];j=(j+n)%m){
            p+=n;if(p>ans)ans=p;al--;
        }
    }
    if(al)printf("No\n");else printf("Yes\n");
}