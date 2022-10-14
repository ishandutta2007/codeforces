//author: dmk
#include <bits/stdc++.h>

using namespace std;
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	long long n, m, k;
	cin>>n>>m>>k;
	if (k<n) cout<<k+1<<" "<<1;
	else {
		long long s=k-n, w=m-1;
		if ((s/w)%2==0) cout<<n-s/w<<" "<<2+s%w;
		else cout<<n-s/w<<" "<<m-s%w;
	}
}