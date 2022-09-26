#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cstdlib>
using namespace std;
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
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
int n;
inline int Ask(int x){
	printf("? %d\n",x);
	fflush(stdout);
	return read();
}
void Output(int x){
	printf("! %d\n",x);
	fflush(stdout);
	exit(0);
}
int main(){
	n=read();
	if(n&2){
		Output(-1);
	}
	int A=Ask(1),B=Ask(1+(n>>1)),l=1,r=(n>>1)+1;
	if(A==B){
		Output(1);
	}
	bool t=(A<B);
	while(l<=r){
		int mid=(l+r)>>1;
		int p=Ask(mid),q=Ask(mid+(n>>1));
		int d=(p<q);
		if(p==q){
			Output(mid);
		}
		if(d==t){
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	return 0;
}