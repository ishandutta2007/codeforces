#include<bits/stdc++.h>
using namespace std;
#define N 100010
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
int n,p[N],a[N],b[N],mxa,mxb,ans;
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		p[i]=read();
	}
	for(int i=1;i<=n;++i){
		if(i==1||p[i]<p[i-1])a[i]=1;
		else a[i]=a[i-1]+1;
		mxa=max(mxa,a[i]);
	}
	int ca=0;
	for(int i=1;i<=n;++i)ca+=mxa==a[i];
	for(int i=n;i>=1;--i){
		if(i==n||p[i]<p[i+1])b[i]=1;
		else b[i]=b[i+1]+1;
		mxb=max(mxb,b[i]);
	}
	int cb=0;
	for(int i=1;i<=n;++i)cb+=mxb==b[i];
	for(int i=2;i<n;++i){
		if(p[i]>p[i-1]&&p[i]>p[i+1]){
			if(a[i]==b[i]&&a[i]&1&&ca==1&&cb==1&&mxa==a[i]&&mxb==b[i]){
				return !printf("1\n");
			}
		}
	}
	printf("0\n");
	return 0;
}