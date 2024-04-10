#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;
ll n,a,b;
int p[100001];
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;
	while(t--){
		cin >> n >> a >> b;
		
		for(int i=1; i<=n ;i++) p[i]=i;
		if(abs(a-b)>1 || a+b>n-2){
			cout << "-1\n";
			continue;
		}
		if(a==b){
			for(int i=1; i<=a ;i++){
				swap(p[2*i],p[2*i+1]);
			}
		}
		else if(a<b){
			for(int i=1; i<=b ;i++){
				swap(p[2*i-1],p[2*i]);
			}
		}
		else{
			for(int i=1; i<=a ;i++){
				swap(p[n-2*i+2],p[n-2*i+1]);
			}
		}
		for(int i=1; i<=n ;i++) cout << p[i] << ' ';
		cout << '\n';
	}
}