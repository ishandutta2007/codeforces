#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
typedef long double ll;
#define x first
#define y second
int n;
pair<ll,ll>a[100001];
vector<int>v;
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n ;i++) cin >> a[i].x >> a[i].y;
	sort(a+1,a+n+1);
	for(int i=1; i<=n ;i++){
		while(!v.empty() && a[v.back()].x==a[i].x) v.pop_back();
		while(v.size()>1){
			int p=v[v.size()-2],q=v.back();
			ll dx=(a[q].x-a[p].x),dy=a[q].y-a[p].y;
			ll dp=a[p].y*2*dx*2*dx-(dy-dx*dx)*(dy-dx*dx);
			ll tmp=a[i].x-a[p].x;
			ll di=a[i].y*2*dx*2*dx-(tmp*2*dx+(dy-dx*dx))*(tmp*2*dx+(dy-dx*dx));
			//cout << cx << endl;
			//cout << dp << ' ' << di << ' ' << dx << endl;
			if(di<dp) break;
			v.pop_back();
		}
		v.push_back(i);
	}
	cout << v.size()-1 << endl;
}