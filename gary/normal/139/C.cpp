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
string s[10000+10];
map<char,int> vow;
int getpos(string S,int k){
	int len=S.length();
	rl(i,len-1,0){
		if(vow[S[i]]){
			k--;
		}
		if(k==0) return i;
	}
	return -1;
}
int n,k;
int aaaa,aabb,abab,abba;
void check(){
	for(int i=1;i<=n;i+=4){
		if(!(s[i]==s[i+1]&&s[i]==s[i+2]&&s[i]==s[i+3])) aaaa=false;
		if(!(s[i]==s[i+1]&&s[i+2]==s[i+3])) aabb=false;
		if(!(s[i]==s[i+2]&&s[i+1]==s[i+3])) abab=false;
		if(!(s[i]==s[i+3]&&s[i+1]==s[i+2])) abba=false;
	}
}
int main(){
	aaaa=aabb=abab=abba=1;
	vow['a']=vow['e']=vow['i']=vow['o']=vow['u']=1;
	cin>>n>>k;
	n=n+n+n+n;
	rb(i,1,n){
		cin>>s[i];
		int idx=getpos(s[i],k);
		if(idx==-1){
			puts("NO");
			return 0;
		}
		string tmp="";
		int len=s[i].length();
		rb(j,idx,len-1){
			tmp+=s[i][j];
		}
		s[i]=tmp;
	}
	check();
	if(aaaa) puts("aaaa");
	else if(aabb) puts("aabb");
	else if(abab) puts("abab");
	else if(abba) puts("abba");
	else puts("NO");
	return 0;
}