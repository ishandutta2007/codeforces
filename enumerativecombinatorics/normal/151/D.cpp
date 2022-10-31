#include<stdio.h>
#include<algorithm>
using namespace std;
int UF[3000];
int FIND(int a){
    if(UF[a]<0)return a;
    return UF[a]=FIND(UF[a]);
}
void UNION(int a,int b){
    a=FIND(a);b=FIND(b);
    if(a==b)return;
    UF[a]+=UF[b];
    UF[b]=a;
}
int main(){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    for(int i=0;i<a;i++)UF[i]=-1;
    for(int i=0;i<a-c+1;i++){
        for(int j=0;j<c;j++){
            UNION(i+j,i+c-1-j);
        }
    }
    int dim=0;
    for(int i=0;i<a;i++)if(UF[i]<0)dim++;
    long long ret=1;
    int mod=1000000007;
    for(int i=0;i<dim;i++){
        ret=ret*b%mod;
    }
    printf("%I64d\n",ret);
}