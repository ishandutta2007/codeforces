#include<bits/stdc++.h>
using namespace std;
#define N 1010
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
int T,n,m;
char mp[N][N];
void Solve(){
	n=read(),m=read()+1;
	for(int i=1;i<=n;++i){
		scanf("%s",mp[i]+1);
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(i==j)continue;
			if(mp[i][j]==mp[j][i]){
				printf("YES\n");
				int tp=i;
				while(m--){
					printf("%d ",tp),tp^=i^j;
				}
				printf("\n");
				return;
			}
		}
	}
	if(m&1){
		for(int i=1;i<n;++i){
			for(int j=1;j<=n;++j){
				if(i==j||i+1==j)continue;
				int tp,o,z;
				if(mp[j][i]==mp[i][i+1])o=i,z=i+1;
				else if(mp[j][i+1]==mp[i+1][i])o=i+1,z=i;
				else continue;
				printf("YES\n");
				if((m>>1)&1)tp=z;
				else tp=o;
				for(int k=0;k<(m>>1);++k){
					printf("%d ",tp),tp^=o^z;
				}
				for(int k=0;k<(m>>1);++k){
					printf("%d ",tp),tp^=o^j;
				}
				printf("%d\n",((m>>1)&1)?j:o);
				return;
			}
		}
		printf("NO\n");
		return;
	}
	printf("YES\n");
	int tp=1;
	while(m--){
		printf("%d ",tp),tp^=1^2;
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