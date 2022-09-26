//SMAWK algorithm
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
//#define mak akioi
namespace Grader{
	int a[1010][1010];
}
map<int,int> mp[N];
int n,m,p[N];
inline int Ask(int x,int y){
	if(mp[x].count(y))return mp[x][y];
	printf("? %d %d\n",x,y);
	fflush(stdout);
	#ifdef mak
		return mp[x][y]=Grader::a[x][y];
	#endif
	return mp[x][y]=read();
}
vector<int> Reduce(vector<int> &A,vector<int> &B){
	static int pre[N],suf[N],head;
	head=(int)B.size()+1;
	for(int i=0;i<(int)B.size();++i){
		pre[i]=i-1;
		suf[i]=i+1;
	}
	pre[0]=head;
	suf[head]=0; 
	auto Del = [&](int x) -> void {
		suf[pre[x]]=suf[x];
		pre[suf[x]]=pre[x];
	};
	int x=0,y=0;
	int T=max(0,(int)B.size()-(int)A.size());
	while(T--){
		if(Ask(A[x],B[y])>Ask(A[x],B[suf[y]])){
			y=suf[y];
			Del(pre[y]);
			if(x)y=pre[y],--x;
		}
		else{
			if(x+1==(int)A.size())Del(suf[y]);
			else ++x,y=suf[y],++T;
		}
	}
	vector<int> ans;
	for(int i=suf[head];i!=B.size();i=suf[i]){
		ans.push_back(B[i]);
	}
	return ans;
}
void SMAWK(vector<int> A,vector<int> B){
	B=Reduce(A,B);
	if(A.size()==1){
		p[A[0]]=B[0];
		return;	
	}
	vector<int> C;
	for(int i=0;i<(int)A.size();++i){
		if(!(i&1))C.push_back(A[i]);
	}
	SMAWK(C,B);
	for(int i=0;i<(int)A.size();++i){
		if(i&1){
			int l=lower_bound(B.begin(),B.end(),p[A[i-1]])-B.begin();
			int r=(i+1==A.size()?B.size()-1:lower_bound(B.begin(),B.end(),p[A[i+1]])-B.begin());
			p[A[i]]=*min_element(B.begin()+l,B.begin()+r+1,[&](int j1,int j2){return Ask(A[i],j1)<Ask(A[i],j2);});
		}
	}
	
} 
int main(){
	n=read(),m=read();
	#ifdef mak
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				Grader::a[i][j]=read();
			}
		}
	#endif
	static vector<int> A,B;
	for(int i=1;i<=n;++i)A.push_back(i);
	for(int i=1;i<=m;++i)B.push_back(i);
	SMAWK(A,B);
	int ans=1e9+233;
	for(int i=1;i<=n;++i){
		ans=min(ans,Ask(i,p[i]));
	}
	printf("! %d\n",ans);
	fflush(stdout);
	return 0;
}