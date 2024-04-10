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
map<char,int> Count;
int main(){
	string s;
	cin>>s;
	int len=s.length();
	rb(i,0,len-1){
		Count[s[i]]++;
	}
	int tot=0;
	map<char,int> :: IT ite;
	for(ite=Count.begin();ite!=Count.end();ite++){
		tot+=bool(((ite->SEC)&1));
//		cout<<ite->FIR<<" "<<ite->SEC<<endl;
	}
//	cout<<tot<<endl;
	if(tot<=1){
		cout<<"First"<<endl;
		return 0;
	}
	cout<<((len&1)? "First":"Second")<<endl;
	return 0;
}