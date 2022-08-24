#include<iostream>
#include<vector>
using namespace std;
vector<int>a,b,c,d;
int main(){
	ios::sync_with_stdio(false);
	a.push_back(1);
	b.push_back(2);
	c.push_back(3);
	d.push_back(0);
	int n;
	cin >> n;
	for(int i=4; i<=n ;i++){
		for(int j=1; j<i-3 ;j+=2){
			a.push_back(j);
			b.push_back(i);
			c.push_back(j+1);
			d.push_back(i-1);
		}
		if(i%2==1){
			a.push_back(i-3);
			b.push_back(i-2);
			c.push_back(i);
			d.push_back(i-1);
		}
		else{
			a.push_back(i-3);
			b.push_back(i-1);
			c.push_back(i);
			d.push_back(0);
		}
	}
	cout << (n)/2+a.size() << endl;
	for(int i=1; i<n-2 ;i+=2){
		cout << 3 << ' ' << i << ' ' << i+1 << ' ' << n << '\n';
	}
	cout << 3 << ' ' << n-2 << ' ' << n-1 << ' ' << n << '\n';
	for(int i=0; i<a.size() ;i++){
		if(d[i]==0) cout << 3 << ' ';
		else cout << 4 << ' ';
		cout << a[i] << ' ' << b[i] << ' ' << c[i];
		if(d[i]!=0) cout << ' ' << d[i];
		cout << '\n';
	}
}