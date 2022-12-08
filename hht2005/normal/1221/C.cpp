#include<bits/stdc++.h>
using namespace std;
int main() {
    int T,a,b,c;
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d%d",&a,&b,&c);
        printf("%d\n",min(min(a,b),(a+b+c)/3));
    }
    return 0;
}