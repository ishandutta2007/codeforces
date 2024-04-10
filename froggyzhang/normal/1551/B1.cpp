#include<bits/stdc++.h>
using namespace std;
#define N 200020
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
int T,n,K;
char s[N];
vector<int> p[N];
void Solve(){
	K=2;
	for(int i=1;i<=26;++i)p[i].clear();
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;++i){
		p[s[i]-'a'+1].push_back(i);
	}
	int sum=0;
	for(int i=1;i<=26;++i){
		sum+=min(K,(int)p[i].size());
	}
	printf("%d\n",sum/K);
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}