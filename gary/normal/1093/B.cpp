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
void solve(){
	map<char,int> hav;
	string s;
	cin>>s;
	int len=s.length();
	int dif=0;
	rep(i,len){
		if(hav[s[i]]==0) dif++;
		hav[s[i]]=1;
	} 
	if(dif==1){
		puts("-1");
		
	}
	else{
		vector<char> v;
		rep(i,len){
			v.PB(s[i]);
		}
		sort(v.begin(),v.end());
		rep(i,len){
			cout<<v[i];
		}
		cout<<endl;
	}
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		solve();
	}
	return 0;
}