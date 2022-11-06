#include<cstdio>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define Rep(i,x,y) for(int i=(x);i>=(y);i--)
#define mx 2000
using namespace std;
int n,m,x;long long ans;char c[mx][mx];
int u[mx][mx],d[mx][mx],l[mx][mx],r[mx][mx];
int main(){
    scanf("%d%d",&n,&m);
    rep(i,0,n-1)scanf("%s",c[i]);
    rep(i,1,n-2){bool u=1;
        rep(j,0,m-1)if(c[i][j]=='#'){u=0;break;}
        if(u)ans++;
    }
    rep(j,1,m-2){bool u=1;
        rep(i,0,n-1)if(c[i][j]=='#'){u=0;break;}
        if(u)ans++;
    }
    rep(i,0,n-1){
        rep(j,0,m-1){
            if(c[i][j]=='#')break;
            l[i][j]=1;
        }
        Rep(j,m-1,0){
            if(c[i][j]=='#')break;
            r[i][j]=1;
        }
    }
    rep(j,0,m-1){
        rep(i,0,n-1){
            if(c[i][j]=='#')break;
            u[i][j]=1;
        }
        Rep(i,n-1,0){
            if(c[i][j]=='#')break;
            d[i][j]=1;
        }
    }
    rep(i,1,n-2){
        rep(j,1,m-2){
            if(u[i][j]&&l[i][j])ans++;
            if(u[i][j]&&r[i][j])ans++;
            if(d[i][j]&&l[i][j])ans++;
            if(d[i][j]&&r[i][j])ans++;
        }
    }
    rep(i,1,n-2){x=0;
        rep(j,1,m-4){
            x+=u[i][j]+d[i][j];
            if(c[i][j]=='#')x=0;
            if(c[i][j+1]=='.'){
                if(u[i][j+2])ans+=x;
                if(d[i][j+2])ans+=x;
            }
        }
    }
    rep(i,1,n-2)
        rep(j,1,m-3){
            if(u[i][j]&&d[i][j+1])ans++;
            if(d[i][j]&&u[i][j+1])ans++;
        }           
    rep(j,1,m-2){x=0;
        rep(i,1,n-4){
            x+=l[i][j]+r[i][j];
            if(c[i][j]=='#')x=0;
            if(c[i+1][j]=='.'){
                if(l[i+2][j])ans+=x;
                if(r[i+2][j])ans+=x;
            }
        }
    }
    rep(j,1,m-2)
        rep(i,1,n-3){
            if(l[i][j]&&r[i+1][j])ans++;
            if(r[i][j]&&l[i+1][j])ans++;
        }
    printf("%I64d\n",ans);
}