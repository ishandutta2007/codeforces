#include<cstdio>
using namespace std;
int n,s,i;long long k,a[50];
int main(){
    scanf("%d%I64d",&n,&k);k--;s=n-1;
    a[0]=a[1]=1;for(i=2;i<n;i++)a[i]=a[i-1]+a[i-2];
    while(s>=0){
        if(a[s]>k){printf("%d ",n-s);s--;}
        else{printf("%d %d ",n-s+1,n-s);k-=a[s];s-=2;}
    }
}