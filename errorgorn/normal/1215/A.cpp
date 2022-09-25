#include <cstdio>
#include <algorithm>
using namespace std;
int a1,a2,k1,k2;
int n;
int main(){
    scanf("%d%d%d%d%d",&a1,&a2,&k1,&k2,&n);
    int mini=0,maxi=0;
    mini=max(n-(a1*k1+a2*k2)+a1+a2,0);
    if (k1>k2) swap(k1,k2),swap(a1,a2);
    if (n>=k1*a1){
        maxi=a1+(n-k1*a1)/k2;
    }
    else{
        maxi=n/k1;
    }
    printf("%d %d\n",mini,maxi);
}