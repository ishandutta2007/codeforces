#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
using namespace std;
#define N 505
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
int T,n,a[N],b[N];
int main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;++i)a[i]=read();
		for(int i=1;i<=n;++i)b[i]=read();
		multiset<pair<int,int> > A,B;
		for(int i=1;i<=n;++i){
			A.insert(make_pair(a[i],a[n-i+1]));
			B.insert(make_pair(b[i],b[n-i+1]));
		}
		printf(A==B?"yes\n":"no\n");
	}
	return 0;
}