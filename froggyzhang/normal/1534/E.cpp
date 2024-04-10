#include<bits/stdc++.h>
using namespace std;
#define N 505
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
int n,k,ans,a[N],sum;
int Ask(vector<int> &A){
	printf("?");
	for(auto x:A)printf(" %d",x);
	printf("\n");
	fflush(stdout);
	return read();
}
inline bool check(){
	static int b[N];
	for(int i=1;i<=n;++i)b[i]=0;
	for(int T=1;T<=sum/k;++T){
		static int p[N];
		for(int i=1;i<=n;++i){
			p[i]=i;
		}
		sort(p+1,p+n+1,[&](int i,int j){return a[i]-b[i]>a[j]-b[j];});
		for(int i=1;i<=k;++i){
			if(a[p[i]]==b[p[i]])return false;
			++b[p[i]];
		}
	}
	return true;
}
int main(){
	n=read(),k=read();
	sum=n;
	for(int i=1;i<=n;++i){
		a[i]=1;
	}
	int now=1;
	while(sum<=k*n){
		if(sum%k==0&&check())break;
		a[now]+=2;
		sum+=2;
		now=now%n+1;
	}
	if(sum>k*n){
		printf("-1\n");
		fflush(stdout);
		return 0;
	}
	for(int T=1;T<=sum/k;++T){
		static int p[N];
		for(int i=1;i<=n;++i){
			p[i]=i;
		}
		sort(p+1,p+n+1,[&](int i,int j){return a[i]>a[j];});
		static vector<int> A;
		A.clear();
		for(int i=1;i<=k;++i){
			A.push_back(p[i]);
			--a[p[i]];
		}
		ans^=Ask(A);
	}
	printf("! %d\n",ans);
	fflush(stdout);
	return 0;
}