#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
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
char s[233];
int n;
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	int cnt=0;
	for(int i=1;i<=n;++i){
		if(s[i]=='1'){
			for(int j=i+1;j<=n;++j){
				cnt+=s[j]=='0';
			}
			break;
		}
	}
	printf(cnt>=6?"yes\n":"no\n");
	return 0;
}