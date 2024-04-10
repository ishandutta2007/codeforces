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
#define N 1005
int T,n,m;
char s[N],t[N];
void Solve(){
	scanf("%s",s+1);
	scanf("%s",t+1);
	n=strlen(s+1);
	m=strlen(t+1);
	for(int i=1;i<=n;++i){
		for(int j=i;j<=n;++j){
			int k=j-(m-(j-i+1));
			if(k>=1){
				bool ok=true;
				int u=1;
				for(int p=i;p<=j;++p){
					if(s[p]^t[u++]){
						ok=false;break;
					}		
				}
				for(int p=j-1;p>=k;--p){
					if(s[p]^t[u++]){
						ok=false;
						break;
					}
				}
				if(ok){
					printf("YES\n");
					return;
				}
			}
		}	
	}
	printf("NO\n");
}
int main(){
	
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}