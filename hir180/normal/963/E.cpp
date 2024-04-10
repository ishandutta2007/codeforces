#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
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
int mat[7905][7905],vecr[7905];
ll R,n,p[4];
ll modpow(ll x,ll n){
    x = (x%mod+mod)%mod;
	ll res=1;
	while(n>0){
		if(n&1) res=res*x%mod;
		x=x*x%mod;
		n>>=1;
	}
	return res;
}
//O(N^2+NB^2)
//mat and vecr must be defined
vector<ll> gauss_band(int B){
	//mat[i][j] == 0 if abs(i-j) > B
	for(int j=0;j<n;j++){
		int pivot=-1;
		for(int i=j;i<min((int)n,j+B+3);i++){
			if(mat[i][j]){
				pivot = i; break;
			}
		}
		if(pivot == -1) continue;
		for(int g=j;g<min((int)n,j+2*B+3);g++) swap(mat[j][g],mat[pivot][g]);
		swap(vecr[j],vecr[pivot]);
		ll rev = modpow(1LL*mat[j][j],mod-2);
		int en = -1;
		for(int i=min((int)n,j+2*B+3)-1;i>=j;i--) if(mat[j][i]){
			en = i;
			break;
		}
		assert(en>=j);
		for(int i=j+1;i<min((int)n,j+B+3);i++){
			if(mat[i][j]){
				ll gg = 1LL*mat[i][j]*rev%mod;
				vecr[i] -= 1LL*vecr[j]*gg%mod;
				if(vecr[i]<0) vecr[i]+=mod;
				for(int g=j;g<=en;g++){
					mat[i][g] -= 1LL*mat[j][g]*gg%mod;
					if(mat[i][g]<0) mat[i][g]+=mod;
				}
			}
		}
	}
	for(int i=n-1;i>=0;i--){
		if(mat[i][i] == 0) continue;
		ll rev = modpow(1LL*mat[i][i],mod-2);
		for(int j=i-1;j>=max(0,i-2*B-3);j--){
			if(mat[j][i]){
				vecr[j] -= 1LL*vecr[i]*rev%mod*mat[j][i]%mod;
				if(vecr[j]<0) vecr[j]+=mod;
				mat[j][i] = 0;
			}
		}
	}
	vector<ll>ans;
	for(int i=0;i<n;i++) ans.pb((1LL*vecr[i]%mod+mod)%mod*modpow(1LL*mat[i][i],mod-2)%mod);
	return ans;
}
int target,nxt;
map<P,int>M;
vector<P>vec;
int main(){
	cin>>R>>p[0]>>p[1]>>p[2]>>p[3];
	ll rev = modpow(p[0]+p[1]+p[2]+p[3],mod-2);
	rep(h,4) p[h]=p[h]*rev%mod;
	for(int i=-R;i<=R;i++) for(int j=-R;j<=R;j++){
		if(i*i+j*j <= R*R){
			vec.pb(mp(i,j));
			M[mp(i,j)] = vec.size()-1;
			if(i==0 && j==0) target = vec.size()-1;
		}
	}
	n = vec.size();
	int dx[4]={-1,0,1,0};
	int dy[4]={0,-1,0,1};
	for(int i=-R;i<=R;i++) for(int j=-R;j<=R;j++){
		if(i*i+j*j <= R*R){
			rep(k,4){
				int nx=i+dx[k],ny=j+dy[k];
				if(nx*nx+ny*ny<=R*R){
					mat[M[mp(i,j)]][M[mp(nx,ny)]] = mod-p[k];
				}
			}
			mat[M[mp(i,j)]][M[mp(i,j)]] = 1;
			vecr[M[mp(i,j)]] = 1;
		}
	}
	vector<ll>ret = gauss_band(105);
	cout << ret[target] << endl;
}