#include<stdio.h>
#include<math.h>
#include<map>
#include<algorithm>
#include<string.h>
#define SIZE 300000
using namespace std;
main(){

    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++,printf("\n"))
        for(int j=0;j<m;j++)
        {
            if(i%2==0)
                printf("#");
            else if(i%4==1&&j==m-1)
                printf("#");
            else if(i%4==3&&j==0)
                printf("#");
            else
                printf(".");

        }

    return 0;
}