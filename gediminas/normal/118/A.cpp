#include <bits/stdc++.h>

using namespace std;

int main () {
    ios_base::sync_with_stdio(false),cin.tie(0);
	string a;
	cin >> a;
	for(char&c:a){
	    c=tolower(c);
	    if(c=='a' or c=='e' or c=='i' or c=='o' or c=='u' or c=='y'){
	        
	    }else{
	        cout << "." << c;
	    }
	}
	return 0;
}