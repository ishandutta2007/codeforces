#include<bits/stdc++.h>
using namespace std;
#define N 2020
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
char a[N],b[N];
void work(char *s,vector<pair<int,int> > &ans){
	int cnt=0;
	for(int i=1;i<=n;++i){
		if(s[i]=='1')++cnt;	
	}
	auto Find = [&](int x) -> int{
		for(int i=1;i<=n;++i){
			if(s[i]=='1'){
				if(!(--x))return i;
			}
		}
		return n+1;
	};
	auto Rev = [&](int l,int r) -> void{
		ans.emplace_back(l,r);
		reverse(s+l,s+r+1);	
	};
	if(!m||cnt<m)return;
	for(int i=cnt+1;i>m;--i){
		Rev(Find(i-m),Find(i)-1);	
	}
	if(cnt==m){
		int p=Find(1);
		for(int i=p;i<=n;++i){
			if(s[i]^s[n-i+p]){
				if(s[p]>s[n-i+p])Rev(p,n);
				break;
			}	
		}
		return;
	}
	if(m&1){
		for(int i=1;i<=m;++i){
			Rev(Find(2),Find(m+1));
			if(i^m)Rev(Find(1),Find(m+1)-1);	
		}
	}
	else{
		for(int i=1;i<=m/2;++i){
			Rev(Find(1),Find(m+1)-1);
			Rev(Find(1)+1,Find(m+1));	
		}
	}
}
void Solve(){
	n=read(),m=read();
	scanf("%s",a+1);
	scanf("%s",b+1);
	vector<pair<int,int> > A,B;
	work(a,A),work(b,B);
	for(int i=1;i<=n;++i){
		if(a[i]^b[i])return (void)(printf("-1\n"));
	}
	reverse(B.begin(),B.end());
	A.insert(A.end(),B.begin(),B.end());
	printf("%d\n",(int)A.size());
	for(auto [x,y]:A){
		printf("%d %d\n",x,y);
	}
}
int main(){
	T=read();
	while(T--)Solve();
	return 0;
}