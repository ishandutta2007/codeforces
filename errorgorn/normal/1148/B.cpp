#include <cstdio>
#include <vector>
using namespace std;
long long n,m,t1,t2,k;
vector<long long> v1,v2;

int main(){
    scanf("%lld%lld%lld%lld%lld",&n,&m,&t1,&t2,&k);
    if (n<=k || m<=k){
        printf("-1\n");
        return 0;
    }
    long long t;
    for (int x=0;x<n;x++){
        scanf("%lld",&t);
        v1.push_back(t);
    }
    for (int x=0;x<m;x++){
        scanf("%lld",&t);
        v2.push_back(t);
    }
    long long ans=0;
    long long iter=0;
    for (int x=0;x<=k;x++){
        while (iter<m && v2[iter]<v1[x]+t1) iter++;
        if (iter+k-x>=m){
            printf("-1\n");
            return 0;
        }
        else{
            ans=max(ans,v2[iter+k-x]);
        }
    }
    printf("%lld\n",ans+t2);
}