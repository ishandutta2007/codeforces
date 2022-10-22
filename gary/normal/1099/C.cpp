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
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int main(){
	string s;
	cin>>s;
	int k;
	cin>>k;
	int len=s.length();
	int flag1,flag2;
	int have=0;
	flag1=flag2=0;
	rep(i,len){
		if(s[i]=='?') flag1++;
		else if(s[i]=='*') flag2++;
		else have++;
	}
	int mini=have-flag1-flag2;
	if(k<mini) {
		puts("Impossible");
		return 0;
	} 
	int maxi=have;
	if(flag2) maxi=INF;
	if(k>maxi){
		puts("Impossible");
		return 0;
	}
	if(k<have){
		int remove=have-k;
		rep(i,len){
			if(i!=len-1)
			{
				if(remove){
					if(s[i+1]=='*'||s[i+1]=='?') {
						remove--;
						continue;
					}	
				}
			}
			if(s[i]!='*'&&s[i]!='?') cout<<s[i];
		}
	}
	else {
		int add=k-have;
		rep(i,len){
			if(s[i]!='*'&&s[i]!='?'){
				cout<<s[i];
			}
			else{
				if(add)
				if(s[i]=='*')
				{
					rb(ite,1,add){
						cout<<s[i-1];
					}
					add=0;
				}
			}
		}
	}
	
	return 0;
}