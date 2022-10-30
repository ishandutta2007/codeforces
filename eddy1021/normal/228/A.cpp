#include <stdio.h>
#include <set>
using namespace std;
int getint(){
    int x=0; char c=getchar();
    while( c<'0'||c>'9' ) c=getchar();
    while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
    return x;
}
int main(){
    int tmp; set<int> S;
    for( int i=0;i<4;i++ ){
        tmp=getint(); S.insert(tmp);
    }
    printf("%d\n",4-S.size());
    return 0;
}