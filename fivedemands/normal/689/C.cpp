#include<iostream>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	long long m;
	cin >> m;
	long long l=1,r=8*m,mid;
	while(l!=r){
		mid=(l+r)/2;
		long long num;
		long long cnt=0;
		for(long long i=2; i<=1000000 ;i++){
			num=mid;
			for(int j=0; j<3 ;j++) num/=i;
			cnt+=num;
			cnt=min(cnt,m+1);
		}
		if(cnt<m){
			l=mid+1;
		}
		else{
			r=mid;
		}
	}
	long long cnt=0;
	for(long long i=2; i<=1000000 ;i++){
		long long num=l;
		for(int j=0; j<3 ;j++) num/=i;
		cnt+=num;cnt=min(cnt,m+1);
	}
	if(cnt==m) cout << l << endl;
	else cout << -1 << endl;
}