#include<bits/stdc++.h>
using namespace std;
#define N 1005
typedef long long ll;
const ll inf=1e18+233;
typedef pair<int,int> pii;
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
int n,m,lcp[N][N];
char s[N];
ll k;
vector<pair<int,int> > R;
inline bool cmp(pii i,pii j){
	int leni=i.second-i.first+1,lenj=j.second-j.first+1;
	int p=lcp[i.first][j.first];
	if(p>=min(leni,lenj))return leni>lenj;
	return s[i.first+p]>s[j.first+p];	
}
ll check(int L,int R){
	static ll dp[N][N];
	static ll sum[N];
	memset(dp,0,sizeof(dp));
	dp[0][n+1]=1;
	for(int i=1;i<=m;++i){
		memset(sum,0,sizeof(sum));
		for(int j=n;j>=0;--j){
			sum[j]=min(inf,sum[j+1]+dp[i-1][j+1]);
		}
		for(int j=n;j>=1;--j){
			if(lcp[L][j]>=min(R-L+1,n-j+1)){
				dp[i][j]=sum[min(n+1,j+R-L)];
			}
			else if(s[j+lcp[L][j]]>s[L+lcp[L][j]]){
				dp[i][j]=sum[j+lcp[L][j]];
			}
			else{
				dp[i][j]=0;	
			}
		}
	}
	return dp[m][1];
}
int main(){
	n=read(),m=read();
	k=read();
	scanf("%s",s+1);
	for(int i=n;i>=1;--i){
		for(int j=n;j>=1;--j){
			lcp[i][j]=(s[i]==s[j]?lcp[i+1][j+1]+1:0);
		}	
	}
	for(int i=1;i<=n;++i){
		for(int j=i;j<=n;++j){
			R.emplace_back(i,j);
		}	
	}
	sort(R.begin(),R.end(),cmp);
	R.erase(unique(R.begin(),R.end()),R.end());
	int l=0,r=R.size(),ans=-1;
	while(l<r){
		int mid=(l+r)>>1;
		if(check(R[mid].first,R[mid].second)>=k){
			ans=r=mid;
		}
		else{
			l=mid+1;
		}
	}
	l=R[ans].first,r=R[ans].second;
	for(int i=l;i<=r;++i){
		putchar(s[i]);	
	}
	return 0;
}