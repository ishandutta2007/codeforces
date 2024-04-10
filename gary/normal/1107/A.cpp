//* AuThOr GaRyMr *//
//AFT ST
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
	int n;
int t;cin>>t;
while(t--){
	cin>>n;
	string s;
	cin>>s;
	if(n==2){
		if(s[0]>=s[1]){
			cout<<"NO"<<endl;
		}
		else{
			cout<<"YES"<<endl;
			cout<<2<<endl;
			cout<<s[0]<<" "<<s[1]<<endl;
		}
	}
	else{
		cout<<"YES"<<endl;
		cout<<2<<endl;
		cout<<s[0]<<" ";
		rb(i,1,n-1){
			cout<<s[i];
		}
		cout<<endl;
	}
}
	return 0;
}