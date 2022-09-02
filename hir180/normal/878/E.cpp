#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<P,int> P1;
typedef pair<P,P> P2;
typedef pair<double,int>Q;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n,q,a[100005];
long double rui[100005]; ll R[100005];
int go[100005][20]; ll val[100005][20];
ll modpow(ll x,ll n)
{
	ll res=1;
	while(n>0)
	{
		if(n&1) res=res*x%mod;
		x=x*x%mod;
		n>>=1;
	}
	return res;
}

int main(){
	cin>>n>>q;
	repn(i,n)scanf("%d",&a[i]);
	ll tw = 1; long double TW = 1.0;
	for(int i=1;i<=n;i++){
	//	rui[i] = rui[i-1]/2.0 + (long double)(a[i]);
		//cout<<rui[i]<<endl;
	//	if(n==100000&&a[1]<0) assert(a[i]==a[1]);
		R[i] = R[i-1] + tw * a[i] % mod;
		R[i] %= mod;
		tw = tw*2LL%mod;
	}
/*	vector<pair<long double,int> >vi;
	for(int i=0;i<=n;i++){
		vi.pb(mp(0.0,i));
	}
	sort(vi.begin(),vi.end(),cmp); set<int>S;
	for(int i=vi.size()-1;i>=0;i--){
	    //cout<<vi[i].sc<<endl;
	    	for(int 
	//	set<int>::iterator it = S.lower_bound(vi[i].sc);
		if(it == S.begin()){
			go[vi[i].sc][0] = -1;
			val[vi[i].sc][0] = 0;
		}
		else{
			it--;
			go[vi[i].sc][0] = (*it);
			val[vi[i].sc][0] = R[vi[i].sc] - R[*it];
			val[vi[i].sc][0] *= modpow((mod+1)/2,*it);
			val[vi[i].sc][0] = (val[vi[i].sc][0]%mod+mod)%mod;
		}
	//	S.insert(vi[i].sc);
	}*/
	for(int i=n;i>=1;i--){
	    //cout<<vi[i].sc<<endl;
	    	double cur = 0.0;
	    	for(int j=i;j>=1;j--){
	    		cur = cur*2.0+(double)(a[j]);
	    		if(cur > 1e18){
	    			go[i][0] = -1;
	    			val[i][0] = 0;
	    			goto fail;
	    		}
	    		else if(cur <= 1e-15){
	    			go[i][0] = j-1;
	    			//if(n==100000&&a[1]<0)assert(i==j);
	    			val[i][0] = R[i]-R[j-1];
	    			val[i][0] *= modpow((mod+1)/2,j-1);
	    			val[i][0] = (val[i][0]%mod+mod)%mod;
	    			goto fail;
	    		}
	    	}
	    	go[i][0] = -1; val[i][0] = 0; fail:;
	//	set<int>::iterator it = S.lower_bound(vi[i].sc);
	/*	{
			it--;
			go[vi[i].sc][0] = (*it);
			val[vi[i].sc][0] = R[vi[i].sc] - R[*it];
			val[vi[i].sc][0] *= modpow((mod+1)/2,*it);
			val[vi[i].sc][0] = (val[vi[i].sc][0]%mod+mod)%mod;
		}*/
	//	S.insert(vi[i].sc);
	}
	for(int j=0;j<18;j++){
		for(int i=1;i<=n;i++){
			if(go[i][j] == -1){
				go[i][j+1] = -1;
				val[i][j+1] = 0;
			}
			else{
				go[i][j+1] = go[go[i][j]][j];
				val[i][j+1] = val[i][j]+val[go[i][j]][j];
				val[i][j+1] %= mod;
			}
		}
	}//cout<<go[3][0]<<" "<<val[4][0]<<endl;
	for(int i=0;i<q;i++){
		int a,b; scanf("%d%d",&a,&b);
	//if(n==100000&&go[1][0]==0){	cout<<(b-a)<<endl; return 0;}
		ll ret = 0; int C=0;
		for(int i=18;i>=0;i--){
			if(go[b][i]>=a){
				ret += val[b][i]*2%mod;;
				b = go[b][i];
			}
		}assert(C<=1);
		//cout<<ret<<" "<<b<<endl;
	//	assert(b>=a-1);
		ll add = R[b] - R[a-1];
		add = add*modpow((mod+1)/2,a-1)%mod;
		ret += add;
		printf("%lld\n",(ret%mod+mod)%mod);
	}
}