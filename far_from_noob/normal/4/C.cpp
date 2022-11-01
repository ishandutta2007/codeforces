#include <iostream>
using namespace std;
#include<bits/stdc++.h>
int main() {
    int n;
    cin >> n;
    string s;
    map<string , int>chutiyapa;
    for(int i=0;i<n;i++){
        cin >> s;
        if(chutiyapa[s]==0)
        cout << "OK"<<endl;
        else cout << s<<chutiyapa[s]<<endl;
        chutiyapa[s]++;
    }
	return 0;
}