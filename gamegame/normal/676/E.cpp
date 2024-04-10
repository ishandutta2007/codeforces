#include<iostream>
#include<sstream>
#include<cstdlib>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	int n,k;
	cin >> n >> k;
	if(k==0){
		string s,zero;
		int f=0;
		cin >> zero;
		if(zero[0]=='0') cout << "Yes\n";
		else if(zero[0]!='?') cout << "No\n";
		else{
		for(int i=1; i<=n ;i++){
			cin >> s;
			f+=(s[0]!='?');
		}
		if(f&1) cout << "Yes\n";
		else cout << "No\n";
		}
	}
	else{
		string s;
		long long int a[n+1],val=0;
		bool f=true;
		for(int i=0; i<=n ;i++){
			cin >> s;
			if(s[0]!='?') a[i]=atoi(s.c_str());
			else f=false;
		}
		if(f){
			for(int i=n; i>=0 ;i--){
				val=val*k+a[i];
				if(abs(val)>=1e12){ cout << "No\n";return 0;}
			}
			if(val==0) cout << "Yes\n";
			else cout << "No\n";
		}
		else if(n&1) cout << "Yes\n";
		else cout << "No\n";
	}
}