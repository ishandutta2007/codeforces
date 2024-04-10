#include<stdio.h>
using namespace std;
int vc[10];
int main(){
    //freopen("tema.in","r",stdin);
    //freopen("tema.out","w",stdout);
    int n,m,cn,cm,pp=0,x=0,i=1;
    char c,d;
    scanf("%d\n",&n);
    scanf("%c%c",&c,&d);
    if(n==0)
        if(c!='0')
            printf("WRONG_ANSWER");
        else
            if(d>='0'&&d<='9')
                printf("WRONG_ANSWER");
            else
                printf("OK");
    else
        if(c=='0')
            printf("WRONG_ANSWER");
        else{
            m=(c-'0')*10+d-'0';
            while(scanf("%c",&c)!=EOF)
                if(c>='0'&&c<='9')
                    m=m*10+c-'0';
            cn=n;
            while(cn!=0){
                vc[cn%10]++;
                cn/=10;
            }
            i=1;
            while(vc[i]==0)
                i++;
            vc[i]--;
            x+=i;
            for(i=0;i<=9;i++)
                while(vc[i]!=0){
                    vc[i]--;
                    x=x*10+i;
                }
            if(x==m)
                printf("OK");
            else
                printf("WRONG_ANSWER");
        }
    return 0;
}