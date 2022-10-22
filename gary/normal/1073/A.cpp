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
int main(){int len;cin>>len;
	string s;
	cin>>s;
	if(len==1){
		cout<<"NO";
		return 0;
	}
	rb(i,0,len-2){
		if(s[i]!=s[i+1]){
			cout<<"YES"<<endl;
				cout<<s[i]<<s[i+1];
				return 0;
			} 
	}
	cout<<"NO";
	return 0;
}