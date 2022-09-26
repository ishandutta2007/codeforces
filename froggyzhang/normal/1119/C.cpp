#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define N 505
inline int read(){
	int f=1,x=0;
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
int n,m,a[N][N],b[N][N];
int main(){
	n=read();m=read();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			a[i][j]=read();
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			b[i][j]=read();
		}
	}
	for(int i=1;i<=n;i++){
		int a1=0,b1=0;
		for(int j=1;j<=m;j++){
			a1^=a[i][j];
			b1^=b[i][j];
		}
		if(a1!=b1){
			cout<<"No"<<endl;
			return 0;
		}
	}
	for(int j=1;j<=m;j++){
		int a1=0,b1=0;
		for(int i=1;i<=n;i++){
			a1^=a[i][j];
			b1^=b[i][j];
		}
		if(a1!=b1){
			cout<<"No"<<endl;
			return 0;
		}
	}
	cout<<"Yes"<<endl;
	return 0;
}