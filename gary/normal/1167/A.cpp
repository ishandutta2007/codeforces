//* AuThOr GaRyMr *//
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define niv vector<int>
#define LL long long
#define IT iterator
#define PB(a) push_back(a)
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string s;
		cin>>s;
		if(n<11){
			cout<<"NO"<<endl;
			continue;
		}
		if(n==11){
			cout<<((s[0]=='8')? "YES":"NO")<<endl;
			continue;
		}
		bool OK=0;
		rb(i,11,n){
			OK=(OK|bool(s[n-1-i+1]=='8'));
		}
		cout<<((OK)? "YES":"NO")<<endl;
	}	
	return 0;
}