#include <cstdio>
#include <algorithm>
using namespace std;
int n;
int main(){
    scanf("%d",&n);
    while (n--){
        int a,b;
        scanf("%d%d",&a,&b);
        if ((a+b)%3!=0){
            printf("NO\n");
            continue;
        }
        if (a>b) swap(a,b);
        if (b-a>a){
            printf("NO\n");
            continue;
        }
        
        printf("YES\n");
    }
}