#include<iostream>
#include<map>
using namespace std;
typedef long long ll;
ll ans=0;
int n;
map<int,int>m;
int main(){
	cin >> n;
	for(int i=1; i<=n ;i++){
		int a,x;
		cin >> a >> x;
		m[a]=max(m[a],x);
	}
	cin >> n;
	for(int i=1; i<=n ;i++){
		int a,x;
		cin >> a >> x;
		m[a]=max(m[a],x);
	}
	for(auto it=m.begin(); it!=m.end() ;++it){
		ans+=it->second;
	}
	cout << ans << endl;
}