#include<cstdio>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define mx 501
#define add(x,y) x=(x+y)%1000000007
using namespace std;
int n,m,k;long long a[2][mx][mx],ans;char b[mx][mx];
int main(){
    scanf("%d%d",&n,&m);k=n+m-1;
    rep(i,1,n)scanf("%s",b[i]+1);
    a[1][1][n]=(b[1][1]==b[n][m]);
    rep(i,1,k/2-1){int op=k-i+1;int r=i&1;
        rep(j,1,i+1)rep(k,1,op+1)a[1-r][j][k]=0;
        rep(j,1,i){int x=i-j+1;
            if(x>m)continue;
            if(x<1||j>n)break;
            rep(s,1,op){int y=op-s+1;
                if(y>m)continue;
                if(y<1||s>n)break;
                if(j<n&&s>1&&b[j+1][x]==b[s-1][y])
                    add(a[1-r][j+1][s-1],a[r][j][s]);
                if(x<m&&s>1&&b[j][x+1]==b[s-1][y])
                    add(a[1-r][j][s-1],a[r][j][s]);
                if(j<n&&y>1&&b[j+1][x]==b[s][y-1])
                    add(a[1-r][j+1][s],a[r][j][s]);
                if(x<m&&y>1&&b[j][x+1]==b[s][y-1])
                    add(a[1-r][j][s],a[r][j][s]);
            }
        }
    }int r=(k/2)&1;
    if(k&1)rep(i,1,k/2){
        add(ans,a[r][i][i]);
        add(ans,a[r][i][i+1]*2);
        add(ans,a[r][i][i+2]);      
    }else rep(i,1,k/2){
        add(ans,a[r][i][i]);
        add(ans,a[r][i][i+1]);
    }       
    printf("%I64d\n",ans);
}