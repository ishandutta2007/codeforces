#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

bool func(int x, int y){
	cout<<"? "<<x<<" "<<y<<endl;
	fflush(stdout);
	string s;
	cin>>s;
	return s[0] == 'x';
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    while(cin>>s){
    	if(s[0] == 'e' || s[0] == 'm')return 0;
    	int x = 0, y = 1;
    	for(int i = 0; i < 30; i++){
    		if(func(x, y))break;
    		x = y;
    		y <<= 1;
    	}
    	int l = x + 1, r = y;
    	while(l < r){
    		int m = l + (r - l)/2;
    		if(func(m, x)){
    			l = m + 1;
    		}else{
    			r = m;
    		}
    	}
    	cout<<"! "<<l<<endl;
    	fflush(stdout);
    }

}