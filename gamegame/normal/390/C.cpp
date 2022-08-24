#include<iostream>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	int n,k,w,p,q;
	cin >> n >> k >> w;
	int a[n+1];
	int pre1[n+1],pre2[n+1];
	pre1[0]=pre2[0]=0;
	char temp;
	for(int i=1; i<=n ;i++){
		cin >> temp;
		a[i]=temp-48;
		if(i<=1) pre1[i]=a[i];
		else pre1[i]=pre1[i-1]+a[i];
		if(i<=k) pre2[i]=a[i];
		else pre2[i]=pre2[i-k]+a[i];
	}
	for(int i=1; i<=w ;i++){
		cin >> p >> q;
		int sum1=pre1[q]-pre1[p-1];
		int sum2=pre2[q]-pre2[p-1];
		sum1-=sum2;
		cout << sum1+(q-p+1)/k-sum2 << endl;
	}
}