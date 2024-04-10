#include<iostream>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int a[n+1];
	bool isprime[2000001];
	for(int i=2; i<=2000000 ;i++) isprime[i]=true;
	for(int i=2; i<=1414 ;i++)
		if(isprime[i])
			for(int j=i*i; j<=2000000 ;j+=i) isprime[j]=false;
	int even=0,odd=0,onec=0,one=0;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
		onec+=(a[i]==1);
		if(isprime[a[i]+1] && a[i]!=1) one=a[i];
	}
	for(int i=1; i<=n ;i++){
		if(a[i]==1) continue;
		for(int j=1; j<=n ;j++)
			if((a[i]&1) && !(a[j]&1) && isprime[a[i]+a[j]]){ even=a[j]; odd=a[i];}
	}
	if(onec>=2 || onec==1 && one!=0){
		cout << onec+(one!=0) << endl;
		for(int i=0; i<onec ;i++) cout << 1 << ' ';
		if(one!=0) cout << one;
	}
	else if(even!=0 && odd!=0) cout << 2 << endl << even << ' ' << odd;
	else cout << 1 << endl << a[1];
}