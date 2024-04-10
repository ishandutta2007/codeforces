#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
    int r,d,e;
    scanf("%d%d%d",&r,&d,&e);
    e*=5;
    int total=0;
    while (total<=r) total+=d;
    total-=d;
    int best=total;
    int temp=total/d;
    for (int x=0;x<temp;x++){
        total-=d;
        while (total<=r) total+=e;
        best=max(best,total-e);
    }
    printf("%d\n",r-best);
}