#include <cstdio>
#include <algorithm>
using namespace std;
int n;
int k;
long long pos,neg;
long long tp,tn;
int main(){
    scanf("%d",&n);
    while (n--){
        scanf("%d",&k);
        if (k<0){
            swap(pos,neg);
            neg++;
        }
        else{
            pos++;
        }
        tp+=pos;
        tn+=neg;
    }
    printf("%lld %lld\n",tn,tp);
}