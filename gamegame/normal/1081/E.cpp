#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;
int n;
ll x[100001];
ll sum=0;
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=2; i<=n ;i+=2){
		cin >> x[i];
		int mid=sqrt(x[i]);
		bool ok=false;
		for(int j=mid; j>=1 ;j--){
			if(x[i]%j!=0) continue;
			if(j%2!=x[i]/j%2) continue;
			ll s=(x[i]/j-j)/2;
			ll b=(x[i]/j+j)/2;;
			if(s>=b) continue;
			if(s*s<=sum) continue;
			x[i-1]=s*s-sum;
			ok=true;
			sum=b*b;
			break;
		}
		if(!ok){
			cout << "No\n";
			return 0;
		}
	}
	cout << "Yes\n";
	for(int i=1; i<=n ;i++) cout << x[i] << ' ';
	cout << endl;
}