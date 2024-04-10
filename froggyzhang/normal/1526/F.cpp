#include<bits/stdc++.h>
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
mt19937 rnd(time(0));
//#define myh akioi
namespace Grader{
	int p[N];
	inline int Ask(int x,int y,int z){
		array<int,3> a={abs(p[x]-p[y]),abs(p[y]-p[z]),abs(p[z]-p[x])};
		sort(a.begin(),a.end());
		return a[1];
	}
}
inline int Ask(int x,int y,int z){
	printf("? %d %d %d\n",x,y,z);
	fflush(stdout);
	#ifdef myh
	return Grader::Ask(x,y,z);
	#endif
	return read();
}
int T,n,ans[N];
inline int Report(){
	printf("!");
	for(int i=1;i<=n;++i){
		printf(" %d",ans[i]);
	}
	printf("\n");
	fflush(stdout);
	#ifdef myh
	for(int i=1;i<=n;++i){
		if(ans[i]^Grader::p[i])return -1;
	}
	return 1;
	#endif
	return read();
}
void Solve(){
	n=read();
	#ifdef myh
	for(int i=1;i<=n;++i){
		Grader::p[i]=read();
	}
	#endif
	for(int i=1;i<=n;++i)ans[i]=0;
	int mn=n+1,A,B,C;
	while(mn>(n-4)/6){
		A=rnd()%n+1,B=rnd()%n+1,C=rnd()%n+1;
		while(A==B||B==C||A==C)B=rnd()%n+1,C=rnd()%n+1;
		mn=min(mn,Ask(A,B,C));
	}
	static vector<int> vec[N];
	for(int i=1;i<=n;++i)vec[i].clear();
	for(int i=1;i<=n;++i){
		if(i==A||i==B)continue;
		vec[Ask(A,B,i)].push_back(i);
	} 
	int m=n;
	while(vec[m].empty())--m;
	if((int)vec[m-1].size()>=2){
		if(Ask(vec[m][0],vec[m-1][0],A)>Ask(vec[m][0],vec[m-1][1],A))swap(vec[m-1][0],vec[m-1][1]);	
	}
	int z1=vec[m][0],z2=vec[m-1][0];
	ans[z1]=1,ans[z2]=2;
	for(int i=1;i<=n;++i){
		if(i==z1||i==z2)continue;
		ans[i]=Ask(z1,z2,i)+2;
	}
	if(ans[1]>ans[2]){
		for(int i=1;i<=n;++i){
			ans[i]=n-ans[i]+1;
		}
	}
	assert(Report()==1);
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}