#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const int N=1e5+1;
const int arin=1e6+1;
const int iu=1e6;
int n,q;
string s[21];
typedef array<ll,4> hsh;
hsh md,bs;
hsh pb[arin];
vector<hsh>vsi[21];
vector<hsh>vqr;
char t[N];
int pf[26][N];
int pw=0;
int z;
string qr;
ll p2[arin];
void build(string& s,vector<hsh>& v){
	v.resize(s.size()+1);
	v[0]={0,0,0,0};
	for(int i=0; i<s.size() ;i++){
		for(int j=0; j<4 ;j++){
			v[i+1][j]=(v[i][j]*bs[j]+s[i])%md[j];
		}
	}
}
hsh gsh(int i,int l,int r){
	r++;
	hsh ans;
	for(int j=0; j<4 ;j++){
		ans[j]=vsi[i][r][j]-vsi[i][l][j]*pb[r-l][j];
		ans[j]=(ans[j]%md[j]+md[j])%md[j];
	}
	return ans;
}
hsh gqh(int l,int r){
	r++;
	hsh ans;
	for(int j=0; j<4 ;j++){
		ans[j]=vqr[r][j]-vqr[l][j]*pb[r-l][j];
		ans[j]=(ans[j]%md[j]+md[j])%md[j];
	}
	return ans;
}
ll solve(){
	cin >> z >> qr;
	build(qr,vqr);
	int cp=0;
	while(s[cp].size()<qr.size()) cp++;
	if(z<cp) return 0;
	int qz=qr.size();
	int sz=s[cp].size();
	ll ans=0;
	for(int i=0; i<=sz ;i++){
		if(i+qz<=sz){
			bool ok=gsh(cp,i,i+qz-1)==gqh(0,qz-1);
			//cout << i << ' ' << ok << endl;
			if(ok) ans=(ans+p2[z-cp])%mod;
		}
		else{
			bool ok1=gsh(cp,i,sz-1)==gqh(0,sz-1-i);
			bool ok2=gsh(cp,0,qz-3-(sz-1-i))==gqh(sz-1-i+2,qz-1);
			//cout << i << ' ' << ok1 << ' ' << ok2 << endl;
			int c=qr[sz-i]-'a';
			ll ways=pf[c][z]-pf[c][cp]*p2[z-cp];
			ways=((ways%mod)+mod)%mod;
			if(ok1 && ok2) ans=(ans+ways)%mod;
		}
	}
	return ans;
}
void apple(){
	p2[0]=1;
	for(int i=1; i<=iu ;i++) p2[i]=p2[i-1]*2%mod;
	bs={391,392,393,394};
	md={(ll)1e9+7,(ll)1e9+9,998244353,998244853};
	pb[0]={1,1,1,1};
	for(int i=1; i<=iu ;i++){
		for(int j=0; j<4 ;j++){
			pb[i][j]=pb[i-1][j]*bs[j]%md[j];
		}
	}
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);apple();
	cin >> n >> q;
	cin >> s[0];
	for(int i=1; i<=n ;i++){
		cin >> t[i];
		for(int j=0; j<26 ;j++) pf[j][i]=pf[j][i-1]*2%mod;
		pf[t[i]-'a'][i]++;
	}
	while(s[pw].size()<=1000000){
		pw++;
		s[pw]=s[pw-1]+t[pw]+s[pw-1];
	}
	for(int i=0; i<=pw ;i++) build(s[i],vsi[i]);
	while(q--) cout << solve() << '\n';
}