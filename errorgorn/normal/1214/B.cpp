#include <cstdio>
#include <algorithm>
using namespace std;
int a,b,c;
int main(){
    scanf("%d%d%d",&a,&b,&c);
    int d1=max(0,c-a),d2=max(0,c-b);
    c-=d1+d2;
    printf("%d\n",c+1);
}