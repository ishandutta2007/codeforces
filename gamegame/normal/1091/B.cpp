#include<iostream>
#include<set>
using namespace std;
set<pair<int,int> >s;
int x[1001],y[1001];
int a[1001],b[1001];
int n;
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n ;i++) cin >> x[i] >> y[i];
	for(int i=1; i<=n ;i++){
		cin >> a[i] >> b[i];
		s.insert({a[i],b[i]});
	}
	for(int i=1; i<=n ;i++){
		int ax=x[1]+a[i],ay=y[1]+b[i];
		bool ok=true;
		for(int j=1; j<=n ;j++){
			int cx=ax-x[j];
			int cy=ay-y[j];
			auto it=s.lower_bound({cx,cy});
			if(it==s.end() || (*it)!=(pair<int,int>){cx,cy}){
				ok=false;
				break;
			}
		}
		if(ok){
			cout << ax << ' ' << ay << endl;
			return 0;
		}
	}
}