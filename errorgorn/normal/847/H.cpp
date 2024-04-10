#include <cstdio>
#include <algorithm>
using namespace std;
int n;
int arr[100005];
long long test(int i){
    long long ans=0;
    int fc=-1;
    for (int x=1;x<i;x++){
        if (fc>=arr[x]){
            fc++;
            ans+=fc-arr[x];
        }
        else{
            fc=arr[x];
        }
    }
    int bc=-1;
    for (int x=n;x>i;x--){
        if (bc>=arr[x]){
            bc++;
            ans+=bc-arr[x];
        }
        else{
            bc=arr[x];
        }
    }

    return ans+max(max(fc,bc)+1-arr[i],0);
}
int main(){
    scanf("%d",&n);
    arr[0]=-1;
    arr[n+1]=-1;
    for (int x=1;x<=n;x++) scanf("%d",&arr[x]);

    int s=1,e=n;
    int t1,t2;
    long long v1,v2;
    while (e-s>3){
        t1=s+(e-s)/3;
        t2=s+(e-s)*2/3;
        v1=test(t1);
        v2=test(t2);
        if (v1<v2){
            e=t2;
        }
        else{
            s=t1;
        }
    }

    long long best=1000000000000000000;
    for (int x=s;x<=e;x++){
        best=min(best,test(x));
    }

    printf("%lld\n",best);

}