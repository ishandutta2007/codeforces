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
	int t;
	cin>>t;
	while(t--){
		string s;
		string t;
		cin>>s>>t;
		int len1,len2;
		len1=s.length();
		len2=t.length();
		int pos=0;
		rl(i,len2-1,0){
			if(t[i]=='1'){
				pos=i;
				break;
			}
		}
		pos=len2-pos+1;
		pos=len1-pos+1;
		rl(i,pos,0){
			if(s[i]=='1'){
				cout<<pos-i<<endl;
				break;
			}
		}
	}
	return 0;
}