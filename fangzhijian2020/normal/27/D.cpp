#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,i,j,x[505],y[505],p,h[16005],Time,top[16005],DFN[16005],Low[16005],in[16005],BCC,Belong[16005],cnt=0,nx,ny,opp[16005],vst[16005];
struct point{
	int x;
	int y1,y2;
}t[8005];
struct node{
	int to,next;
}a[10000005];
long long pf(long long x){
	return x*x;
}
void Add(int x,int y){
	++cnt;a[cnt].to=y;a[cnt].next=h[x];h[x]=cnt;
}
int min(int x,int y){
	return x>y?y:x;
}
void tarjan(int x){
	int i,y;
	++Time;
	DFN[x]=Time;Low[x]=Time;top[++top[0]]=x;in[x]=1;
	for(i=h[x];i;i=a[i].next){
		y=a[i].to;
		if(!DFN[y]){
			tarjan(y);
			Low[x]=min(Low[x],Low[y]);
		}
		else if(in[y]){
			Low[x]=min(Low[x],DFN[y]);
		}
	}
	if(DFN[x]==Low[x]){
		++BCC;
		do{
			y=top[top[0]];
			--top[0];in[y]=0;
			Belong[y]=BCC;
		}while(y!=x);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++){
		scanf("%d%d",&x[i],&y[i]);	
		if(x[i]>y[i])swap(x[i],y[i]);	
	}
	for(i=1;i<m;i++){
		for(j=i+1;j<=m;j++){
			if((x[i]<x[j]&&x[j]<y[i]&&y[i]<y[j])||(x[j]<x[i]&&x[i]<y[j]&&y[j]<y[i])){
				Add(2*i-1,2*j);
				Add(2*i,2*j-1);
				Add(2*j,2*i-1);
				Add(2*j-1,2*i);
			}
		}
	}
	for(i=1;i<=m<<1;++i){
		if(!DFN[i])tarjan(i);
	}
	for(i=1;i<=m;++i){
		if(Belong[2*i-1]==Belong[2*i]){
			printf("Impossible\n");
			return 0;
		}
	}
	for(i=1;i<=m<<1;i++){
		if(i%2==1)p=i+1;
		else p=i-1;
		opp[Belong[i]]=Belong[p];
	}
	for(i=1;i<=BCC;i++){
		if(!vst[i]){
			vst[opp[i]]=1;
		}
	}
	for(i=1;i<=2*m;i++){
		if(!vst[Belong[i]]){
			if(i%2==1)putchar('i');
			else putchar('o');
		}
	}
	return 0;
}