#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;
bool p[2800000];
int arr[2800000];
vector<int> primes;
void init(){
    ///p[i] is true if i is prime
    memset(p,true,sizeof(p));
    p[0]=p[1]=false;
    int k;
    for (int x=0;x<1675;x++){
        if (!p[x]) continue;
        k=x*x;
        while (k<2800000){
            p[k]=false;
            k+=x;
        }
    }
    primes.push_back(-1); ///1-indexing is pretty gay
    for (int x=0;x<2800000;x++) if (p[x]) primes.push_back(x);
}
int gd(int i){
    int k=2;
    while (i%k) k++;
    return i/k;
}
int main(){
    init();
    int n,t;
    scanf("%d",&n);
    for (int x=0;x<(n<<1);x++){
        scanf("%d",&t);
        arr[t]++;
    }
    for (int x=200005;x>=0;x--){
        if (arr[x] && !p[x]){
            for (int y=0;y<arr[x];y++) printf("%d ",x);
            arr[gd(x)]-=arr[x];
            arr[x]=0;
            //printf("%d %d\n",x,gd(x));
        }
    }
    for (int x=0;x<2800000;x++){
        if (arr[x]){
            for (int y=0;y<arr[x];y++) printf("%d ",x);
            arr[primes[x]]-=arr[x];
            arr[x]=0;
            //rintf("%d %d\n",x,primes[x]);
        }
    }
}