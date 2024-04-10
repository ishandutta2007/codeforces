#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define N 100010
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
int T,n,A,B;
char s[N];
vector<pair<int,int> > mine;
int main(){
	T=read();
	while(T--){
		A=read(),B=read();
		scanf("%s",s+1);
		n=strlen(s+1);
		int ans=0;
		for(int i=1,las=-1;i<=n;++i){
			if(s[i]=='1'){
				if(~las)ans+=min(A,(i-las-1)*B);
				else ans+=A;
				las=i;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}