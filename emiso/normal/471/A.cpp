//EM NOME DE ABELLA
#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
    int a[10],s=1,i,pernaok=0,b[2];
    scanf("%d%d%d%d%d%d",&a[0],&a[1],&a[2],&a[3],&a[4],&a[5]);
    sort(a,a+6);
    for(i=1;i<6;i++)
    {
                if(a[i]==a[i-1]) s++;
                else s=1;
                if(s==4)
                {
                        pernaok=1;
                        a[i]=0;
                        a[i-1]=0;
                        a[i-2]=0;
                        a[i-3]=0;
                        s=0;
                }
    }
    int j=0;
    b[0]=-2;
    b[1]=-3;
    if(pernaok==1) for(i=0;i<6;i++)
    {
                    if(a[i]!=0) 
                    {
                                b[j]=a[i];
                                j++;
                    }
    }
    if(pernaok==0) printf("Alien\n");
    else if(b[0]==b[1]) printf("Elephant\n");
    else printf("Bear\n");
    return 0;
}