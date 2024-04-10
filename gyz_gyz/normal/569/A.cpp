#include<cstdio>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define mx 100001
using namespace std;
int t,s,q,ans;
int main(){
    scanf("%d%d%d",&t,&s,&q);ans=1;
    while(1){s+=(q-1)*s;if(s>=t)break;ans++;}
    printf("%d\n",ans);
}