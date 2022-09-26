#include<iostream>
#include<cstdio>
#include<stack>
#include<cstring>
using namespace std;
#define N 200020
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
int T,n,ans[N];
char s[N];
void Solve(){
	n=read();
	scanf("%s",s+1);
	stack<int> st[2];
	int tot=0;
	for(int i=1;i<=n;++i){
		int c=s[i]-'0';
		if(st[c^1].empty()){
			ans[i]=++tot;
			st[c].push(tot);
		}
		else{
			ans[i]=st[c^1].top();
			st[c^1].pop();
			st[c].push(ans[i]); 
		}
	}
	printf("%d\n",tot);
	for(int i=1;i<=n;++i){
		printf("%d ",ans[i]);
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