#include<bits/stdc++.h>
using namespace std;
#define N 75010
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
int n,Q,len,blocks,L[N],R[N],a[N],pos[N],cnt;
vector<pair<int,int> > OP;
vector<int> p[N],ans;
vector<vector<int> > q[N];
int Merge(int x,int y){
	if(!x||!y)return x|y;
	++cnt;
	OP.emplace_back(x,y);
	return cnt;	
}
int Query(int l,int r,const vector<int> &V,const vector<vector<int> > &T){
	l=lower_bound(V.begin(),V.end(),l)-V.begin();
	r=upper_bound(V.begin(),V.end(),r)-V.begin()-1;
	if(l>=V.size()||r<0||l>r)return 0;
	return T[l][r];
}
vector<vector<int> > Solve(vector<int> &V){
	vector<vector<int> > T;
	T.resize(V.size());
	for(int i=0;i<(int)V.size();++i){
		T[i].resize(V.size());	
	}
	if(V.size()==1){
		T[0][0]=V[0];
		return T;
	}
	auto tmp=V;
	nth_element(tmp.begin(),tmp.begin()+(int)V.size()/2,tmp.end(),[&](int i,int j){return a[i]<a[j];});
	int mid=tmp[V.size()/2];
	vector<int> A,B;
	for(int i=0;i<(int)V.size();++i){
		if(a[V[i]]<a[mid])A.push_back(V[i]);
		else B.push_back(V[i]);	
	}
	auto TA=Solve(A),TB=Solve(B);
	for(int i=0;i<(int)V.size();++i){
		for(int j=i;j<(int)V.size();++j){
			T[i][j]=Merge(Query(V[i],V[j],A,TA),Query(V[i],V[j],B,TB));
		}
	}
	return T;
}
int main(){
	n=read(),Q=read();
	cnt=n;
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	len=min(n,(int)ceil(sqrt(Q)));
	blocks=n/len;
	if(n%len)++blocks;
	for(int i=1;i<=blocks;++i){
		L[i]=(i-1)*len+1,R[i]=min(n,i*len);
		for(int j=L[i];j<=R[i];++j)pos[j]=i;
	}
	for(int i=1;i<=blocks;++i){
		for(int j=1;j<=n;++j){
			if(a[j]>=L[i]&&a[j]<=R[i])p[i].push_back(j);
		}
		q[i]=Solve(p[i]);
	}
	while(Q--){
		int l=read(),r=read();
		int now=0;
		for(int i=1;i<=blocks;++i){
			now=Merge(now,Query(l,r,p[i],q[i]));
		}
		ans.push_back(now);
	}
	printf("%d\n",n+(int)OP.size());
	for(auto [x,y]:OP)printf("%d %d\n",x,y);
	for(auto x:ans)printf("%d ",x);
	printf("\n");
	return 0;
}