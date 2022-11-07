#include<cstdio>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define mx 200001
using namespace std;
long long x,y,z,ans;
int main(){
    scanf("%I64d%I64d",&x,&y);
    while(y){ans+=x/y;z=x;x=y;y=z%y;}
    printf("%I64d",ans);
}