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
	if(len&1){
		if(len==1){
			puts("Impossible");
			return 0;
		}
		int flag=1;
		rep(i,(len-1)>>1){
			if(i){
				if(s[i]!=s[i-1]){
					flag=0;
				}
			}
		}
		if(flag){
			puts("Impossible");
			return 0;
		}
		puts("2");
	}
	else{
		int flag=1;
		rep(i,len){
			if(i){
				if(s[i]!=s[i-1]){
					flag=0;
				}
			}
		}
		if(flag){
			puts("Impossible");
			return 0;
		} 
		string tmps;
		string s1,s2;
		rb(i,0,len-2){
			tmps="";
			rb(j,i+1,len-1){
				tmps+=s[j];
//				cout<<i<<endl;
			}
			rb(j,0,i){
				tmps+=s[j];
//				cout<<i<<endl;
			}
//			cout<<tmps<<endl;
			s1=s2="";
			rep(j,len){
				s1+=tmps[j];
			}
			rl(j,len-1,0){
				s2+=tmps[j];
			}
			if(s1==s2&&s1!=s){
//				cout<<s1<<endl;
				puts("1");
				return 0;
			} 
		}
		puts("2");
	} 
	return 0;
}