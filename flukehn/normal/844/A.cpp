#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),i##_end=(b);i<=i##_end;i++)
#define per(i,b,a) for(int i=(b),i##_st=(a);i>=i##_st;i--)
inline int rd() {
	int x=0,c=0,f=1;
	for(; c<'0'||c>'9'; c=getchar())f=c!='-';
	for(; c>='0'&&c<='9'; c=getchar())x=x*10+c-'0';
	return f?x:-x;
}
char s[1111];
int tot[30];
int main(){
	scanf("%s",s+1);
	int n=strlen(s+1),K=rd();
	if(n<K){
		puts("impossible");
		return 0;
	}
	rep(i,1,n){
		tot[s[i]-'a']++;
	}
	int heihei=0;
	rep(i,0,25){
		heihei+=tot[i]!=0;
	}
	printf("%d\n",max(0,K-heihei));
}