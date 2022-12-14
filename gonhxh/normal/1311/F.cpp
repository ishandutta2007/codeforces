#include <bits/stdc++.h>
#define int long long
#define ld long double
#define endl "\n"
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a,b)
#define ms(v,x) memset(v,x,sizeof(v))
#define ff first
#define ss second
#define rep(i,l,r) for(int i = (int)l;i<(int)r;i++)
#define td(v) v.begin(),v.end()
#define M   1000000007 // 1e9 + 7
#define MAXN 200100
using namespace std;
typedef pair<int,int> pii;
inline int mod(int n, int m){ int ret = n%m; if(ret < 0) ret += m; return ret; }
int gcd(int a, int b){return (b == 0 ? a : gcd(b, a%b));}
int exp(int a,int b,int m){
    if(b==0) return 1;
    if(b==1) return mod(a,m);
    int k = mod(exp(a,b/2,m),m);
    if(b&1){
        return mod(a*mod(k*k,m),m);
    }
    else return mod(k*k,m);
}

vector<int> L,R;

struct BIT{
 int n;
 int MAX;
 vector<int> bit;
 BIT(){}
 BIT(int _n){
	 n = _n;
	 MAX = n +2;
	 bit.resize(n+10,0);
 }
 
 int query(int x){
	 int r=0;
	 while(x>0){
		 r+=bit[x];
		 x-=(x&-x);
	 }
	 return r;
 }
 
 int query(int l,int r){
	 return query(r) - query(l-1);
 }
 
 void update(int x,int val){
	 while(x<MAX){
		 bit[x]+=val;
		 x+=(x&-x);
	 }
 }
 
 int find_kth(int k){
	 int sum=0;
	 int pos=0;
	 // 30 == log -> trocar conforme necessario
	 for(int i=30;i>=0;i--){
		 if(pos+(1LL<<i)>n)continue;
		 int atual = bit[pos+(1LL<<i)];
		 if(sum+atual<k){
			 sum+=atual;
			 pos+=(1LL<<i);
		 }
		 
	 }
	 
	 //acha a maior pos com <k;
	 return pos+1;
 }
 	
};

pii x[MAXN];
int32_t main(){
	fastio;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i].ff;
	}
	map<int,int> mp;
	for(int j=1;j<=n;j++){
		cin>>x[j].ss;
		mp[x[j].ss];
	}
	int k=0;
	for(map<int,int>::iterator it =mp.begin();it!=mp.end();it++){
		it->second = ++k;
	}
	BIT T(n+10);//sum
	BIT T2(n+10);//qtd
	int sum=0;
	int qtd=0;
	int ans=0;
	sort(x+1,x+1+n);
	for(int i=n;i>=1;i--){
		int cord = x[i].ff;
		int v = mp[x[i].ss];
		
		if(v<=0){
			qtd = T2.query(v,n);
			sum = T.query(v,n);
			ans+=sum - qtd*cord;
		}else{
			qtd = T2.query(v,n);
			sum = T.query(v,n);
			ans+=sum - qtd*cord;
		}
		T.update(v,cord);
		T2.update(v,1);
	}
	cout<<ans<<endl;
	
	
}