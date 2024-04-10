#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
#define N 200020
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
int n,a[N],p[N],l,r;
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
		p[a[i]]=i;
	}
	l=r=p[n];
	for(int i=n-1;i>=1;--i){
		if(l>1&&a[l-1]==i)--l;
		else if(r<n&&a[r+1]==i)++r;
		else return !printf("NO\n");
	}
	printf("YES\n");
	return 0;
}