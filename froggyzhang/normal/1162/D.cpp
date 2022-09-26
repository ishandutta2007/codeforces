#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
#define N 200010
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
int n,m,ans;
pair<int,int> a[N],b[N];
bool check(int p){
	if(p==n)return false;
	for(int i=1;i<=m;++i){
		int x=(a[i].first+p-1)%n+1;
		int y=(a[i].second+p-1)%n+1;
		if(x>y)swap(x,y);
		b[i]=make_pair(x,y);
	}
	sort(b+1,b+m+1);
	for(int i=1;i<=m;++i){
		if(a[i]!=b[i])return false;
	}
	return true;
}	
int main(){
	n=read(),m=read();
	for(int i=1;i<=m;++i){
		int x=read(),y=read();
		if(x>y)swap(x,y);
		a[i]=make_pair(x,y);
	}
	sort(a+1,a+m+1); 
	for(int i=1;i*i<=n;++i){
		if(n%i==0){
			if(check(i)||check(n/i))return !printf("Yes\n");
		}
	}
	printf("No\n");
	return 0;
}