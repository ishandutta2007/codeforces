#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	int n;
	long long l;
	cin >> n >> l;
	double a[n+1];
	for(int i=1; i<=n ;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	double maxi=0;
	maxi=max(maxi,a[1]*2);
	maxi=max(maxi,(l-a[n])*2);
	for(int i=2; i<=n ;i++){
		maxi=max(maxi,a[i]-a[i-1]);
	}
	printf("%.10lf\n",maxi/2);
}