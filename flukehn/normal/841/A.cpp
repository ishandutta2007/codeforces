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
char s[1561];
int a[56];
int main(){
	int n=rd(),k=rd();
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
		a[s[i]-'a']++;
	for(int i=0;i<26;i++){
		if(a[i]>k){
			puts("NO");
			return 0;
		}
	}
	puts("YES");
}