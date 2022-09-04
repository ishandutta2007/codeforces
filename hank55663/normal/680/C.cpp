#include<bits/stdc++.h>
#define N 20005
using namespace std;
int prime[19]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67};
main(){
    int ok=1;
    int num[19],nn=0;
   // for(int p=2;p<=100;p++){
            nn=0;ok=1;
        memset(num,0,sizeof(num));
        for(int i=0;i<18;i++){
            printf("%d\n",prime[i]);
            fflush(stdout);
            char c[5];
            scanf("%s",c);
            if(c[0]=='y')
                num[i]=1,nn++;

        }
        if(nn>1)
            ok=0;
        else{
            for(int i=0;i<4;i++)
            if(num[i]){
                printf("%d\n",prime[i]*prime[i]);
                fflush(stdout);
                char c[5];
                scanf("%s",c);
                if(c[0]=='y')
                    ok=0;
                break;
            }
        }
        if(ok)
            printf("prime\n");
        else
            printf("composite\n");
            fflush(stdout);
   // }
}