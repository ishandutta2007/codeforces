#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;
const int N=1e6+1;
int main(){
	ios::sync_with_stdio(false);
	int n,k;
	cin >> n >> k;
	int len=(n-1)/k;
	int dd=(n-1)%k;
	if(dd==1) cout << 2*len+1 << endl;
	else if(dd==0) cout << 2*len << endl;
	else cout << 2*len+2 << endl;
	stack<int>s;
	for(int i=k+2; i<=n ;i++) s.push(i);
	for(int i=0; i<k ;i++){
		int cur=len;
		if(i<dd){
			cur=len+1;
		}
		int c=1;
		for(int j=0; j<cur-1 ;j++){
			cout << c << ' ' << s.top() << '\n';
			c=s.top();
			s.pop();
		}
		cout << c << ' ' << i+2 << '\n';
	}
	
}