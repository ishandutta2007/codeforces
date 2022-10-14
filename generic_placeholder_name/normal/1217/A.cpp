#include<bits/stdc++.h>

#define ll long long

using namespace std;
int main(){
	int q; cin>>q; for(int l=1; l<=q; l++) {
		int s, i, n; cin>>s>>i>>n; cout<<max(n-max((int)floor((double)(n+i-s)/2), -1), 0)<<endl;
	}
}