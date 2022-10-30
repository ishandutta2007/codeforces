#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
char str[2001];
int parin[2000][2000];
int L[2000];
int R[2000];
int len;
int solve(int a,int b){
    if(~parin[a][b])return parin[a][b];
    if(a==b)return parin[a][b]=1;
    if(a+1==b&&str[a]==str[b])return parin[a][b]=1;
    if(a+1==b&&str[a]!=str[b])return parin[a][b]=0;
    int m=solve(a+1,b-1);
    if(str[a]!=str[b]||m==0)return parin[a][b]=0;
    else return parin[a][b]=1;
}
int main(){
    scanf("%s",str);
    int len=strlen(str);
    for(int i=0;i<len;i++)
        for(int j=0;j<len;j++)
            parin[i][j]=-1;
    for(int i=0;i<len;i++){
        for(int j=i;j<len;j++)
            solve(i,j);
    }
    for(int i=0;i<len;i++){
        for(int j=i;j<len;j++){
            L[j]+=parin[i][j];
        }
    }
    for(int i=0;i<len;i++){
        for(int j=i;j<len;j++){
            R[i]+=parin[i][j];
        }
    }
    long long ret=0;
    for(int i=0;i<len;i++){
        for(int j=i+1;j<len;j++){
            ret+=(long long)L[i]*(long long)R[j];
        }
    }
    printf("%I64d\n",ret);
}