#include <cstdio>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    printf("%d\n",(n>>1)+1);
    int x=1,y=1;
    for (int _x=0;_x<n;_x++){
        printf("%d %d\n",x,y);
        if (x==y) x++;
        else y++;
    }
}