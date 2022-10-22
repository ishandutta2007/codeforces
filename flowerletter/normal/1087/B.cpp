#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
signed main(){
	int x,n,k,Min=1000000100ll;
	cin>>n>>k;
	for(int i=1;i<k;i++){
		if(n%i==0){
			int t=n/i;
			int x=t*k+i;
			Min=min(Min,x);
		}
	}
	cout<<Min;
	return 0;
}