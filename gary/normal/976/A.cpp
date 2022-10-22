//* AuThOr GaRyMr *//
#include<bits/stdc++.h>
#define rb(a,b,c) for(LL a=b;a<=c;++a)
#define rl(a,b,c) for(LL a=b;a>=c;--a)
#define niv vector<LL>
#define LL long long
#define IT iterator
#define PB(a) push_back(a)
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
using namespace std;
const LL INF=0x3f3f3f3f;
typedef pair<LL,LL> mp;
typedef pair<mp,mp> superpair;
int main(){
	int len;
	cin>>len;
	string s;
	cin>>s;
	if(s[0]!='0')
	cout<<1;
	rb(i,1,len)
	{
		if(s[i-1]=='0'){
			cout<<0;
		}
	}
	return 0;
}