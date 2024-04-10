#include<stdio.h>
#include<cstring>
#include<algorithm>
using namespace std;
struct thing{
 int l,r;
};
bool operator<(const thing &a,const thing &b){
    return a.l<b.l;
}
main(){
    int n;
    thing order[500010];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d %d",&order[i].l,&order[i].r);
    sort(order,order+n);
    int t=order[0].r;
    int sum=1;
    for(int i=1;i<n;i++){
        if(order[i].l>t){
            sum++;
            t=order[i].r;
        }
        else{
            t=min(t,order[i].r);
        }
    }
    printf("%d",sum);
}