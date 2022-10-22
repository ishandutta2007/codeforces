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
	string s;
	cin>>s;
	int len=s.length();
	int from=0;
	int to=len;
	rl(i,len-1,0){
		if(s[i]!='0') break;
		to=i;
	}
	to--;
	string s1,s2;
	rb(i,from,to){
		s1+=s[i];
	}
	rl(i,to,from){
		s2+=s[i];
	}
	if(s1==s2){
		puts("YES");
	}
	else{
		puts("NO");
	}
	return 0;
}