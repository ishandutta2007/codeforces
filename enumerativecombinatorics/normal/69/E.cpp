#include<stdio.h>
#include<algorithm>
using namespace std;
int t[100000];
int k[100000];
int zahyou[100000];
int co[100000];
int SEGTREE[262144];
void query(int at,int val){
    if(val==1)SEGTREE[at+131072]=at;
    else SEGTREE[at+131072]=-1;
    at+=131072;
    at/=2;
    while(at>0){
        SEGTREE[at]=max(SEGTREE[2*at],SEGTREE[2*at+1]);
        at/=2;
    }
    return;
}
int find(int begin,int end,int a,int b,int t){
    if(begin<=a&&b<=end)return SEGTREE[t];
    else if(begin>b||end<a)return -1;
    else return max(find(begin,end,a,(a+b)/2,t*2),find(begin,end,(a+b)/2+1,b,t*2+1));
}
int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    for(int i=0;i<a;i++){
        scanf("%d",t+i);
        k[i]=t[i];
    }
    std::sort(k,k+a);
    for(int i=0;i<262144;i++)SEGTREE[i]=-1;
    for(int i=0;i<a;i++){
        zahyou[i]=lower_bound(k,k+a,t[i])-k;
    }
    for(int i=0;i<b;i++){
        co[zahyou[i]]++;
    }
    for(int i=0;i<b;i++){
        if(co[zahyou[i]]==1){
            query(zahyou[i],1);
        }
    }
    if(SEGTREE[1]!=-1)
        printf("%d\n",k[SEGTREE[1]]);
        else printf("Nothing\n");
    for(int i=1;i<a-b+1;i++){
        co[zahyou[i-1]]--;
        co[zahyou[i+b-1]]++;
        if(co[zahyou[i-1]]==1)query(zahyou[i-1],1);
        else query(zahyou[i-1],-1);
        if(co[zahyou[i+b-1]]==1)query(zahyou[i+b-1],1);
        else query(zahyou[i+b-1],-1);
        //for(int j=131072;j<131072+a;j++)printf("%d ",SEGTREE[j]);
    if(SEGTREE[1]!=-1)
        printf("%d\n",k[SEGTREE[1]]);
        else printf("Nothing\n");
    }
}