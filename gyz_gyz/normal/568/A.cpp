#include<cstdio>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
using namespace std;
int pi,rub,p,q,ans,w,ii,u,rt[10];
int main(){
    scanf("%d%d",&p,&q);
    rep(i,1,1500000){u=0;
        rep(j,2,i-1){
            if(j*j>i)break;
            if(i%j==0){u=1;break;}
        }
        if(!u&&i>1)pi++;
        w=0;ii=i;while(ii)rt[++w]=ii%10,ii/=10;u=0;
        rep(j,1,w/2)if(rt[j]!=rt[w-j+1]){u=1;break;}
        if(!u)rub++;if(pi*q<=rub*p)ans=i;
    }
    printf("%d\n",ans);
}