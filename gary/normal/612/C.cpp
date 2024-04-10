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
int f[1000000+10];
inline bool judge(char A,char B){
	if(A=='('){
		return B!=')';
	}
	else{
	if(A=='{'){
		return B!='}';
	}
	else{
		if(A=='[')
		return B!=']';
		else
		return B!='>';
	}	
	}
	
}
int main(){
	string s;
	cin>>s;
	if(s.length()==0){
		puts("0");
		return 0;
	}
	if(s.length()&1){
		puts("Impossible");
		return 0;
	}
	rb(i,0,s.length()-1){
		if(i!=0){
			f[i]=f[i-1];
		}
		f[i]+=(s[i]=='(' || s[i]=='<' ||s[i]=='['||s[i]=='{')? 1:-1;
		if(f[i]<0){
			puts("Impossible");
			return 0;
		}
	}
	if(f[s.length()-1]!=0){
		puts("Impossible");
		return 0;
	}
	stack<char> S;
	int res=0;
	rb(i,0,s.length()-1){
		if(s[i]=='(' || s[i]=='<' ||s[i]=='['||s[i]=='{'){
			S.push(s[i]);
		}
		else{
			res+=judge(S.top(),s[i]);
//			cout<<S.top()<<" "<<s[i]<<endl;
			S.pop();
		}
	}
	printf("%d\n",res);
	return 0;
}