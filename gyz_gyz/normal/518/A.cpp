#include<cstdio>
#include<cstring>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define mx 100
using namespace std;
char c1[mx],c2[mx];int sz,i;
int main(){
    scanf("%s",c1);scanf("%s",c2);
    sz=strlen(c1);
    for(i=sz-1;c1[i]=='z';)i--;
    c1[i]++;rep(j,i+1,sz-1)c1[j]='a';
    rep(j,0,sz-1)if(c1[j]!=c2[j]){
        printf("%s\n",c1);
        return 0;
    }
    printf("No such string\n");
}