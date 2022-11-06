#include<bits/stdc++.h>
using namespace std;
long long a[]={	1, 3, 40, 1260, 72576, 6652800, 889574400, 163459296000ll, 39520825344000ll, 12164510040883200ll};
int main(){
    int n;
    scanf("%d",&n);
    printf("%lld",a[n/2-1]);
}