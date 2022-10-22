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
//#defind FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
map<string ,int> M; 
map<string ,string > M2;
string S[6]={"red","purple","yellow","orange","green","blue"};
int main(){
	int n;
	string s;
	cin>>n;
	rb(i,1,n){
		cin>>s;
		M[s]=1;
		
	}
	M2["red"]="Reality";
	M2["blue"]="Space";
	M2["orange"]="Soul";
	M2["purple"]="Power";
	M2["green"]="Time";
	M2["yellow"]="Mind";
	cout<<6-n<<endl;
	rep(i,6){
		if(!M[S[i]]){
			cout<<M2[S[i]]<<endl;
		}
	}
	return 0;
}