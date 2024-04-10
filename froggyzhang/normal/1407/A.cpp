#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
#define N 2333
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
int T,n,a[N];
vector<int> ans;
int main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;++i){
			a[i]=read();
		}
		a[n+1]=0;
		ans.clear();
		for(int i=1;i<=n;++i){
			if(!a[i]){
				ans.push_back(0);
				continue;
			}
			if(a[i]&&a[i+1]){
				ans.push_back(1);
				ans.push_back(1);
				++i;
				continue;
			}
		}
		printf("%d\n",(int)ans.size());
		for(auto x:ans){
			printf("%d ",x);
		}
		printf("\n");
	}
	return 0;
}