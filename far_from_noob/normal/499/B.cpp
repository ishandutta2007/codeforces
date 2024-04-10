#include <iostream>
using namespace std;
#include<bits/stdc++.h>
int main() {
	int n,m;
	cin >> n>> m;
	string a[m],b[m];
	for (int i=0;i<m;i++){
	    cin >> a[i]>> b[i];
	}
	string words[n];
	for(int i=0;i<n;i++)
	{
	    cin >> words[i];
	}
	for(int i=0;i<n;i++){
	    int temp;
	    for(int j=0;j<m;j++){
	        if(a[j]==words[i]){
	        temp=j;
	        break;
	        }
	    }
	    //int x=strlen(a[temp],y=strlen(b[temp]);
	    if(a[temp].size()<=b[temp].size())
	    cout << a[temp]<< " ";
	    else cout << b[temp]<<" ";
	}
	return 0;
}