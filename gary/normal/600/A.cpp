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
string words[100000];
int tot=1;
int main(){
	string s;
	cin>>s;
	int len=s.length();
	rb(i,1,len){
		if(s[i-1]==';'||s[i-1]==','){
			tot++;
			continue;
		}
		words[tot]+=s[i-1];
	}
//	cout<<tot<<endl;
	string A,B;
	int totA=0,totB=0;
	rb(i,1,tot){
		int flag=1;
		int len=words[i].length();
		if(!len){
			totB++;
			if(totB!=1) B+=',';
			continue;
		}
		if(len>=2&&words[i][0]=='0'){
			flag=0;
		}
		rb(j,1,len){
			if(!(words[i][j-1]>='0'&&words[i][j-1]<='9')) flag=false;
		}
		if(flag){
			totA++;
			if(totA!=1) A+=',';
			A+=words[i];
		}
		else{
			totB++;
			if(totB!=1) B+=',';
			B+=words[i];
		}
	}
	if(totA){
		cout<<'"'<<A<<'"'<<endl;
	}
	else{
		cout<<'-'<<endl;
	}
	if(totB){
		cout<<'"'<<B<<'"'<<endl;
	}
	else{
		cout<<'-'<<endl;
	}
	return 0;
}