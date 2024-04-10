#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<ctime>
#include<cmath>
using namespace std;
int a[10];
int main() {
	int n,ans=0;
	cin>>n;
	for(int i=1;i<=7;i++)a[i]=n%2,n/=2;
	swap(a[1],a[5]),swap(a[3],a[4]);
	for(int i=7;i>=1;i--)ans=ans*2+a[i];
	cout<<ans;
	return 0;
}