#include<bits/stdc++.h>
using namespace std;
int work(long long s,long long n,long long k){
    //cout << "edge: " << ((s/k+2)/2)*(s%k)+(k-s%k)*((s/k+1)/2)-(s/k)%2 << endl;
	return s >= k && (s==k || ((s/k+2)/2)*(s%k)+(k-s%k)*((s/k+1)/2)-(s/k)%2 < n);
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	int T;
	cin>>T;
	long long s,n,k;
	while(cin>>s>>n>>k){
		puts(work(s,n,k)?"YES":"NO");
	}
}