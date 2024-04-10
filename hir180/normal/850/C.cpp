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
map<int,int>M;
int calc(int hoge){
	if(hoge == 0) return 0;
	if(M.find(hoge) != M.end()) return M[hoge];
	set<int>S;
	for(int i=29;i>=1;i--){
		int nxt = 0;
		for(int j=29;j>=0;j--){
			if(((hoge>>j)&1)){
				if(j>=i) nxt|=(1<<(j-i));
				else nxt|=(1<<j);
			}
		}
		if(hoge==nxt) continue;
		S.insert(calc(nxt));
	}
	for(int i=0;;i++) if(S.find(i)==S.end()) return M[hoge]=i;
}
map<int,int>hoge;
int main(){
	int n; cin >> n;
	int a[105];
	rep(i,n){
		cin>>a[i];
		for(int j=2;j*j<=a[i];j++){
			if(a[i]%j==0){
				int cnt = 0;
				while(a[i]%j==0) a[i]/=j,cnt++;
				hoge[j]|=(1<<cnt);
			}
		}
		if(a[i]!=1) hoge[a[i]]|=2;
	}
	int ans = 0;
	for(map<int,int>::iterator it = hoge.begin(); it != hoge.end(); it++){
	//cout<<it->sc<<endl;
		ans ^= calc(it->sc);
	}
	cout<< (ans?"Mojtaba":"Arpa") << endl;
}