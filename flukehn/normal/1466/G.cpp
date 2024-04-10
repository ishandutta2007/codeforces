#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=a,i##_end=b;i<i##_end;++i)
using ll=long long;
using pii=pair<int,int>;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
const int mo=1e9+7;
int Pow(int a,int b,int p=mo){int r=1;for(;b;b>>=1,a=1ll*a*a%p)if(b&1)r=1ll*r*a%p;return r;}
//template<typename T>
void inc(int &x,int y){x=(x+y>=mo?x+y-mo:x+y);}
int ad(int x,int y){return x+y>=mo?x+y-mo:x+y;}
template<typename T>T gcd(T a,T b){while(b)a%=b,swap(a,b);return a;}
mt19937 rnd(time(0));

const int N=1e5+11,M=2e6+11;
int n,m;
string s[26];
int len[26];
char t[N],tr[M];

using ull=unsigned long long;
ull base=2333;
ull pool[M*4],g[M],*h[26],tmp[M];
ull *cnt=pool;
ull get(ull *x,int l,int r){
	if(l>r)return 0;
	return x[r]-x[l-1]*g[r-l+1];
}
void cal(ull *x,char *y,int n){
	x[0]=0;
	For(i,1,n+1)x[i]=x[i-1]*base+y[i];
}
void init(){
	g[0]=1;
	For(i,1,M)g[i]=g[i-1]*base;
	For(i,0,m+1){
		h[i]=cnt;
		cnt+=len[i]+2;
		For(j,0,len[i])tr[j+1]=s[i][j];
		cal(h[i],tr,len[i]);
	}
}
int g2[N],g2v[N];
int f[N][26];
int main(){
#ifdef SGR
	freopen("a.txt","r",stdin);
#endif
	ios::sync_with_stdio(0);
	g2[0]=1;
	g2v[0]=1;
	For(i,1,N)g2[i]=ad(g2[i-1],g2[i-1]);
	For(i,1,N)g2v[i]=1ll*(mo+1)/2*g2v[i-1]%mo;
	int q;
	cin>>n>>q>>s[0]>>t;
	for(m=0;;++m){
		len[m]=s[m].length();
		if(len[m]>=1000000)break;
		s[m+1]=s[m]+t[m]+s[m];
	}
	For(i,0,n){
		if(i)For(j,0,26)f[i][j]=ad(f[i-1][j],f[i-1][j]);
		inc(f[i][t[i]-'a'],1);
	}
	init();
	while(q--){
		int k;
		cin>>k>>tr+1;
		//--k;
		int l=strlen(tr+1);
		int i;
		for(i=0;i<=m;++i){
			if(len[i]>=l)break;
		}
		if(i>k){
			cout<<"0\n";
			continue;
		}
		cal(tmp,tr,l);
		int ans=0;
		For(j,l,len[i]+1)if(get(h[i],j-l+1,j)==tmp[l])++ans;
		//cerr<<i<<" "<<ans<<" "<<tmp[l]<<endl;
		ans=1ll*ans*g2[k-i]%mo;
		if(i<k){
			int ans2[26];
			memset(ans2,0,sizeof ans2);
			For(j,1,l+1){
				//cerr<<tmp[j-1]<<" "<<get(h[i],len[i]-j+2,len[i])<<" "<<get(tmp,j+1,l)<<" "<<h[i][l-j]<<endl;
				if(tmp[j-1]==get(h[i],len[i]-j+2,len[i]) && get(tmp,j+1,l) == h[i][l-j])ans2[tr[j]-'a']++;
			}
			//For(j,0,26)cerr<<ans2[j]<<" \n"[j==25];
			For(j,0,26){
				int w=f[k-1][j];
				if(i)w-=1ll*g2[k-i]*f[i-1][j]%mo;
				ans=(ans+1ll*ans2[j]*w)%mo;
			//	cerr<<w<<" \n"[j==25];
			}
			if(ans<0)ans+=mo;
		}
		cout<<ans<<"\n";
	}
}