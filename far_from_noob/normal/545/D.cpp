#include <iostream>
using namespace std;
#include<bits/stdc++.h>
int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort (a,a+n);
    int count=0,i,countans=0;;
    for(i=0;i<n;i++){
        if(count<=a[i]){
        count+=a[i];
        countans++;
        }
    }
    cout<< countans;
	return 0;
}