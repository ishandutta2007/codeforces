#include<stdio.h>
#include<algorithm>
using namespace std;
int p[100000];
int q[100000];
pair<int,int>  ans[100000];
int main(){
    int a,b,c,d;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    for(int i=0;i<a;i++)scanf("%d",p+i);
    for(int i=0;i<b;i++)scanf("%d",q+i);
    int now=0;
    int ret=0;
    for(int i=0;i<a;i++){
        while(now<b&&q[now]<p[i]-c){
            now++;
        }
        if(now<b&&q[now]<=p[i]+d){
            ans[ret++]=make_pair(i,now);
            now++;
            
        }
    }
    printf("%d\n",ret);
    for(int i=0;i<ret;i++)printf("%d %d\n",ans[i].first+1,ans[i].second+1);
}