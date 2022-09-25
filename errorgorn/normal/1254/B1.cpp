#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
int n;
int arr[100005];
vector<int> v;
int k;
const long long INF=1000000000000000000;
long long test(int i){
    long long ans=0;
    for (int x=0;x<k;x+=i){
        for (int y=0;y<i;y++){
            ans+=abs(v[x+y]-v[x+(i>>1)]);
        }
    }

    return ans;
}
int main(){
    scanf("%d",&n);
    for (int x=0;x<n;x++) scanf("%d",&arr[x]);

    long long choc=0;
    for (int x=0;x<n;x++) choc+=arr[x];
    for (int x=0;x<n;x++) if (arr[x]) v.push_back(x);

    long long ans=INF;
    k=choc;
    for (int x=2;x<100005;x++){
        if (choc%x==0){
            ans=min(ans,test(x));
            while (choc%x==0) choc/=x;
        }
    }

    printf("%lld\n",(ans==INF)?-1:ans);
}