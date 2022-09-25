#include <cstdio>
#include <algorithm>
using namespace std;
long long n,k,d1,d2;
int main(){
    int TC;
    scanf("%d",&TC);
    while (TC--){
        scanf("%lld%lld%lld%lld",&n,&k,&d1,&d2);
        n-=k;
        long long test,test2; //middle up
        test=n-d1-d2;
        test2=k-(max(d1,d2)*2-min(d1,d2));
        if (test>=0 && test%3==0 && test2>=0 && test2%3==0) {
            printf("yes\n");
            continue;
        }
        test=n-(max(d1,d2)*2-min(d1,d2)); //middle down
        test2=k-d1-d2;
        if (test>=0 && test%3==0 && test2>=0 && test2%3==0) {
            printf("yes\n");
            continue;
        }
        test=n-d1*2-d2; //ascend
        test2=k-d1-d2*2;
        if (test>=0 && test%3==0 && test2>=0 && test2%3==0) {
            printf("yes\n");
            continue;
        }
        test=n-d1-d2*2; //desend
        test2=k-d1*2-d2;
        if (test>=0 && test%3==0 && test2>=0 && test2%3==0) {
            printf("yes\n");
            continue;
        }
        printf("no\n");
    }
}