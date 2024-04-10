#include <cstdio>
using namespace std;
int n,a,b,x,y;
int main(){
    scanf("%d%d%d%d%d",&n,&a,&x,&b,&y);
    while (a!=x && b!=y){
        if (a==b){
            printf("YES\n");
            return 0;
        }
        a++;
        b--;
        if (a>n) a=1;
        if (b==0) b=n;
    }
    if (a==b){
        printf("YES\n");
        return 0;
    }
    printf("NO\n");
}