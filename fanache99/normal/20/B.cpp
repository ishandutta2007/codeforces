#include<stdio.h>
#include<cmath>
using namespace std;
char s[101];
int main(){
    //freopen("tema.in","r",stdin);
    //freopen("tema.out","w",stdout);
    double a,b,c,x1,x2,d;
    scanf("%lf%lf%lf",&a,&b,&c);
    if(a==0&&b==0&&c==0)
        printf("-1");
    else{
        d=b*b-4*a*c;
        if(d<0)
            printf("0");
        else
            if(a==0)
                if(b!=0)
                    printf("1\n%lf",-1*c/b);
                else
                    printf("0");
            else{
                x1=(-1*b-sqrt(d))/(2*a);
                x2=(-1*b+sqrt(d))/(2*a);
                if(x1>x2){
                    d=x1;
                    x1=x2;
                    x2=d;
                }
                if(x1==x2)
                    printf("1\n%lf",x1);
                else
                    printf("2\n%lf\n%lf",x1,x2);
            }
    }
    return 0;
}