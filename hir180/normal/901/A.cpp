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
int n,a[200005];
int main(){
	cin>>n;
	rep(i,1+n){
		scanf("%d",&a[i]);
	}
	repn(i,n){
		if(a[i-1] >= 2 && a[i] >= 2) goto nxyy;
	}
	puts("perfect"); return 0;
	nxyy:;
	puts("ambiguous");
	cout << 0;
	int nxt = 1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<a[i];j++){
			cout << " " << nxt;
		}
		nxt += a[i];
	}
	cout << endl;
	
	cout << 0;
	nxt = 1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<a[i];j++){
			if(a[i-1]>=2 && a[i]>=2 && j>=1){
				cout << " " << nxt-1;
			}
			else{
				cout << " " << nxt;
			}
		}
		nxt += a[i];
	}
	cout << endl;
}