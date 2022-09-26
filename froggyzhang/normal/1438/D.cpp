#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<tuple>
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
int n,a[N],x;
vector<tuple<int,int,int> > ans;
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
		x^=a[i];
	}
	if(n%2==0&&x!=0){
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	for(int i=1;i<=n-2;i+=2){
		ans.emplace_back(i,i+1,i+2);
	}
	if(n%2==0)ans.emplace_back(1,n-1,n);
	if(n&1){
		for(int i=n-2;i>=3;i-=2){
			ans.emplace_back(i-2,i-1,i);
		}
	}
	else{
		for(int i=3;i<n;i+=2){
			ans.emplace_back(1,i,i+1);
		}
	}
	printf("%d\n",(int)ans.size());
	for(auto [x,y,z]:ans){
		printf("%d %d %d\n",x,y,z);
	}
	return 0;
}