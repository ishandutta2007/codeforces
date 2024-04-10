#include<cstdio>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define mx 151
#define ll long long
#define inf 30000000
using namespace std;
char s[mx];
int n,p[mx],a[mx][mx][mx],t[mx];
int main(){
    scanf("%d",&n);
    rep(i,1,n)scanf("%d",&p[i]);
    scanf("%s",s+1);
    rep(i,1,n)rep(j,1,n)rep(k,0,n)a[i][j][k]=-inf;
    rep(i,1,n)a[i][i][1]=0;
    rep(i,1,n-1)if(s[i]==s[i+1])a[i][i+1][2]=0;
    rep(i,0,n-1){
        rep(l,1,n){int r=l+i;if(r>n)break;
            rep(j,1,i+1)if(p[j]>=0&&a[l][r][j]+p[j]>a[l][r][0])
                a[l][r][0]=a[l][r][j]+p[j];
        }
        rep(l,1,n){int r=l+i;
            if(r>n)break;
            rep(j,0,i+1)if(l>1&&r<n&&s[l-1]==s[r+1])
                if(a[l][r][j]>a[l-1][r+1][j+2])a[l-1][r+1][j+2]=a[l][r][j];
            rep(k,1,i+1){
                if(l-k>0)rep(j,0,i+1){
                    if(a[l][r][j]+a[l-k][l-1][0]>a[l-k][r][j])
                        a[l-k][r][j]=a[l][r][j]+a[l-k][l-1][0];
                }
                if(r+k<=n)rep(j,0,i+1){
                    if(a[l][r][j]+a[r+1][r+k][0]>a[l][r+k][j])
                        a[l][r+k][j]=a[l][r][j]+a[r+1][r+k][0];
                }
            }
            rep(k,1,i){
                if(l-k>0)rep(j,0,k){
                    if(a[l][r][0]+a[l-k][l-1][j]>a[l-k][r][j])
                        a[l-k][r][j]=a[l][r][0]+a[l-k][l-1][j];
                }
                if(r+k<=n)rep(j,0,k){
                    if(a[l][r][0]+a[r+1][r+k][j]>a[l][r+k][j])
                        a[l][r+k][j]=a[l][r][0]+a[r+1][r+k][j];
                }
            }           
        }
    }
    rep(i,1,n){
        t[i]=t[i-1];
        rep(j,1,i)if(t[j-1]+a[j][i][0]>t[i])
            t[i]=t[j-1]+a[j][i][0];
    }
    printf("%d\n",t[n]);
}