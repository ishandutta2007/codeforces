#include<cstdio>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
using namespace std;
int x,y;
int main(){
    scanf("%d%d",&x,&y);
    if(x*2<=y)printf("%d\n",x);
    else if(y*2<=x)printf("%d\n",y);    
    else printf("%d\n",(x+y)/3);
}