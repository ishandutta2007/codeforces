#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
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

int n;
char a[3005][3005],b[3005][3005];
int vec[3005],nxt=1;
int bck[3005],fwd[3005];
bool f;
bool eq[3005];
ll rui[3005][2];
ll modpow(ll x,ll n){
	ll res=1;
	while(n>0){
		if(n&1) res=res*x%mod;
		x=x*x%mod;
		n>>=1;
	}
	return res;
}
int pos[3005];
bool contain(string str,int id,int st){
	//a[id] <- str?
	int m = strlen(a[id]);
/*	for(int i=0;i+str.size()-1<m;i++){
	    for(int j=0;j<str.size();j++){
	        if(a[id][i+j] != str[j]) goto nxt;
	    }
	    return true; nxt:;
	}
	return false;*/
	ll cur = 37;ll cur2 = 71;
	for(int i=0;i<m;i++){
		rui[i][0] = cur * (a[id][i]-'a'+5) % mod;
		rui[i][1] = cur2 * (a[id][i]-'a'+5) % mod;
		if(i){
		    rep(k,2) rui[i][k] = (rui[i-1][k]+rui[i][k])%mod;
		}
		cur = cur*37LL%mod;
		cur2 = cur2*71LL%mod;
	}
	ll v = 0; ll v2 = 0;
	cur = 37; cur2 = 71;
	for(int i=0;i<str.size();i++){
		v += cur * (str[i]-'a'+5)%mod;
		v2 += cur2 * (str[i]-'a'+5)%mod;
		cur = cur*37LL%mod;
		cur2 = cur2*71LL%mod;
	}
	v = (v%mod+mod)%mod;
	v2 = (v2%mod+mod)%mod;
	ll x[3005][2];
	x[0][0] = x[0][1] = 1;
	x[1][0] = modpow(37LL,mod-2);
	x[1][1] = modpow(71LL,mod-2);
	for(int i=2;i<3005;i++) rep(k,2) x[i][k] = x[i-1][k] *x[1][k] %mod;
	
	for(int beg=0;beg+str.size()-1<m;beg++){
		ll w = rui[beg+str.size()-1][0];
		ll w2 = rui[beg+str.size()-1][1];
		if(beg){
		    w -= rui[beg-1][0];
		    w2 -= rui[beg-1][1];
		}
		w *= x[beg][0];
		w %= mod;
		if(w<0) w += mod;
		w2 *= x[beg][1];
		w2 %= mod;
		if(w2<0) w2 += mod;
		if(w == v && w2 == v2){
		    if(st != beg) return true;
		    else return false;
		}
	}
	return false;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s",&a[i]);
	}
	fill(bck,bck+3005,INF);
	fill(fwd,fwd+3005,INF);
	for(int i=1;i<=n;i++){
	    scanf("%s",&b[i]);
		int mn = INF, mx = -INF;
		int m = strlen(b[i]);
		for(int j=0;j<m;j++){
			if(a[i][j] != b[i][j]){
				mn = min(mn,j);
				mx = max(mx,j);
			}
		}
		int vecc[3005],nxtt = 1;
		if(mn <= mx){
		    pos[i] = mn;
			if(!f){
				f = 1;
				for(int j=mn;j<=mx;j++){
					int x = (a[i][j]-'a')*30+(b[i][j]-'a');
					vec[nxt++] = x;
				}
				int nt=1;
				for(int x=mn-1;x>=0;x--){
					bck[nt++] = (b[i][x]-'a');
				}
				nt = 1;
				for(int x=mx+1;x<m;x++){
					fwd[nt++] = (b[i][x]-'a');
				}
			}
			else{
				for(int j=mn;j<=mx;j++){
					int x = (a[i][j]-'a')*30+(b[i][j]-'a');
					vecc[nxtt++] = x;
				}
				if(nxt != nxtt){
					puts("NO"); return 0;
				}
				for(int i=1;i<nxt;i++){
					if(vec[i] != vecc[i]){
						puts("NO"); return 0;
					}
				}
				int nt=1;
				for(int x=mn-1;x>=0;x--){
					if(bck[nt] != (b[i][x]-'a')){
						bck[nt] = INF; break;
					}
					nt++;
				}
				while(nt<3003) bck[nt++] = INF;;
				nt = 1;
				for(int x=mx+1;x<m;x++){
					if(fwd[nt] != (b[i][x]-'a')){
						fwd[nt] = INF; break;
					}
					nt++;
				}
				while(nt<3003) fwd[nt++] = INF;;
			}
		}
		else eq[i] = true;
	}
	string aa="",b="";
	int N = 0;
	for(int i=1;i<3005;i++){
		if(bck[i] == INF) break;N++;
		aa.pb(bck[i]+'a');
		b.pb(bck[i]+'a');
	}
	reverse(aa.begin(),aa.end());
	reverse(b.begin(),b.end());
	for(int i=1;i<nxt;i++){
		aa.pb( vec[i]/30+'a');
		b.pb( vec[i]%30+'a');
	}
	for(int i=1;i<3005;i++){
		if(fwd[i] == INF) break;
		aa.pb(fwd[i]+'a');
		b.pb(fwd[i]+'a');
	}
	repn(i,n){
		if(!eq[i]){
		    if(contain(aa,i,pos[i]-N)){
		        puts("NO"); return 0;
		    }
		}
		else if(contain(aa,i,-1)){
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	cout<<aa<<endl<<b<<endl;
}