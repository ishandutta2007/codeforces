#include<bits/stdc++.h>
#define SZ(x) ((int)x.size())
#define pb push_back
#define E {if(!ch[u][tmp])ch[u][tmp]=++nc;u=ch[u][tmp];}
template <typename _Tp>inline void chmax(_Tp &a,const _Tp &b){a=a<b?b:a;}
template <typename _Tp>inline void chmin(_Tp &a,const _Tp &b){a=a<b?a:b;}
const int N=20005;
char A[805],B[805];int l[805],r[805],fail[N];
int ch[N][10],nc,_q[N],_l,_r;
std::vector<int> v[N];
int dp[2005][N],s[N],val[N],opt[2005][N];
int main(){
	int n;scanf("%s%s%d",A+1,B+1,&n);
	int la=strlen(A+1),lb=strlen(B+1);
	for(int i=1;i<=lb;++i)r[i]=B[i]-48;
	for(int i=1;i<=la;++i)l[i+lb-la]=A[i]-48;
	for(int i=1;i<=lb;++i){
		if(l[i]!=r[i]){
			bool tag=true;
			int u=0,tmp;for(int j=1;j<i;++j){
				tag&=l[j]==0,tmp=l[j];
				if(!tag)E;
			}
			int qwq=u;bool T=tag&(l[i]==0);
			tmp=l[i];if(!T)E;
			for(int j=i+1;j<=lb;++j){
				for(int k=l[j]+1;k<10;++k){
					if(!ch[u][k])ch[u][k]=++nc;
					v[ch[u][k]].pb(lb-j);
				}
				T&=l[j]==0,tmp=l[j];
				if(!T)E;
			}
			v[u].pb(0);
			u=qwq;T=tag&(r[i]==0);
			tmp=r[i];if(!T)E;
			for(int j=i+1;j<=lb;++j){
				for(int k=0;k<r[j];++k){
					if(!ch[u][k])ch[u][k]=++nc;
					v[ch[u][k]].pb(lb-j);
				}
				T&=l[j]==0,tmp=r[j];
				if(!T)E;
			}
			v[u].pb(0);
			u=qwq;
			for(int k=l[i]+1;k<r[i];++k){
				if(!ch[u][k])ch[u][k]=++nc;
				v[ch[u][k]].pb(lb-i);
			}
			break;
		}
		else if(i==lb){
			bool tag=true;
			int u=0,tmp;for(int j=1;j<=lb;++j){
				tag&=l[j]==0,tmp=l[j];
				if(!tag)E;
			}
			v[u].pb(0);
		}
	}
	_l=1,_r=0;for(int i=0;i<10;++i)if(ch[0][i])_q[++_r]=ch[0][i];
	while(_l!=_r+1){
		int x=_q[_l++];
		for(int i=0;i<10;++i){
			if(ch[x][i])fail[ch[x][i]]=ch[fail[x]][i],_q[++_r]=ch[x][i];
			else ch[x][i]=ch[fail[x]][i];
		}
	}
	for(int i=0;i<=nc;++i)std::sort(v[i].begin(),v[i].end(),std::greater<int>());
	memset(dp,-63,sizeof(dp));
	for(int i=0;i<=nc;++i)dp[n][i]=0;
	for(int i=n;i>=0;--i){
		for(int j=0;j<=nc;++j)while(!v[j].empty()&&v[j].back()<=n-i)v[j].pop_back(),++val[j];
		for(int j=0;j<=_r;++j){
			int x=_q[j];
			if(i!=n)for(int k=0;k<10;++k)if(dp[i+1][ch[x][k]]>dp[i][x])dp[i][x]=dp[i+1][ch[x][k]],opt[i][x]=k;
			s[x]=val[x]+s[fail[x]],dp[i][x]+=s[x];
		}
	}
	printf("%d\n",dp[0][0]);
	for(int i=0,j=0;i<n;++i)putchar(opt[i][j]+48),j=ch[j][opt[i][j]];
	putchar('\n');
	return 0;
}