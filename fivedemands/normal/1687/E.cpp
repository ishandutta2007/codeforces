#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int N=2e6+1;
const int iu=1e6;
const ll mod=998244353;
ll n;

vector<pair<int,int> >pf[iu+1];
int a[iu+1];


vector<int>cur;

vector<pair<int,pair<int,int> > > ans;
void add(int i,int j,int q){
	ans.push_back({i,{j,q}});
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n;
	for(int i=1; i<=n ;i++){
		ll x;cin >> x;
		if(x==1) continue;
		for(int j=2; j<=1000 ;j++){
			if(x%j==0){
				int pc=0;
				while(x%j==0){
					x/=j;pc++;
				}
				pf[j].push_back({pc,i});
			}
		}
		if(x!=1){
			pf[x].push_back({1,i});
		}
	}
	for(int i=1; i<=iu ;i++){
		if(pf[i].empty()) continue;
		for(auto c:pf[i]){
			a[c.se]=c.fi;
		}
		sort(pf[i].begin(),pf[i].end());
		int m1=0,m2=0;
		if(pf[i].size()==n-1) m2=pf[i][0].fi;
		if(pf[i].size()==n) m1=pf[i][0].fi,m2=pf[i][1].fi;
		int f1=0,f2=0;
		for(auto c:cur){
			if(f1==0 && a[c]==m1) f1=c;
			else if(f2==0 && a[c]==m2) f2=c;
		}
		for(int j=1; j<=n ;j++){
			if(f1 && f2) break;
			if(f1==j || f2==j) continue;
			if(f1==0 && a[j]==m1){
				cur.push_back(j);f1=j;
			}
			else if(f2==0 && a[j]==m2){
				cur.push_back(j);f2=j;
			}
		}
		for(auto c:pf[i]){
			a[c.se]=0;
		}
	}
	sort(cur.begin(),cur.end());
	int m=cur.size();
	for(int i=1; i<(1<<m) ;i++){
		int j=__builtin_popcount(i);
		int k1=(j%2==0)?-1:1;
		int k2=(j%2==1)?-(j-1):(j-1);
		int k=k1+k2;
		for(int p=0; p<k ;p++){
			add(0,j,i);
		}
		for(int p=0; p<-k ;p++){
			add(1,j,i);
		}
	}
	cout << ans.size() << '\n';
	for(auto c:ans){
		int p=c.fi,j=c.se.fi,i=c.se.se;
		cout << p << ' ' << j << ' ';
		for(int q=0; q<m ;q++) if((i>>q)&1) cout << cur[q] << ' ';
		cout << '\n';
	}
}