#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
int n,m;
ll p[100001];
int dpn[512];
pair<int,int>pz[512],pz2[512];
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i=1; i<=n ;i++){
		int a;cin >> a;
		int x=0;
		for(int j=0; j<a ;j++){
			int k;cin >> k;x|=(1<<k);
		}
		x>>=1;
		dpn[x]++;
	}
	for(int i=0; i<9 ;i++){
		for(int j=0; j<512 ;j++){
			if(j&(1<<i)) dpn[j]+=dpn[j^(1<<i)];
		}
	}
	for(int i=0; i<512 ;i++) pz[i].fi=pz2[i].fi=-1.0011e9;
	for(int i=1; i<=m ;i++){
		cin >> p[i];p[i]=-p[i];
		int a;cin >> a;
		int x=0;
		for(int j=0; j<a ;j++){
			int k;cin >> k;x|=(1<<k);
		}
		x>>=1;
		if(p[i]>pz2[x].fi) pz2[x]={p[i],i};
		if(pz2[x].fi>pz[x].fi) swap(pz[x],pz2[x]);
	}
	//for(int i=0; i<512 ;i++) cout << pz[i].fi << '\n';
	pair<int,int>ans={0,-2.0033e9};
	pair<int,int>out={0,0};
	for(int i=0; i<512 ;i++){
		for(int j=0; j<512 ;j++){
			pair<int,int>cur={dpn[i|j],pz[i].fi+((i==j)?pz2[j].fi:pz[j].fi)};
			pair<int,int>jj={pz[i].se,((i==j)?pz2[j].se:pz[j].se)};
			if(cur>ans && jj.fi!=0 && jj.se!=0) out=jj,ans=cur;
		}
	}
	cout << out.fi << ' ' << out.se << endl;
}