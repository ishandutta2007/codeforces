#include<bits/stdc++.h>
using namespace std;
typedef array<int,19> a19;
#define fi first
#define se second
string s[2]={"Fou","Shi"};
int k=19;
int a[300001];
int n,q;
a19 mi[19];
a19 god,zero;
vector<pair<int,int> >qr[300001];
int out[300001];
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> q;
	for(int i=1; i<=n ;i++) cin >> a[i];
	for(int i=1; i<=q ;i++){
		int l,r;cin >> l >> r;
		qr[r].push_back({l,i});
	}
	for(int i=1; i<=n ;i++){
		god=zero;
		for(int j=0; j<19 ;j++){
			if(a[i]&(1<<j)){
				for(int k=0; k<19 ;k++){
					god[k]=max(mi[j][k],god[k]);
				}
				god[j]=i;
			}
		}
		for(int j=0; j<19 ;j++){
			if(a[i]&(1<<j)) mi[j]=god;
		}
		for(auto cur:qr[i]){
			int l=cur.fi,r=i;
			int duh=19;
			for(int j=0; j<19 ;j++) if(a[r]&(1<<j)) duh=j;
			bool ans=false;
			if(duh!=19){
				for(int j=0; j<19 ;j++) if(a[l]&(1<<j)) ans|=(mi[duh][j]>=l);
			}
			out[cur.se]=ans;
		}
	}
	for(int i=1; i<=q ;i++) cout << s[out[i]] << '\n';
}