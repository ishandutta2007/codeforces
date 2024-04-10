#include<stdio.h>
using namespace std;
int main(){
    //freopen("tema.in","r",stdin);
    //freopen("tema.out","w",stdout);
    int n,p1,p2,p3,t1,t2,l,r,s=0,a,b,i;
    scanf("%d%d%d%d%d%d",&n,&p1,&p2,&p3,&t1,&t2);
    scanf("%d%d",&l,&r);
    s=s+(r-l)*p1;
    a=r;
    for(i=2;i<=n;i++){
        scanf("%d%d",&l,&r);
        s=s+(r-l)*p1;
        b=l-a;
        if(b<=t1)
            s=s+b*p1;
        else{
            s=s+t1*p1;
            b-=t1;
            if(b<=t2)
                s=s+b*p2;
            else{
                s=s+t2*p2;
                b-=t2;
                s=s+b*p3;
            }
        }
        a=r;
    }
    printf("%d",s);
    return 0;
}