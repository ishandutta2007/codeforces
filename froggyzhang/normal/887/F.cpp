#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define yes !printf("YES\n")
#define N 500050
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
int n,m,a[N],p[N],k;
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	p[k=1]=1;
	for(int i=2;i<=n;++i){
		if(a[i]<a[p[k]]){
			p[++k]=i;
		}
	}
	p[++k]=n+1;
	int pos=-1;
	for(int i=1;i<=n;++i){
		if(p[i+1]-p[i]>m){
			if(~pos)return !printf("NO\n");
			pos=i;
		}
	}
	if(!~pos)return yes;
	if(pos^(k-1)&&p[pos+2]-p[pos]<=2*m)return yes;
	for(int i=p[pos+1]+1;i<=n;++i){
		if(a[i]>a[p[pos+1]]&&a[i]<a[p[pos]]&&p[pos+1]-p[pos]<=2*m)return yes;
	}
	printf("NO\n");
	return 0;
}