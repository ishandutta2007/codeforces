#include<stdio.h>
#include<cstring>
#include<algorithm>
using namespace std;
long long int d[50][50][60];
long long int dp(int x,int y,int a){
    if(d[x][y][a]!=0)
    return d[x][y][a];
    if(x*y<=a||a==0)
    return 0;
    long long int ans=1e12;
    for(int i=1;i<x;i++){
    if(i*y<=a)
    ans=min(dp(x-i,y,a-i*y)+y*y,ans);
    else{
        ans=min(dp(i,y,a)+y*y,ans);
        }
    }
    for(int i=1;i<y;i++){
        if(i*x<=a)
        ans=min(dp(x,y-i,a-x*i)+x*x,ans);
        else{
        ans=min(dp(x,i,a)+x*x,ans);
        }
    }
    return d[x][y][a]=ans;
} 
main(){
 int t;
 memset(d,0,sizeof(d));
 for(int n=1;n<=30;n++)
 for(int m=1;m<=30;m++)
 for(int k=1;k<=min(n*m,50);k++)
 dp(n,m,k);
 scanf("%d",&t);
  while(t--){
    
    int x,y,a;
    scanf("%d %d %d",&x,&y,&a);
    printf("%I64d\n",d[x][y][a]);
    } 
}