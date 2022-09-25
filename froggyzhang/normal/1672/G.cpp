#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
#define N 2005
typedef long long ll;
int n,m,pw2[N*N];
char s[N][N];
void init(int n){
	pw2[0]=1;
	for(int i=1;i<=n;++i){
		pw2[i]=(pw2[i-1]<<1)%mod;
	}
}
class Union_Set{
public:
	int f[N+N];
	void init(int n){
		for(int i=1;i<=n;++i){
			f[i]=i;
		}
	}
	inline int getf(int x){
		return f[x]==x?x:f[x]=getf(f[x]);
	}
	inline bool Merge(int x,int y){
		int fx=getf(x),fy=getf(y);
		if(fx==fy)return false;
		f[fy]=fx;
		return true;
	}
}S;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	init(n*m);
	for(int i=1;i<=n;++i){
		cin>>(s[i]+1);
	}
	if(!(n&1)&&!(m&1)){
		int cnt=0;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
				cnt+=s[i][j]=='?';
		cout<<pw2[cnt]<<'\n';
		return 0;
	}
	if(!(m&1)){
		int ans=0;
		for(int o=0;o<2;++o){
			int tmp=1;
			for(int j=1;j<=m;++j){
				int cnt=0,one=0;
				for(int i=1;i<=n;++i){
					if(s[i][j]=='1')++one;
					else if(s[i][j]=='?')++cnt;
				}
				if(!cnt){
					if((one&1)^o)tmp=0;
				}
				else{
					tmp=1LL*tmp*pw2[cnt-1]%mod;
				}
			}
			ans+=tmp;
		}
		cout<<ans%mod<<'\n';
		return 0;
	}
	if(!(n&1)){
		int ans=0;
		for(int o=0;o<2;++o){
			int tmp=1;
			for(int i=1;i<=n;++i){
				int cnt=0,one=0;
				for(int j=1;j<=m;++j){
					if(s[i][j]=='1')++one;
					else if(s[i][j]=='?')++cnt;
				}
				if(!cnt){
					if((one&1)^o)tmp=0;
				}
				else{
					tmp=1LL*tmp*pw2[cnt-1]%mod;
				}
			}
			ans+=tmp;
		}
		cout<<ans%mod<<'\n';
		return 0;
	}
	S.init(n+m);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(s[i][j]=='?')S.Merge(i,j+n);
		}
	}
	int ans=0;
	for(int o=0;o<2;++o){
		static int cnt[N+N],sum[N+N];
		memset(cnt,0,sizeof(cnt));
		memset(sum,0,sizeof(sum));
		for(int i=1;i<=n+m;++i)cnt[i]=1;
		for(int i=1;i<=n;++i){
			sum[S.getf(i)]^=o;
			--cnt[S.getf(i)];
		}
		for(int j=1;j<=m;++j){
			sum[S.getf(j+n)]^=o;
			--cnt[S.getf(j+n)];
		}
		int tot=1;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				if(s[i][j]=='?'){
					++cnt[S.getf(i)];
				}
				else{
					sum[S.getf(i)]^=s[i][j]-'0';
					sum[S.getf(j+n)]^=s[i][j]-'0';
				}
			}
		}
		for(int i=1;i<=n+m;++i){
			if(S.getf(i)==i){
				if(sum[i]){
					tot=0;
					break;
				}
				else{
					tot=1LL*tot*pw2[cnt[i]]%mod;
				}
			}
		}
		ans+=tot;
	}
	cout<<ans%mod<<'\n';
	return 0;
}//