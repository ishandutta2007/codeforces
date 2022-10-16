#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 500005
#define py cout<<"YES\n"
#define pn cout<<"NO\n";
vector<int>son[N];
void dfs(int now,int fat){
	for(int T,i=0;i<son[now].size();++i)
		if((T=son[now][i])!=fat)dfs(T,now);
}
int T,n,k,i,l,r,mid,j,x,y,m,a[N],b[N];
int check(int x){
	int ee=0;
	for(i=1;i<=n;++i){
		if(a[i]>=ee&&b[i]>=x-ee-1){
			++ee;
			if(ee==x)return 1;
		}
	}
	return 0;
}
int qwq=0;
#define mod 1000000007
ll ans,fl,c[36],dp[36][N];
ll ksm(ll x,ll y){ll ret=1;for(;y;y>>=1,x=x*x%mod)if(y&1)ret=ret*x%mod;return ret;}
int main(){cin.tie(0);
	T=1;
//	cin>>T;
	while(T--){
		cin>>n;
		memset(c,0,sizeof(c));
		for(i=1;i<=n;++i){
			cin>>x;qwq=0;
			while(x%2==0)++qwq,x/=2;
			++c[qwq];
		}
		ans=ksm(2,n)-1;
		for(i=1;i<=30;++i){
			if(c[i]){
				fl=0;
				for(j=i;j<=30;++j)fl+=c[j];
				ans-=ksm(2,fl-1);
			}
		}
		cout<<(ans%mod+mod)%mod<<"\n";
	}
}