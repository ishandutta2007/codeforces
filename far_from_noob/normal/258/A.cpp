#include <iostream>
using namespace std;
#include<bits/stdc++.h>
int main() {
    string s;
    cin>>s;
    int l=s.size();
    int i;
    for( i=0;i<l;i++){
        if(s[i]=='0')break;
        if(i==l-1)break;
    }
    //cout<<i;
    for(int j=0;j<l;j++){
        if(j!=i)cout<<s[j];
    }
	return 0;
}