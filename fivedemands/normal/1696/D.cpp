#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=998244353;
const int N=2e6+1;
ll n,m,k;
int a[N],b[N];
int pn[N],px[N],sn[N],sx[N];
void solve(){
	cin >> n;
	pn[0]=sn[n+1]=n+1;
	sx[0]=sx[n+1]=0;
	int p1=0,pm=0;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
		if(a[i]==1) p1=i;
		if(a[i]==n) pm=i;
		pn[i]=min(pn[i-1],a[i]);
		px[i]=max(px[i-1],a[i]);
	}
	for(int i=n; i>=1 ;i--){
		sn[i]=min(a[i],sn[i+1]);
		sx[i]=max(a[i],sx[i+1]);
	}
	if(n==1){
		cout <<"0\n";return;
	}
	if(p1>pm){
		reverse(a+1,a+n+1);
		p1=n+1-p1;
		pm=n+1-pm;
		
	pn[0]=sn[n+1]=n+1;
	sx[0]=sx[n+1]=0;
		for(int i=1; i<=n ;i++){
			if(a[i]==1) p1=i;
			if(a[i]==n) pm=i;
			pn[i]=min(pn[i-1],a[i]);
			px[i]=max(px[i-1],a[i]);
		}
		for(int i=n; i>=1 ;i--){
			sn[i]=min(a[i],sn[i+1]);
			sx[i]=max(a[i],sx[i+1]);
		}
	}
	if(p1<pm){
		int cnt=0;
		for(int i=pm+1; i<=n ;i++){
			if(cnt%2==0 && a[i]==sn[i]) cnt++;
			else if(cnt%2==1 && a[i]==sx[i]) cnt++;
		}
		int cnt2=0;swap(cnt,cnt2);
		for(int i=p1-1; i>=1 ;i--){
			if(cnt%2==0 && a[i]==px[i]) cnt++;
			else if(cnt%2==1 && a[i]==pn[i]) cnt++;
		}
		cout << cnt+cnt2+1 << '\n';
	}
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
}