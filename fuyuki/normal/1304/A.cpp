#include<cstdio>
#include<iostream>
using namespace std;
int main(){
    int T,x,y,a,b;
    for(scanf("%d", &T);T--;){
        scanf("%d%d%d%d",&x,&y,&a,&b);
        if ((y-x)%(a+b))cout<<"-1\n";
        else cout<<(y-x)/(a+b)<<'\n';
    }
    return 0;
}