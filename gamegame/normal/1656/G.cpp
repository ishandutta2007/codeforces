#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int N=2e6+1;
const ll mod=998244353;
ll n;
pair<int,int>a[N];
int e[N];
int f[N];
int k=0;//center
int b[N];
int find(int x){
	if(f[x]!=x) f[x]=find(f[x]);
	return f[x];
}
void join(int x,int y){
	x=find(x);y=find(y);
	f[x]=y;
}
void solve(){
	cin >> n;
	for(int i=1; i<=n ;i++){
		f[i]=0;b[i]=0;
	}
	for(int i=1; i<=n ;i++){
		cin >> a[i].fi;a[i].se=i;
		e[i]=a[i].fi;
		f[a[i].fi]++;
	}
	if(n==1){
		cout << "YES\n";
		cout << "1\n";
		return;
	}
	if(n%2==0){
		for(int i=1; i<=n ;i++){
			if(f[i]%2!=0){
				cout << "NO\n";
				return;
			}
		}
	}
	else{
		int cnt=0;
		for(int i=1; i<=n ;i++){
			if(f[i]%2!=0){
				cnt++;
				if(cnt>=2 || a[(n+1)/2].fi==i && f[i]==1){
					cout << "NO\n";
					return;
				}
				k=i;
			}
		}
	}
	sort(a+1,a+n+1);
	{
		if(n%2==1){
			for(int i=1; i<=n ;i++){
				if(a[i].fi==k && a[i].se!=(n+1)/2){
					b[(n+1)/2]=a[i].se;
					break;
				}
			}
		}
		
		int pi=1,pj=0;
		while(pi<=n){
			if(n%2==1 && a[pi].se==b[(n+1)/2]){
				pi++;continue;
			}
			if(n%2==1 && a[pi+1].se==b[(n+1)/2]){
				swap(a[pi],a[pi+1]);
				pi++;continue;
			}
			
			b[++pj]=a[pi].se;
			b[n+1-pj]=a[pi+1].se;
			pi+=2;
		}
	}
	for(int i=1; i<=n ;i++){
		//if(e[b[i]]!=e[b[n+1-i]]) while(true);
	}
	for(int i=1; i<=n ;i++) f[i]=i;
	for(int i=1; i<=n ;i++) join(i,b[i]);
	for(int i=1; i<=n/2 ;i++){
		if(find(i)!=find(n+1-i)){
			swap(b[i],b[n+1-i]);
			join(i,n+1-i);
		}
		if(find(i)!=find(1)){
			swap(b[i],b[1]);
			swap(b[i],b[n+1-i]);
			swap(b[i],b[n]);
			
			join(1,i);
		}
	}
	cout << "YES\n";
	for(int i=1; i<=n ;i++){
		cout << b[i] << ' ';
	}
	cout << '\n';
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
}