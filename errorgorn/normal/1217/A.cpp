#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
    int TC;
    scanf("%d\n",&TC);
    while (TC--){
        int a,b,c,_c;
        scanf("%d%d%d",&a,&b,&c);
        _c=c;
        c-=(b-a)-1;
        printf("%d\n",min(max(c/2,0),_c+1));
    }
}