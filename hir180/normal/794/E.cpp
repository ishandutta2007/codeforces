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
int a[300005],n;
set<P>e,o;
int mx;
int main(){
	cin>>n;
	rep(i,n) cin>>a[i],mx=max(mx,a[i]);
	for(int i=0;i<n;i++){
	    if(i==n-1){
	        cout << mx << endl;
	        return 0;
	    }
		int x = n-i;
		if(x%2 == 0){
			int m = x/2;
			if(m-1 >= 0) e.insert(mp(a[m-1],m-1));
			e.insert(mp(a[m],m));
			if(m != 0) e.insert(mp(a[n-m],n-m));
			if(n-m-1 >= 0) e.insert(mp(a[n-m-1],n-m-1));
			set<P>::iterator it = e.end();
			it--;
			cout << (*it).fi << " ";
		}
		else{
			int m = (x-1)/2;
			if(m-1>=0 && m+1<n) o.insert(mp(max(min(a[m-1],a[m]),min(a[m],a[m+1])),m));
			if(n-m<n && n-m-2>=0) o.insert(mp(max(min(a[n-m],a[n-m-1]),min(a[n-m-1],a[n-m-2])),n-m-1));
			set<P>::iterator it = o.end();
			it--;
			cout << (*it).fi << " ";
		}
	}
}