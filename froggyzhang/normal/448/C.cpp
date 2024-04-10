#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 5050
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
int Get(int l,int r){
	int mn=1e9;
	for(int i=l;i<=r;i++){
		mn=min(mn,a[i]);
	}
	return mn;
}
inline int Solve(int l,int r,int h){
	if(l>r)return 0;
	if(l==r){
		if(a[l]==h)return 0;
		return 1;
	}
	int mn=Get(l,r);
	int ans=mn-h;
	int pos=l;
	for(int i=l;i<=r;i++){
		if(a[i]==mn){
			ans+=Solve(pos,i-1,mn);
			pos=i+1;
		}
	}
	ans+=Solve(pos,r,mn);
	return min(ans,r-l+1);
}
int main(){
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	printf("%d\n",Solve(1,n,0));
	return 0;
}