#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,mod=998244353;
typedef long long ll;
inline int read(){
	int s=0;char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s;
}
int c1,c2,c3;
int a1,a2,a3,a4,a5;
int main(){
	int t=read();
	while(t--){
		c1=read(),c2=read(),c3=read();
		a1=read(),a2=read(),a3=read(),a4=read(),a5=read();
		c1-=a1,c2-=a2,c3-=a3;
		if(c1<0||c2<0||c3<0){
			puts("NO");
			continue;
		} 
		a4-=min(a4,c1);a5-=min(a5,c2);
		if(c3>=a4+a5) puts("YES");
		else puts("NO");
	}
	return 0;
}