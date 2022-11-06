#include<cstdio>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
using namespace std;
int n,p,ans;char c[200][200];
int main(){
    scanf("%d",&n);
    rep(i,1,n)scanf("%s",c[i]+1);
    rep(i,1,n){p=0;
        rep(j,1,n){p++;
            rep(k,1,n)if(c[i][k]!=c[j][k]){
                p--;break;
            }
        }
        if(p>ans)ans=p;
    }
    printf("%d\n",ans);
}