#include<iostream>
#include<cstdio>
#include<cstring>
#include<unordered_map>
using namespace std;
#define N 5005
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,a[N];
int Solve(int l,int r,int h){
	if(l>r)return 0;
	int mn=1e9+1,pos=-1;
	for(int i=l;i<=r;++i){
		if(a[i]-h<mn){
			mn=a[i]-h;
			pos=i;
		}
	}
	return min(r-l+1,Solve(l,pos-1,h+mn)+Solve(pos+1,r,h+mn)+mn);
}
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	printf("%d\n",Solve(1,n,0));
	return 0;
}