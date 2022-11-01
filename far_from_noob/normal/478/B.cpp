#include <iostream>
using namespace std;
#include<bits/stdc++.h>
int main() {
    long long n,m;
    cin  >> n >> m;
    long long  temp=n/m,temp2=n%m;
    cout << temp2*temp*(temp+1)/2+(m-temp2)*temp*(temp-1)/2<< " "<< (n-m+1)*(n-m)/2;
	return 0;
}