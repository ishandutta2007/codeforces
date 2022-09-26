#include<bits/stdc++.h>
using namespace std;
#define N 1000100
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
int T,n,k,a[N],c[N];
char s[N];
void Solve(){
	static int vis[N];
	for(int i=0;i<=n;++i)vis[i]=0;
	n=read(),k=read();
	scanf("%s",s+1);
	for(int i=1;i<=n;++i){
		a[i]=(s[i]-'0')^1;
		c[i]=c[i-1]+a[i];
	}
	for(int i=k;i<=n;++i){
		int x=0;
		if(k>=20&&c[i-20]-c[i-k]>0)continue;
		for(int j=max(i-20,i-k+1);j<=i;++j){
			x=(x<<1)|a[j];
		}
		if(x<=n)vis[x]=1;
	}
	int lim=(k<=20?min(n,(1<<k)-1):n);
	for(int i=0;i<=lim;++i){
		if(!vis[i]){
			printf("YES\n");
			string s="";
			for(int j=1;j<=k;++j){
				s+='0'+(i&1);
				i>>=1;
			}
			reverse(s.begin(),s.end());
			cout<<s<<endl;
			return;
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