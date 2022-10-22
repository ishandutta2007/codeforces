#include <stdio.h>
#include <algorithm>
#include <map>

using namespace std;

long long a[300005];
long long sum[300005];
map<int, int> first;

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0; i < n; ++i)
        scanf("%I64d", a+i);
    sum[0]=0;
    long long ans=-2000000005;
    int ansS, ansE;
    for(int i=0; i < n; ++i){
        sum[i+1]=sum[i]+(a[i]<0?0:a[i]);
        if(first[a[i]]){
            long long newAns=2*a[i]+sum[i]-sum[first[a[i]]];
            if(newAns > ans){
                ans=newAns;
                ansS=first[a[i]]-1;
                ansE=i+1;
            }
        }
        else
            first[a[i]]=i+1;
    }
    int k=0;
    for(int i=0; i < n; ++i){
        if(!(i == ansS || i == ansE-1 || (a[i] > 0 && i > ansS && i < ansE)))
            ++k;
    }
    printf("%I64d %d\n", ans, k);
    for(int i=0; i < n; ++i){
        if(!(i == ansS || i == ansE-1 || (a[i] > 0 && i > ansS && i < ansE)))
            printf("%d ", i+1);
    }
    return 0;
}