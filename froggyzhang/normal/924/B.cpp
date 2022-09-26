#include<iostream>
#include<cstdio>
#include<cstring>
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
int n,U,a[N];
int main(){
	n=read(),U=read();
	double ans=-1;
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	for(int l=1,r=1;l<n;++l){
		while(r<n&&a[r+1]-a[l]<=U)++r;
		if(r>l+1)ans=max(ans,1.0*(a[r]-a[l+1])/(a[r]-a[l]));
	}
	if(ans<0){
		printf("-1\n");
	}
	else{
		printf("%.12lf\n",ans);
	}
	return 0;
}