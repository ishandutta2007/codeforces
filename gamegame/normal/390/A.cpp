#include<iostream>
using namespace std;
bool a[101],b[101];
int sum1,sum2;
int main(){
	ios::sync_with_stdio(false);
	int n,p,q;
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> p >> q;
		a[p]=true;b[q]=true;
	}
	for(int i=0; i<=100 ;i++){
		sum1+=a[i];
		sum2+=b[i];
	}
	cout << min(sum1,sum2) << endl;
}