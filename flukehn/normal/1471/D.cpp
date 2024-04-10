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
template<typename T>T gcd(T a,T b){while(b)a%=b,swap(a,b);return a;}
const int N=1e6+11;
int np[N],p[N],mn[N],tot;
int a[N],b[N],c[N],n;
int ans[5];
int main(){
#ifdef SGR
	freopen("a.txt","r",stdin);
#endif
	ios::sync_with_stdio(0);
	For(i,2,N){
		if(!np[i]){
			p[tot++]=i;
			mn[i]=i;
		}
		for(int j=0,k;j<tot&&(k=i*p[j])<N;++j){
			np[k]=1;
			mn[k]=p[j];
			if(i%p[j]==0)break;
		}
	}
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		For(i,0,n){
			cin>>a[i];
			//cerr<<a[i]<<" ";
			int x=a[i];
			while(x>1){
				int y=mn[x];
				//cerr<<x<<" "<<y<<" "<<a[i]<<endl;
				while(a[i]%y==0&&a[i]/y%y==0)a[i]/=y*y;
				//cerr<<x<<" md "<<y<<endl;
				while(x%y==0)x/=y;
				//cerr<<x<<" mlgb "<<y<<endl;
			}
			//cerr<<a[i]<<endl;
		}
		sort(a,a+n);
		//For(i,0,n)cerr<<a[i]<<" \n"[i==n-1];
		memset(ans,0,sizeof ans);
		//cerr<<"ok\n";
		int now=1;
		ans[0]=1;
		For(i,1,n){
			if(a[i]==a[i-1])++now;
			else now=1;
			ans[0]=max(ans[0],now);
		}
		for(int i=0,j;i<n;i=j){
			//cerr<<i<<endl;
			for(j=i;j<n&&a[j]==a[i];++j);
			if((j-i)%2==0||a[i]==1)ans[1]+=j-i;
		}
		ans[1]=max(ans[1],ans[0]);
		int q;
		cin>>q;
		while(q--){
			ll w;
			cin>>w;
			if(w>1)w=1;
			cout<<ans[w]<<"\n";
		}
	}
}