#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<sstream>
using namespace std;
int main()
{
	int a[100];
	int n,k,ans=0,check;
	
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(i==k-1){
			check=a[i];
		}
	}
	
	for(int j=0;j<n;j++){
		if(a[j]>=check&&a[j]>0){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}