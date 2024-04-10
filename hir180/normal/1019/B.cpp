#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
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
int n;
int main(){
	cin>>n;
	if(n%4 != 0){
		cout<<"! "<<-1<<endl;
		return 0;
	}
	cout<<"? "<<1<<endl;
	int x; cin>>x;
	cout<<"? "<<n/2+1<<endl;
	int y; cin>>y;
	if(x == y){
		cout<<"! "<<1<<endl;
		return 0;
	}
	//f(1) = x-y f(n/2+1) = y-x
	bool one = (x-y > 0);
	int lb = 1, ub = n/2+1;
	while(ub-lb > 2){
		int mid = (lb+ub)/2;
		cout<<"? "<<mid<<endl;
		int x; cin>>x;
		int midd = mid;
		midd += (n/2);
		if(midd > n) midd -= n;
		cout<<"? "<<midd<<endl;
		int y; cin>>y;
		if(x == y){
			cout<<"! "<<mid<<endl;
			return 0;
		}
		else{
			//f(mid) = x-y
			if(x-y > 0){
				if(one) lb = mid;
				else ub = mid;
			}
			else{
				if(one) ub = mid;
				else lb = mid;
			}
		}
	}
	cout<<"! "<<(lb+ub)/2<<endl;
}