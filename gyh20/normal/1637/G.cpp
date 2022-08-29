#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
const int M=998244353;
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
inline int Mod(re int x){return x>=M?x-M:x;}
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return s;
}
int t,n,a[1000002],ans,num[100002],nn[100002];
char s[1000002];
vector<int>ansa,ansb;
inline void Do(re int x,re int y){
	assert(nn[x]),--nn[x];
	assert(nn[y]),--nn[y];
	++nn[x+y],++nn[abs(x-y)];
	ansa.push_back(x),ansb.push_back(y);
}
inline void solve(vector<int>A){
	if(!A.size())return;
	if(A.size()==1){
		++num[A[0]];
		return;
	}
	if(A.size()==2){
		++num[A[0]],++num[A[1]];
		return;
	}
	re int pos;
	for(re int i=A.size()-1;~i;--i)if((A[i]&(-A[i]))==A[i]){pos=i;break;}
	if(pos==A.size()-1){
		++num[A[pos]];
		A.pop_back(),solve(A);
		return;
	}
	vector<int>B;++num[A[pos]];
	for(re int i=A.size()-1;i>pos;--i)Do(A[i],A[pos-(i-pos)]),B.push_back(A[i]-A[pos-(i-pos)]),++num[A[pos]<<1];
	reverse(B.begin(),B.end());
	solve(B);
	re int xx=A.size();
	for(re int i=0;i<(xx-1-pos)*2;++i)A.pop_back();A.pop_back();
	solve(A);
}
inline void Out(){
	printf("%u\n",ansa.size());
	for(re int i=0;i<ansa.size();++i)printf("%d %d\n",ansa[i],ansb[i]);
	ansa.clear(),ansb.clear();
}
int main(){
	t=read();
	while(t--){
		n=read();
		if(n==2){
			puts("-1");
			continue;
		}
		vector<int>A;
		for(re int i=1;i<=n;++i)A.push_back(i),num[i]=0;
		re int m=1;
		while(m<n)m<<=1;
		fill(num,num+m+1,0);
		for(re int i=0;i<=m;++i)nn[i]=0;
		for(re int i=1;i<=n;++i)nn[i]=1;
		solve(A);
		for(re int i=1;i<=m;++i)if(num[i])assert(nn[i]==num[i]);
		for(re int i=1;i<m;++i)
			if(num[i]>1){
				Do(i,i),num[i]-=2,++num[0],++num[i<<1];
				break;
			}
		for(re int i=1;i<m;++i)
			for(re int j=1;j<=num[i];++j){
				re int x=i;
				while(x!=m)Do(0,x),Do(x,x),x<<=1;
			}
			Do(0,m);
		Out();
	}
}