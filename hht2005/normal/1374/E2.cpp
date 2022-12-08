#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
#define mp make_pair
typedef pair<int,int> pii;
vector<pii>AB,A,B,O,S;
int f[maxn],n,m,k,ans=2e9+10,X=-1;
int calc(int x) {
	if(~f[x])return f[x];
	if(2*k-x>m||x>int(AB.size())||int(A.size())<k-x||int(B.size())<k-x)return f[x]=2e9+10;
	S=O;
	int Sum=0,N=max(k-x,0);
	for(int i=0;i<x;i++)Sum+=AB[i].first;
	for(int i=0;i<N;i++)Sum+=A[i].first;
	for(int i=0;i<N;i++)Sum+=B[i].first;
	for(int i=x;i<int(AB.size());i++)S.push_back(AB[i]);
	for(int i=N;i<int(A.size());i++)S.push_back(A[i]);
	for(int i=N;i<int(B.size());i++)S.push_back(B[i]);
	sort(S.begin(),S.end());
	for(int i=0;i<m-x-2*N;i++)Sum+=S[i].first;
	if(ans>Sum)ans=Sum,X=x;
	return f[x]=Sum;
}
int main() {
	memset(f,-1,sizeof(f));
	int t,a,b;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++) {
		scanf("%d%d%d",&t,&a,&b);
		if(a&&b)AB.push_back(mp(t,i));
		if(!a&&b)B.push_back(mp(t,i));
		if(a&&!b)A.push_back(mp(t,i));
		if(!a&&!b)O.push_back(mp(t,i));
	}
	sort(AB.begin(),AB.end());
	sort(A.begin(),A.end());
	sort(B.begin(),B.end());
	sort(O.begin(),O.end());
	int L=0,R=AB.size();
	while(L<=R) {
		int mid=(L+R)>>1;
		if(calc(mid)<calc(mid+1))R=mid-1;
		else L=mid+1;
	}
	if(X==-1) {
		puts("-1");
		return 0;
	}
	S=O;
	printf("%d\n",ans);
	int N=max(k-X,0);
	for(int i=0;i<X;i++)printf("%d ",AB[i].second);
	for(int i=0;i<N;i++)printf("%d ",A[i].second);
	for(int i=0;i<N;i++)printf("%d ",B[i].second);
	for(int i=X;i<int(AB.size());i++)S.push_back(AB[i]);
	for(int i=N;i<int(A.size());i++)S.push_back(A[i]);
	for(int i=N;i<int(B.size());i++)S.push_back(B[i]);
	sort(S.begin(),S.end());
	for(int i=0;i<m-X-N-N;i++)printf("%d ",S[i].second);
	puts("");
	return 0;
}