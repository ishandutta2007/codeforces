#include<iostream>
#include<algorithm>
using namespace std;
int main (){
    int n,c;
    cin >> n >> c;
    long long p[n+1],t[n+1];
    for(long long i=1; i<=n ;i++){
    	cin >> p[i];
	}
	for(long long i=1; i<=n ;i++){
		cin >> t[i];
	}
	long long ls=0,rs=0,lt=0,rt=0;
	for(long long i=1; i<=n ;i++){
		lt+=t[i];
		ls+=max(0LL,p[i]-c*lt);
	}
	for(long long i=n; i>=1 ;i--){
		rt+=t[i];
		rs+=max(0LL,p[i]-c*rt);
	}
	if(ls>rs){
		cout << "Limak\n";
	}
	else if(ls<rs){
		cout << "Radewoosh\n";
	}
	else{
		cout << "Tie\n";
	}
}