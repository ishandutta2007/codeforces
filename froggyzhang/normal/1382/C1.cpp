#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
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
int T,n;
char a[N],b[N];
void Solve(){
	n=read();
	scanf("%s",a+1);
	scanf("%s",b+1);
	int l=1,r=n;
	bool t=false;
	vector<int> ans;
	for(int i=n;i>=1;--i){
		if((n-i)&1){
			if((a[r]==b[i])^t)ans.push_back(1);
			ans.push_back(i),t^=1;
			--r;
		}
		else{
			if((a[l]==b[i])^t)ans.push_back(1);
			ans.push_back(i),t^=1;
			++l;
		}
	}
	printf("%d ",(int)ans.size());
	for(auto x:ans){
		printf("%d ",x);
	}
	printf("\n");
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}