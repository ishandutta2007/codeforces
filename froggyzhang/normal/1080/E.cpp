#include<bits/stdc++.h>
using namespace std;
#define N 255
typedef long long ll;
typedef unsigned long long ull;
int n,m;
ll ans;
char s[N][N];
mt19937_64 rnd(time(0)); 
ull w[26],_h[N<<1];
int init(ull *a,ull *b,int n){
	a[0]=1,a[1]=2,a[2*n+2]=3;
	for(int i=1;i<=n;++i){
		a[i<<1]=b[i],a[i<<1|1]=2;
	}
	return 2*n+1;
}
void Manacher(ull *s,int *d,int n){
	for(int i=1,po=0,mx=0;i<=n;++i){
		d[i]=mx>i?min(mx-i,d[2*po-i]):1;
		while(s[i+d[i]]==s[i-d[i]])++d[i];
		if(i+d[i]>mx)po=i,mx=i+d[i];
	}	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>(s[i]+1);
	}
	for(int i=0;i<26;++i){
		w[i]=rnd();
	}
	for(int l=1;l<=m;++l){
		static ull h[N];
		static int g[N];
		memset(h,0,sizeof(h));
		memset(g,0,sizeof(g));
		for(int r=l;r<=m;++r){
			for(int i=1;i<=n;++i){
				g[i]^=1<<(s[i][r]-'a');
				h[i]+=w[s[i][r]-'a'];
			}
			int len=init(_h,h,n);
			static int d[N<<1],ban[N];
			memset(d,0,sizeof(d));
			memset(ban,0,sizeof(ban));
			for(int i=1;i<=n;++i){
				if(g[i]^((g[i]&-g[i]))){
					_h[i<<1]=rnd();ban[i]=1;
				}
			}
			Manacher(_h,d,len);
			for(int i=1;i<=len;++i){
				if(!(i&1)&&ban[i>>1])continue;
				ans+=d[i]/2;	
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}