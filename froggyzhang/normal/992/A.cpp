#include<iostream>
#include<cstdio>
#include<set>
#include<cstring>
using namespace std;
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
int n;
set<int> s;
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		int x=read();
		if(!x)continue;
		s.insert(x);
	}
	printf("%d\n",(int)s.size());
	return 0;
}