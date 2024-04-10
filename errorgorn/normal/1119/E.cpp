#include <cstdio>
#include <algorithm>
using namespace std;
int n;
long long ans;
int one;
int main(){
    scanf("%d",&n);
    int t;
    long long match;
    for (int x=0;x<n;x++){
        scanf("%d",&t);
        match=min(one,t/2);
        ans+=match;
        one-=match;
        t-=match*2;
        ans+=t/3;
        one+=t%3;
    }
    printf("%lld\n",ans);
}