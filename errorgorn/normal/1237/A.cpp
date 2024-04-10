#include <cstdio>
using namespace std;
int n;
int k;
bool flag;
int main(){
    scanf("%d",&n);
    while (n--){
        scanf("%d",&k);
        if (k%2==0){
            printf("%d\n",k/2);
            continue;
        }
        if (!flag){
            if (k>0) printf("%d\n",k/2);
            else printf("%d\n",k/2-1);
        }
        else{
            if (k>0) printf("%d\n",k/2+1);
            else printf("%d\n",k/2);
        }
        flag^=true;
    }
}