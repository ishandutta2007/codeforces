#include<iostream>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	long long n;
	cin >> n;
	long long a[n+1][n+1];
	long long xx,yy;
	for(long long i=1; i<=n ;i++){
		for(long long j=1; j<=n ;j++){
			cin >> a[i][j];
			if(a[i][j]==0){
				xx=i,yy=j;
			}
		}
	}
	if(n==1){
		cout << 1 << endl;
		return 0;
	}
	long long sum=0;
	long long tmp=1+(xx==1);
	for(long long i=1; i<=n ;i++){
		sum+=a[tmp][i];
	}
	bool ok=true;
	long long ans=0;
	for(long long i=1; i<=n ;i++){
		long long sum2=0;
		for(long long j=1; j<=n ;j++){
			sum2+=a[i][j];
		}
		if(xx==i){
			ans=sum-sum2;
		}
		else if(sum!=sum2){
			ok=false;
		}
	}
	for(long long i=1; i<=n ;i++){
		long long sum2=0;
		for(long long j=1; j<=n ;j++){
			sum2+=a[j][i];
		}
		if(yy==i){
			if(sum2+ans!=sum) ok=false;
		}
		else if(sum!=sum2){
			ok=false;
		}
	}
	long long sum2=0,sum3=0;
	for(long long i=1; i<=n ;i++){
		sum2+=a[i][i];
		sum3+=a[i][n+1-i];
	}
	if(xx==yy){
		if(sum2+ans!=sum) ok=false;
	}
	else{
		if(sum2!=sum) ok=false;
	}
	if(xx+yy==n+1){
		if(sum3+ans!=sum) ok=false;
	}
	else{
		if(sum3!=sum) ok=false;
	}
	if(!ok || ans<1){
		cout << -1 << endl;
		return 0;
	}
	cout << ans;
}