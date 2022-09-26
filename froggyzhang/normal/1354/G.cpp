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
int n,T;
inline int Ask(const vector<int> &A,const vector<int> &B){
	printf("? %d %d\n",(int)A.size(),(int)B.size());
	for(auto x:A){
		printf("%d ",x);
	}
	printf("\n");
	for(auto x:B){
		printf("%d ",x);
	}
	printf("\n");
	fflush(stdout);
	string s;
	cin>>s;
	return s[0]=='F'?-1:(s[0]=='S'?1:0); 
}
void Report(int x){
	printf("! %d\n",x);
	fflush(stdout);
}
mt19937 rnd(time(0));
vector<int> V(int l,int r){
	vector<int> A;
	for(int i=l;i<=r;++i)A.push_back(i);
	return A;
} 
void Solve(){
	n=read();read();
	int u=1;
	for(int i=1;i<=6;++i){
		int v=rnd()%n+1;
		while(u==v)v=rnd()%n+1;
		if(Ask(V(u,u),V(v,v))==1)u=v;
	}
	if(u^1){
		if(Ask(V(1,1),V(u,u))==1){
			return Report(1);
		}
	}
	int p=0;
	while((1<<p+1)<=n){
		if(Ask(V(1,1<<p),V((1<<p)+1,1<<p+1)))break;
		++p;
	}
	int l=(1<<p)+1,r=min(1<<p+1,n)+1,ans=l-1;
	while(l<r){
		int mid=(l+r)>>1;
		if(Ask(V(1,mid-l+1),V(l,mid))){
			r=mid;		
		}
		else{
			ans=mid,l=mid+1;
		}
	}
	Report(ans+1);
}	
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}