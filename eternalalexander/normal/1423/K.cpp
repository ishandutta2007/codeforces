#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5,mx=1e6;
int T;
bool vis[N];
int c[N],cnt,d[N];
void init(){
	for(int i=2;i<=mx;i++){
		if(!vis[i]) {
			c[++cnt]=i;
			d[c[cnt]]++;d[min(1ll*c[cnt]*c[cnt],1ll*mx+1)]--;
			for(int j=i;j<=mx;j+=i)
				vis[j]=1;
		}
	}
	d[1]++;
	for(int i=1;i<=mx;i++) d[i]+=d[i-1];
}
int main(){
	init();
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		printf("%d\n",d[n]);
	}
}