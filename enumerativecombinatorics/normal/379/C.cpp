#include<stdio.h>
#include<algorithm>
using namespace std;
pair<int,int> d[1000000];
int out[1000000];
int main(){
    int a;
    scanf("%d",&a);
    for(int i=0;i<a;i++){
        int b;
        scanf("%d",&b);
        d[i]=make_pair(b,i);
    }
    std::sort(d,d+a);
    int now=0;
    for(int i=0;i<a;i++){
        out[d[i].second]=max(d[i].first,now+1);
        now=max(now+1,d[i].first);
    }
    for(int i=0;i<a;i++){
        if(i)printf(" ");
        printf("%d",out[i]);
    }
    printf("\n");
}