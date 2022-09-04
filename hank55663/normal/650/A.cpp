#include<stdio.h>
#include<cstring>
#include<algorithm>
using namespace std;
struct dot{
    int x,y;
};
bool cmp(const dot &a,const dot &b){
    return a.x<b.x;}
bool cmp2(const dot&a,const dot &b){
    return a.y<b.y;
}
bool cmp3(const dot&a,const dot &b){
    if(a.x!=b.x)
        return a.x<b.x;
    else
        return a.y<b.y;
}
main(){
   int n;
   scanf("%d",&n);
   dot d[200005];
   for(int i=0;i<n;i++)
    scanf("%d %d",&d[i].x,&d[i].y);
    sort(d,d+n,cmp);
    long long int ans=0;
    long long int sum=1;
    for(int i=1;i<n;i++){
        if(d[i].x==d[i-1].x)
        sum++;
        else{
            ans+=sum*(sum-1)/2;
            sum=1;
        }
    }
    ans+=sum*(sum-1)/2;
    sort(d,d+n,cmp2);
    sum=1;
    for(int i=1;i<n;i++){
        if(d[i].y==d[i-1].y)
        sum++;
        else{
            ans+=sum*(sum-1)/2;
            sum=1;
        }
    }
    ans+=sum*(sum-1)/2;
    sort(d,d+n,cmp3);
    sum=1;
    for(int i=1;i<n;i++){
        if(d[i].y==d[i-1].y&&d[i].x==d[i-1].x)
        sum++;
        else{
            ans-=sum*(sum-1)/2;
            sum=1;
        }
    }
    ans-=sum*(sum-1)/2;
    printf("%I64d\n",ans);
}