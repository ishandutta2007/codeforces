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
map<char,map<char,int> > M;
int main(){
	string s;
	rb(i,1,3){
		cin>>s;
		M[s[1]][s[0]]++;
	}
	int res=INF;
	map<char,map<char,int> > :: IT ite;
	for(ite=M.begin();ite!=M.end();ite++){
		map<char,int> M3=ite->SEC;
		map<char,int> :: IT ite2;
		for(ite2=M3.begin();ite2!=M3.end();ite2++){
			res=min(res,3-(ite2->SEC));
			res=min(res,!(bool(M3[(ite2->FIR)]))+!(bool(M3[(ite2->FIR)+1]))+!(bool(M3[(ite2->FIR)+2])));
		}
	}
	cout<<res<<endl;
	return 0;
}