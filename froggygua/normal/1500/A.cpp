#include<bits/stdc++.h>
using namespace std;
#define N 200020
#define M 5000020
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
int n,a[N];
pair<int,int> t[M];
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			int x=a[i]+a[j];
			if(t[x].first){
				if(i^t[x].first&&i^t[x].second&&j^t[x].first&&j^t[x].second){
					printf("YES\n");
					printf("%d %d %d %d\n",i,j,t[x].first,t[x].second);
					return 0;
				}
			}
			else t[x]=make_pair(i,j);
		}
	}
	printf("NO\n");
	return 0;
}