#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 233
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
int n,a[N],ans;
int main(){
	n=read();
	for(int i=1;i<=n<<1;++i){
		a[i]=read();
	}
	for(int i=1;i<=n;++i){
		int j=2;
		for(;;++j){
			if(a[j]^a[1])++ans;
			else break;
		}
		int p=0;
		for(int k=2;k<=(n<<1)-2*(i-1);++k){
			if(k==j)continue;
			a[++p]=a[k];
		}
	}
	printf("%d\n",ans);
	return 0;
}