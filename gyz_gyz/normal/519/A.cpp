#include<cstdio>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
using namespace std;
char c[8];int p;
int main(){
    rep(i,1,8){
        scanf("%s",c);
        rep(j,0,7){
            if(c[j]=='Q')p+=9;
            if(c[j]=='R')p+=5;
            if(c[j]=='B')p+=3;
            if(c[j]=='N')p+=3;
            if(c[j]=='P')p++;
            if(c[j]=='q')p-=9;
            if(c[j]=='r')p-=5;
            if(c[j]=='b')p-=3;
            if(c[j]=='n')p-=3;
            if(c[j]=='p')p--;
        }
    }
    if(p>0)printf("White\n");
    if(p<0)printf("Black\n");
    if(p==0)printf("Draw\n");
}