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
int n;
string s[50000+10];
bool cmp(string A,string B){
	string AFIR,BFIR;
	AFIR=A;
	AFIR+=B;
	BFIR=B;
	BFIR+=A;
//	cout<<AFIR<<" "<<BFIR<<bool(AFIR<BFIR)<<endl;
	return AFIR<BFIR;
}
int main(){
	scanf("%d",&n);
	rb(i,1,n){
		cin>>s[i];
	}
	sort(s+1,s+1+n,cmp);
	rb(i,1,n){
		cout<<s[i];
	}
	cout<<endl;
	return 0;
}