#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define R(x) cin>>x
using namespace std;
int a[200],b[200];
bitset<10005> dp[10001];
int main(){
	int t;
	int n,k;
	cin>>n>>k;
	rb(i,1,n) scanf("%d",&a[i]);
	rb(i,1,n) scanf("%d",&b[i]);
	int sum=0;
	dp[0].set(0);
	rb(i,1,n){
		sum+=a[i];
		rl(j,sum,a[i]){
			dp[j]|=dp[j-a[i]]<<b[i];
		}
	}
	rl(i,10000,1){
		if(i%k==0){
			if(dp[i][i/k]==1){
				cout<<i<<endl;
				return 0;
			}
		}
	}
	cout<<-1<<endl;
	return 0;
}