#include<bits/stdc++.h>
#define N 20005
using namespace std;
main(){
    int t[5];
    for(int i=0;i<5;i++)
        scanf("%d",&t[i]);
    sort(t,t+5);
    int sum=0;
    for(int i=0;i<5;i++)
        sum+=t[i];
    for(int i=4;i>=1;i--)
    if(t[i]==t[i-1]){
        sum-=t[i];
        sum-=t[i-1];
        if(i>=2&&t[i-2]==t[i-1])
        sum-=t[i-2];
        break;
    }
    if(t[0]==t[1]&&t[1]==t[2])
        sum=min(sum,t[3]+t[4]);
    printf("%d",sum);
}