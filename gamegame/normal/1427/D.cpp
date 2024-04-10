#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;
const int N=2e6+1;
int n;
int p[N];
vector<vector<int> >ans;
void ask(vector<int>v){
	vector<int>v2;
	for(auto c:v) if(c!=0) v2.push_back(c);
	if(v2.size()<=1) return;
	ans.push_back(v2);
	/*cout << v2.size() << ' ';
	for(auto c:v2) cout << c << ' ';
	cout << endl;*/
}
void sim(vector<int>v){
	int cur=n;
	vector<int>v2;
	reverse(v.begin(),v.end());
	for(auto c:v){
		for(int i=cur-c+1; i<=cur ;i++){
			v2.push_back(p[i]);
		}
		cur-=c;
	}
	for(int i=1; i<=n ;i++){
		p[i]=v2[i-1];
	}
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> p[i];
	}
	for(int i=n; i>=1 ;i--){
		//cout << "doing " << i << endl;
		bool f=(i%2==0);
		if(f){
			int pos=0;
			for(int j=1; j<=n ;j++){
				if(p[j]==i) pos=j;
			}
			vector<int>qr;
			for(int j=1; j<=n-i ;j++) qr.push_back(1);
			qr.push_back(i-pos+1);
			qr.push_back(pos-1);
			reverse(qr.begin(),qr.end());
			ask(qr);
			sim(qr);
		}
		else{
			int pos=0;
			for(int j=1; j<=n ;j++){
				if(p[j]==i) pos=j;
			}
			vector<int>qr;
			
			qr.push_back(n-pos);
			qr.push_back(pos-(n-i));
			for(int j=1; j<=n-i ;j++) qr.push_back(1);
			reverse(qr.begin(),qr.end());
			ask(qr);
			sim(qr);
		}
		//cout << "p: ";
		//for(int j=1; j<=n ;j++) cout << p[j] << ' ';
		//cout << endl;
	}
	cout << ans.size() << '\n';
	for(auto c:ans){
		cout << c.size() << ' ';
		for(auto d:c){
			cout << d << ' ';
		}
		cout << '\n';
	}
}