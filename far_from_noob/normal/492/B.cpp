#include <iostream>
using namespace std;
#include <bits/stdc++.h>
int main() {
	int n;
	double l;
	cin >> n >> l;
	double a[n];
	for(int i =0;i<n;i++)
	{
	    cin >>a[i];
	}
	sort(a,a+n);
	double currentmax=0,temp;
	for(int i=0;i<n-1;i++){
	    if((a[i+1]-a[i])/2 > currentmax)
	    currentmax=(a[i+1]-a[i])/2;
	}
	if (currentmax>a[0]-0)
	temp=currentmax;
	else temp=a[0]-0;
	if(temp>l-a[n-1])
	printf("%.9lf",temp);
	else printf("%.9lf",l-a[n-1]); 
	return 0;
}