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
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int main(){
	string s1,s2;
	cin>>s1>>s2;
	int len1=s1.length(),len2=s2.length();
	string S1,S2;
	bool flag=0;
	rep(i,len1){
		if(flag||s1[i]!='0'){
			flag=1;
			S1+=s1[i];
		}
	}
	flag=0;
	rep(i,len2){
		if(flag||s2[i]!='0'){
			flag=1;
			S2+=s2[i]; 
		}
	}
	len1=S1.length();
	len2=S2.length();
	s1=S1;
	s2=S2;
	if(len1!=len2){
		cout<<((len1<len2)? "<":">")<<endl;
	}
	else{
		rep(i,len1){
			if(s1[i]!=s2[i]){
				cout<<((s1[i]<s2[i])? '<':'>')<<endl;
				return 0;
			}
		}
		puts("=");
	}
	return 0;
	
}