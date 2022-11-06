#include<bits/stdc++.h>
using namespace std;
inline int rd() {
	int x=0,c=0,f=1;
	for(; c<'0'||c>'9'; c=getchar())f=c!='-';
	for(; c>='0'&&c<='9'; c=getchar())x=x*10+c-'0';
	return f?x:-x;
}
char s[1231];
int main(){
	int n=rd();
	scanf("%s",s+1);
	int T=0;
	for(int i=1;i<=n;i++){
		T+=(s[i]=='S'&&s[i+1]=='F');
		T-=(s[i+1]=='S'&&s[i]=='F');
	}
	puts(T>0?"YES":"NO");
}