#include<cstdio>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
using namespace std;
char p[15];int n,a,b,c,d;
int main(){
    scanf("%d",&n);
    scanf("%s",p);
    rep(i,0,n-1){
        if(p[i]>'1')a++;
        if(p[i]>'2')b++;
        if(p[i]>'3')a+=2;
        if(p[i]>'4')c++;
        if(p[i]>'5')a++,b++;
        if(p[i]>'6')d++;
        if(p[i]>'7')a+=3;
        if(p[i]>'8')b+=2;
    }
    for(;d;d--){
        printf("7");c--;b-=2;a-=4;
    }
    for(;c;c--){
        printf("5");b--;a-=3;
    }
    for(;b;b--){
        printf("3");a--;
    }
    for(;a;a--)printf("2");
}