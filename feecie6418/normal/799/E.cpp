#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[2][2][200005],cnt[2][2],b[200005],isa[200005],isb[200005],n,m,K,s1,s2;
ll s[2][2][200005],ans=1e18;
namespace K_min_sum{
 
multiset<int> s1,s2;
int K;
ll sum=0;
void Do(){
	while(s1.size()>K){
		int u=*--s1.end();
		s1.erase(s1.find(u)),s2.insert(u),sum-=u;
	}
	while(s1.size()<K&&s2.size()){
		int u=*s2.begin();
		s2.erase(s2.find(u)),s1.insert(u),sum+=u;
	}
}
void Ins(int x){
	s1.insert(x),sum+=x,Do();
}
void Del(int x){
	if(s1.find(x)!=s1.end())s1.erase(s1.find(x)),sum-=x;
	else if(s2.find(x)!=s2.end())s2.erase(s2.find(x));
	Do();
}
void Makek(int k){
	K=k,Do();
}
ll Query(){
	if(s1.size()<K)return 1e18;
	return sum;
}
 
}
int main(){
	cin>>n>>m>>K,K_min_sum::Makek(K);
	for(int i=1;i<=n;i++)cin>>b[i];
	cin>>s1;
	for(int i=1,x;i<=s1;i++)cin>>x,isa[x]=1;
	cin>>s2;
	for(int i=1,x;i<=s2;i++)cin>>x,isb[x]=1;
	for(int i=1;i<=n;i++){
		int *p=a[isa[i]][isb[i]];
		p[++cnt[isa[i]][isb[i]]]=b[i];
	}
	for(int i=0;i<2;i++)for(int j=0;j<2;j++)sort(a[i][j]+1,a[i][j]+cnt[i][j]+1);
	for(int i=0;i<2;i++)for(int j=0;j<2;j++)for(int k=1;k<=cnt[i][j];k++)s[i][j][k]=s[i][j][k-1]+a[i][j][k];
	for(int i=1;i<=cnt[0][0];i++)K_min_sum::Ins(a[0][0][i]);
	for(int i=1;i<=cnt[1][1];i++)K_min_sum::Ins(a[1][1][i]);
	for(int i=K+1;i<=cnt[0][1];i++)K_min_sum::Ins(a[0][1][i]);
	for(int i=K+1;i<=cnt[1][0];i++)K_min_sum::Ins(a[1][0][i]);
	for(int i=0;i<=cnt[1][1]&&i<=K;i++){
		int j=K-i;
		if(i)K_min_sum::Del(a[1][1][i]);
		if(j>cnt[1][0]||j>cnt[0][1]||m-i-2*j<0){
			if(j<=cnt[1][0])K_min_sum::Ins(a[1][0][j]);
			if(j<=cnt[0][1])K_min_sum::Ins(a[0][1][j]);
			continue;
		}
		//(1,1)1~i
		//(1,0),(0,1)1~K-i
		K_min_sum::Makek(m-i-2*j);
		ans=min(ans,K_min_sum::Query()+s[1][1][i]+s[1][0][j]+s[0][1][j]);
		if(j&&j<=cnt[1][0])K_min_sum::Ins(a[1][0][j]);
		if(j&&j<=cnt[0][1])K_min_sum::Ins(a[0][1][j]);
	}
	if(ans<1e15)cout<<ans;
	else cout<<-1;
}