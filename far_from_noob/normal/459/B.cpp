
 #include <iostream>
using namespace std;
#include <bits/stdc++.h>
int main() {
	int n;
	cin >> n;
	int b[n];
	for (int i=0;i<n;i++){
	    cin >>b[i];
	}
	sort(b,b+n);
	cout << b[n-1]-b[0]<<endl;
	int count1=0,count2=0;
	for(int i=0;i<n-1;i++){
	    if(b[i]==b[0]){
	        count1++;
	    }
	    else break;
	}
	for(int i=n-1;i>0;i--){
	    if(b[i]==b[n-1]){
	        count2++;
	    }
	    else break;
	}
	if(b[0]!=b[n-1])
	cout << (long long)count1*count2;
	else cout << (long long)n*(n-1)/2;
	return 0;
}