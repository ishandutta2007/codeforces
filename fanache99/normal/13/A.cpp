#include <stdio.h>
using namespace std;
int cif(int n,int b){
    int s=0;
    while(n!=0){
        s=s+n%b;
        n/=b;
    }
    return s;
}
int main(){
    //freopen("tema.in","r",stdin);
    //freopen("tema.out","w",stdout);
    int a,i,x,y;
    scanf("%d%d",&a);
    y=a-2;
    x=0;
    for(i=2;i<=a-1;i++)
        x=x+cif(a,i);
    for(i=2;i<=1000;i++)
        while(x%i==0&&y%i==0){
            x/=i;
            y/=i;
        }
    printf("%d/%d",x,y);
    return 0;
}