#include <cstdio>
#include <algorithm>
using namespace std;
int n,k;
char c;
int main(){
    c=getchar();
    while (c!='\n'){
        n++;
        if (c=='a') k++;
        c=getchar();
    }
    printf("%d\n",min((k<<1)-1,n));
}