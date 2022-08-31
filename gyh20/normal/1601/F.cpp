#include<bits/stdc++.h>
#define re register
#define int long long
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
const int M1=998244353,M2=1e9+7,B=1e6;
int n,cnt,sum[10],ans;
vector<int>A[10];
inline void dfs(re int x,re int y){
	++cnt,A[x].push_back(((cnt-y)%M1+M1)%M1),sum[x]+=(cnt-y+M1)%M1;
	if(x==6)return;
	for(re int i=0;i<10;++i)dfs(x+1,y*10+i);
}
inline void dfs1(re int x,re int y){
	if(y>n)return;
	if(y*B>n/10&&y*B+999999<=n){
		re int pw=1;
		for(re int i=0;i<7;++i){
			re int tmp=((cnt-y*pw)%M1+M1)%M1;
			re int pos=lower_bound(A[i].begin(),A[i].end(),M1-tmp)-A[i].begin();
			ans+=tmp*A[i].size()%M2+sum[i];
			ans-=(A[i].size()-pos)*M1%M2;
			pw*=10,ans%=M2;
		}
		for(re int i=0;i<7;++i)cnt+=A[i].size();
		return;
	}
	if(x)++cnt,ans+=((cnt-y)%M1+M1)%M1,ans%=M2;
	for(re int i=!x;i<=9;++i)dfs1(x+1,y*10+i);
}
signed main(){
	n=read(),dfs(0,0);
	for(re int i=0;i<7;++i){
		sort(A[i].begin(),A[i].end());
		sum[i]%=M2,sum[i]+=M2,sum[i]%=M2;
	}cnt=0,dfs1(0,0),printf("%lld",((ans%M2+M2)%M2));
}