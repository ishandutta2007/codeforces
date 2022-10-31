#include<stdio.h>
#include<algorithm>
using namespace std;
int d[110000];
pair<int,int> e[110000];
int ans[110000];
int main(){
    int a,b,c;scanf("%d%d%d",&a,&b,&c);
    for(int i=0;i<a;i++)scanf("%d",d+i);
    if(b==c){
        for(int i=0;i<b;i++)ans[i]=1;
        for(int i=b;i<a;i++)ans[i]=2;
    }else if(b>c){
        for(int i=0;i<a;i++)e[i]=make_pair(d[i],i);
        std::sort(e,e+a);
        for(int i=0;i<a;i++)ans[i]=2;
        for(int i=0;i<b;i++)ans[e[i].second]=1;
    }else{
        for(int i=0;i<a;i++)e[i]=make_pair(d[i],-i);
        std::sort(e,e+a);
        for(int i=0;i<a;i++)ans[i]=1;
        for(int i=0;i<c;i++)ans[-e[i].second]=2;
    }
    for(int i=0;i<a;i++){
        if(i)printf(" ");
        printf("%d",ans[i]);
    }
    printf("\n");
}