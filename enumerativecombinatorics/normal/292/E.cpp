#include<stdio.h>
#include<algorithm>
using namespace std;
int A[100000];
int B[100000];
int segtree[262144];
int QB[100000];
int QC[100000];
void query(int a,int b,int c,int d,int e,int f){
	if(d<a||b<c)return;
	if(c<=a&&b<=d){
		segtree[e]=f;
		return ;
	}
	query(a,(a+b)/2,c,d,e*2,f);
	query((a+b)/2+1,b,c,d,e*2+1,f);
}
int get(int a){
	int ret=-1;
	a+=131072;
	while(a){
		ret=max(ret,segtree[a]);
		a/=2;
	}
	return ret;
}
int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=0;i<a;i++)scanf("%d",A+i);
	for(int i=0;i<a;i++)scanf("%d",B+i);
	for(int i=0;i<262144;i++)segtree[i]=-1;
	for(int i=0;i<b;i++){
		int c;
		scanf("%d",&c);
		if(c==1){
			int d,e,f;
			scanf("%d%d%d",&e,&f,&d);
			e--;
			f--;
			QB[i]=e;
			QC[i]=f;
			query(0,131071,f,f+d-1,1,i);
		}else{
			int d;
			scanf("%d",&d);
			d--;
			int v=get(d);
			if(~v)printf("%d\n",A[QB[v]+d-QC[v]]);
			else printf("%d\n",B[d]);
		}
	}
}