#include<iostream>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;
int gcd(int a,int b){
	while(b!=0 && a%b!=0){
        a=a%b;
        b=b%a;
    }
    if(b==0){
        b=a;
    }
    return b;
}
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int a[n+1];
	for(int i=1; i<=n ;i++){
		cin >> a[i];
	}
	queue<int>ans;
	int k=0;
	for(int i=1; i<=n-1 ;i++){
		if(gcd(a[i],a[i+1])==1){
			ans.push(a[i]);
		}
		else{
			ans.push(a[i]);
			ans.push(1);
			k++;
		}
	}
	cout << k << endl;
	while(!ans.empty()){
		cout << ans.front() << ' ';
		ans.pop();
	}
	cout << a[n] << endl;
}