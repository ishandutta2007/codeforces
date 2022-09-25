#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
const long long INF=1000000000000000000;
int n;
int arr[1000005];
long long test(long long i){
    long long res=0;
    long long bn=0,fn=0;

    long long bb=((i-1)>>1);
    long long ff=(i>>1);
    //printf("stuff: %lld %lld %lld\n",i,bb,ff);
    long long curr;
    long long temp;
    long long center=-1;
    for (int x=0;x<n;x++){
        curr=arr[x];
        if (bn<bb && bn!=-1){
            temp=min(curr,bb-bn);
            bn+=temp;
            curr-=temp;
        }

        if (bn==bb && curr){
            curr--;
            bn=-1;
            center=x;
        }

        if (bn==-1){
            temp=min(curr,ff-fn);
            curr-=temp;
            fn+=temp;
            res+=(x-center)*temp;
        }

        if (fn==ff){
            curr%=i;
            bn=0;
            fn=0;
        }

        if (bn<bb){
            temp=min(curr,bb-bn);
            bn+=temp;
            curr-=temp;
        }

        if (bn==bb && curr){
            curr--;
            bn=-1;
            center=x;
        }

        if (bn==-1){
            temp=min(curr,ff-fn);
            curr-=temp;
            fn+=temp;
            res+=(x-center)*temp;
        }

        if (bn!=-1) res+=bn;

        //printf("%lld %lld %lld\n",res,bn,fn);
    }
    //printf("res: %lld\n",res);
    return res;
}
int main(){
    scanf("%d",&n);
    for (int x=0;x<n;x++) scanf("%d",&arr[x]);

    long long choc=0;
    for (int x=0;x<n;x++) choc+=arr[x];

    if (choc==1){
        printf("-1\n");
        return 0;
    }

    long long ans=INF;
    for (int x=2;x<=1000005;x++){
        if (choc%x==0){
            ans=min(ans,test(x));
            while (choc%x==0) choc/=x;
        }
    }

    //printf("%lld\n",choc);

    if (choc!=1) ans=min(ans,test(choc));

    printf("%lld\n",ans);
}