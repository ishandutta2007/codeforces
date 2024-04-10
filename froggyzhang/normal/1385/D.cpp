#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 233333
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
int T,n;
char s[N];
int calc(int l,int r,char c){
	if(l==r)return s[l]!=c;
	int cntl=0,cntr=0;
	int mid=(l+r)>>1;
	for(int i=l;i<=mid;++i){
		cntl+=(s[i]!=c);
	}
	for(int i=mid+1;i<=r;++i){
		cntr+=(s[i]!=c);
	}
	return min(cntl+calc(mid+1,r,c+1),cntr+calc(l,mid,c+1));
}
int main(){
	T=read();
	while(T--){
		n=read();
		scanf("%s",s+1);
		printf("%d\n",calc(1,n,'a'));
	}
	return 0;
}