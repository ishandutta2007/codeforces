#include<iostream>
#include<cmath>
using namespace std;
long long p2[100001];
int c[100001];
bool p[100001];
int cnt[100001];
int n,q;
long long mod(long long m){
	return m%1000000007;
}
int main(){
	ios::sync_with_stdio(false);
	p2[0]=1;
	for(int i=1; i<=100000 ;i++){
		p2[i]=mod(p2[i-1]*2);
		c[i]=1;
		p[i]=true;
	}
	for(int i=2; i<=100000 ;i++){
		for(int j=2; j<=316 ;j++){
			if(i%(j*j)==0){
				c[i]=0;
				break;
			}
		}
		if(!p[i]) continue;
		for(int j=i; j<=100000 ;j+=i){
			p[j]=false;
			c[j]=-c[j];
		}
	}
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> q;
		for(int j=1; j<=sqrt(q) ;j++){
			if(q%j!=0) continue;
			cnt[j]++;
			if(j*j==q) break;
			cnt[q/j]++;
		}
	}
	long long ans=0;
	for(int i=1; i<=100000 ;i++){
		ans=mod(ans+c[i]*(p2[cnt[i]]-1)+1000000007);
	}
	cout << ans << endl;
}