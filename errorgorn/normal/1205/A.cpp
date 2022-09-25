#include <cstdio>
using namespace std;
int n;
int mod;
int arr[200005];
int main(){
    scanf("%d",&n);
    if (!(n&1)) printf("NO\n");
    else{
        mod=n<<1;
        int i=0;
        int k=1;
        while (i!=mod){
            arr[i]=k++;
            i=(i+n)%mod;
            arr[i]=k++;
            i++;
        }
        printf("YES\n");
        for (int x=0;x<mod;x++) printf("%d ",arr[x]);
    }
}