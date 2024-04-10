#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int segtree[3000000];
int sum[3000000];
char str[3000000];
int query(int a,int b,int c,int d,int e){
    if(d<a||b<c)return 999999999;
    if(c<=a&&b<=d)return segtree[e];
    return min(query(a,(a+b)/2,c,d,e*2),query((a+b)/2+1,b,c,d,e*2+1));
}
int main(){
    int a;
    scanf("%s%d",str,&a);
    for(int i=0;i<3000000;i++)segtree[i]=999999999;
    int n=strlen(str);
    for(int i=0;i<n;i++){
        sum[i+1]=sum[i];
        if(str[i]=='(')sum[i+1]++;
        else sum[i+1]--;
        segtree[1048576+i]=sum[i+1];
    }
    for(int i=1048575;i>=1;i--){
        segtree[i]=min(segtree[i*2],segtree[i*2+1]);
    }
    for(int i=0;i<a;i++){
        int b,c;
        scanf("%d%d",&b,&c);b--;c--;
        int m=query(0,1048575,b,c,1);
        m-=sum[b];
        int M=sum[c+1]-sum[b];
        int ret=c-b+1;
        if(m<0){ret+=m;M-=m;}
        if(M>0)ret-=M;
        printf("%d\n",ret);
    }
}