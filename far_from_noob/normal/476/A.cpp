#include <iostream>
using namespace std;
#include<bits/stdc++.h>
int main() {
    int n,m;
    cin>>n>>m;
    int min=0;
    if(n%2==0)min=n/2;
    else min=n/2 +1;
    int ans;
    if(m>n)ans=-1;
    
    else if(min%m==0)ans=min;
    else ans=min/m*  (m) +m;
    cout<<ans;
	return 0;
}