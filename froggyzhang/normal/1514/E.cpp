#include<bits/stdc++.h>
using namespace std;
#define N 233
int n,p[N];
inline int Ask1(int x,int y){
	printf("1 %d %d\n",x,y);
	fflush(stdout);
	scanf("%d",&x);
	assert(~x);
	return x;
}
inline int Ask2(int x,int t){
	printf("2 %d %d",x,n-t);
	for(int i=t;i<n;++i)printf(" %d",p[i]);
	printf("\n");
	fflush(stdout);
	scanf("%d",&x);
	assert(~x);
	return x;
}
void Solve(){
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		p[i]=i;
	}
	sort(p,p+n,[&](int i,int j){return Ask1(j,i);});
	static int g[N],num;
	num=0;
	for(int i=0,j=0,z=0;i<n;++i){
		while(j+1<n&&Ask2(p[i],j+1))++j;
		if(i==j){
			++num;
			for(int k=z;k<=j;++k)g[p[k]]=num;
			++j;
			z=j;
		}
	}
	printf("3\n");
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			putchar('0'+(g[i]>=g[j]));
		}
		putchar('\n');
	}
	fflush(stdout);
	int x;
	scanf("%d",&x);
	assert(x==1);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		Solve();
	}
	return 0;
}