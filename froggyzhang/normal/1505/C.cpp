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
int n;
char s[233];
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=3;i<=n;++i){
		int x=s[i-2]-'A',y=s[i-1]-'A',z=s[i]-'A';
		if((x+y)%26!=z){
			return !printf("NO\n");
		}
	}
	printf("YES\n");
	return 0;
}