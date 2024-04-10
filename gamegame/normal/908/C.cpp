#include<iostream>
#include<queue>
#include<cmath>
#include<algorithm>
#include<iomanip>
using namespace std;
typedef long long ll;
int n,r;
int x[1001];
long double ans[1001];
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> r;
	for(int i=1; i<=n ;i++){
		cin >> x[i];
		ans[i]=r;
		for(int j=1; j<i ;j++){
			if(abs(x[j]-x[i])<=2*r){
				long double height=sqrt((2*r)*(2*r)-(x[j]-x[i])*(x[j]-x[i]));
				ans[i]=max(ans[i],height+ans[j]);
			}
		}
		cout << fixed << setprecision(15) << ans[i] << ' ';
	}
	cout << endl;
}