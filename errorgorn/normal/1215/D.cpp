#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int n;
int v,q;
int main(){
    scanf("%d",&n);
    getchar();
    n>>=1;
    char ch;
    for (int x=0;x<n;x++){
        ch=getchar();
        if (ch=='?') q++;
        else v+=ch-'0';
    }
    for (int x=0;x<n;x++){
        ch=getchar();
        if (ch=='?') q--;
        else v-=ch-'0';
    }
    printf((q/2)*9+v==0?"Bicarp":"Monocarp");
}