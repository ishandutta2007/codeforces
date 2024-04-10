#include<iostream>
#include<cstdio>
#include<vector>
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
int n,m,sx,sy;
vector<int> vec;
int main(){
	n=read(),m=read(),sx=read(),sy=read();
	for(int i=sy;i>=1;--i){
		printf("%d %d\n",sx,i);
	}
	for(int i=sy+1;i<=m;++i){
		printf("%d %d\n",sx,i);
	}
	for(int i=sx+1;i<=n;++i){
		vec.push_back(i);
	}
	for(int i=sx-1;i>=1;--i){
		vec.push_back(i);
	}
	int st=0;
	for(auto x:vec){
		st^=1;
		if(st){
			for(int i=m;i>=1;--i){
				printf("%d %d\n",x,i);
			}
		}
		else{
			for(int i=1;i<=m;++i){
				printf("%d %d\n",x,i);
			}
		}
	}
	return 0;
}