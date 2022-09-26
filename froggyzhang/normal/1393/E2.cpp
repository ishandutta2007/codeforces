#include<bits/stdc++.h>
using namespace std;
#define N 100010
#define M 1000100
typedef long long ll;
typedef unsigned long long ull;
const ull base=233;
const int mod=1e9+7;
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
ull pw[M];
int n,len[N],ans;
string s[N];
vector<int> p[N],dp[N];
vector<ull> h[N];
inline ull Hash(vector<ull> &h,int l,int r){
	return h[r]-(l==0?0:h[l-1])*pw[r-l+1];	
}
inline bool same(int i,int l1,int r1,int j,int l2,int r2){
	return Hash(h[i],l1,r1)==Hash(h[j],l2,r2);	
}
int cmp(int i,int l1,int r1,int j,int l2,int r2){
	int l=0,r=min(r1-l1+1,r2-l2+1)+1,p=0;
	while(l<r){
		int mid=(l+r)>>1;
		if(same(i,l1,l1+mid-1,j,l2,l2+mid-1)){
			p=mid,l=mid+1;
		}
		else{
			r=mid;
		}
	}
	char ci=(r1<=l1+p-1?char(0):s[i][l1+p]);
	char cj=(r2<=l2+p-1?char(0):s[j][l2+p]);
	if(ci==cj)return 0;
	if(ci<cj)return 1;
	if(ci>cj)return -1;
}
inline bool Comp(int i,int x,int j,int y){
	int p1=min(x,y),p2=max(x,y);
	int t=cmp(i,0,p1-1,j,0,p1-1);
	if(t==1)return true;
	if(t==-1)return false;
	t=(x<=y?cmp(i,x+1,min(len[i]-1,y),j,x,min(len[j]-1,y-1)):cmp(i,y,min(len[i]-1,x-1),j,y+1,min(len[j]-1,x)));
	if(t==1)return true;
	if(t==-1)return false;
	t=cmp(i,p2+(x<len[i]-1),len[i]-1,j,p2+(y<len[j]-1),len[j]-1);
	if(t==1)return true;
	if(t==-1)return false;
	return true;
}
int main(){
	n=read();
	pw[0]=1;
	for(int i=1;i<=1000000;++i){
		pw[i]=pw[i-1]*base;
	}
	for(int i=1;i<=n;++i){
		cin>>s[i];
		s[i]+='#';
		len[i]=s[i].length();
		p[i].resize(len[i]);
		h[i].resize(len[i]);
		dp[i].resize(len[i]);
	}
	for(int i=1;i<=n;++i){
		h[i][0]=s[i][0];
		for(int j=1;j<len[i];++j){
			h[i][j]=h[i][j-1]*base+s[i][j];
		}	
	}
	for(int i=1;i<=n;++i){
		for(int j=0;j<len[i];++j){
			p[i][j]=j;
		}
		static int nxt[M];
		nxt[len[i]-1]=len[i];
		for(int j=len[i]-2;j>=0;--j){
			nxt[j]=(s[i][j]==s[i][j+1]?nxt[j+1]:j+1);
		}
		sort(p[i].begin(),p[i].end(),[&](int x,int y){return nxt[x]==nxt[y]?x<y:(x<y?s[i][x]>s[i][nxt[x]]:s[i][y]<s[i][nxt[y]]);});
	}
	for(int j=0;j<len[1];++j){
		dp[1][j]=1;
	}
	for(int i=2;i<=n;++i){
		int k=0,sum=0;
		for(int j=0;j<len[i];++j){
			while(k<len[i-1]&&Comp(i-1,p[i-1][k],i,p[i][j]))sum=(sum+dp[i-1][p[i-1][k]])%mod,++k;
			dp[i][p[i][j]]=sum;
		}	
	}
	for(int j=0;j<len[n];++j){
		ans=(ans+dp[n][j])%mod;
	}
	printf("%d\n",ans);
	return 0;
}