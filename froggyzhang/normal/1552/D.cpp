#include<bits/stdc++.h>
using namespace std;
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
int T,n,a[10],s[1<<10];
void Solve(){
	n=read();
	for(int i=0;i<n;++i)a[i]=read();
	for(int i=0;i<(1<<n);++i){
		s[i]=0;
		for(int j=0;j<n;++j){
			if(i>>j&1)s[i]+=a[j];	
		}
	}
	for(int i=0;i<(1<<n);++i){
		for(int j=i+1;j<(1<<n);++j){
			if(s[i]==s[j]){
				printf("YES\n");return;
			}
		}
	}
	printf("NO\n");
}
int main(){
	T=read();
	while(T--)Solve();
	return 0;
}