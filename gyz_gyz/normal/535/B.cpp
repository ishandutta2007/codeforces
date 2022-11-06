#include<cstdio>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
using namespace std;
int n,ans,v;
int main(){
    for(scanf("%d",&n),v=1;n;n/=10){
        if(n%10==7)ans+=v;v*=2;
    }
    printf("%d\n",ans+v-1);
}