#include <cstdio>
using namespace std;
int tc;
long long n,_n,k,ans;
int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d",&tc);
    while (tc--){
        scanf("%lld%lld",&n,&k);
        ans=0;
        while (n!=0){
            if (n%k==0){
                n/=k;
                ans++;
            }
            else{
                _n=n/k*k;
                ans+=n-_n;
                n=_n;
            }
        }
        printf("%lld\n",ans);
    }
}