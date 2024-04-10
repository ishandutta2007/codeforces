#include<cstdio>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
using namespace std;
char c[30];
int main(){
    scanf("%s",c);
    rep(i,1,30)if(c[i]=='\0'){
        printf("%d\n",25*(i+1)+1);return 0;
    }
}