/* testing code for prof_paradox */

#include<stdio.h>
int main() /* making this int, rather than void */
{
    int i,k=0;
    scanf("%d",& i);
    int a[i];
    for(int j=0;j<i;j++)
    {
        scanf("%d",& a[j]);
        if(a[j]==1)
        {
            k=1;
            break;
        }
     }
    if(k==1)
    {
        printf("HARD");
    }
    else{
        printf("EASY");
    }
}