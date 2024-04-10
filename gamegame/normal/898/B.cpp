#include<iostream>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
long long n,a,b;
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> a >> b;
	for(int i=0; i<b ;i++){
		if(n-a*i>=0 && (n-a*i)%b==0){
			cout << "YES\n" << i << ' ' << (n-a*i)/b << endl;
			return 0;
		}
	}
	cout << "NO\n";
}