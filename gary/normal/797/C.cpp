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
string s;
int main(){
	cin>>s;
	int len=s.length();
	stack<char> S;
	map<char,int> M;
	map<char,int> M2;
	M2['z'+1]=1;
	S.push('z'+1);
	rb(i,0,len-1){
		M[s[i]]++;
	} 
	map<char,int> :: IT ite1,ite2;
	ite1=M.begin();
	ite2=M2.begin();
//	cout<<ite1->FIR<<endl;
	rb(i,0,len-1){
//		cout<<i<<endl;
		while(!ite1->SEC) ite1++;
		while(S.top()<=ite1->FIR){
			cout<<S.top();
			S.pop(); 
		}
		for(;i<len;i++){
			S.push(s[i]);
			M[s[i]]--;
			if(s[i]==ite1->FIR) break;
		} 
	}
	while(!S.empty()){
		if(S.top()=='z'+1){
			break;
		}
		cout<<S.top();
		S.pop();
	}
	return 0;
}