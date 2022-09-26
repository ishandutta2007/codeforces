#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 100010
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
int a[N],b[N],n,p[N],q[N];
int main(){
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	for(int i=1;i<=n;i++){
		b[i]=read();
	}
	if(a[1]!=b[1]||a[n]!=b[n]){
		cout<<"No"<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++){
		p[i]=a[i]-a[i-1];
		q[i]=b[i]-b[i-1];
	}
	sort(p+1,p+n+1),sort(q+1,q+n+1);
	for(int i=1;i<=n;i++){
		if(p[i]!=q[i]){
			cout<<"No"<<endl;
			return 0;
		}
	}
	cout<<"Yes"<<endl;
	return 0;
}