//* AuThOr GaRyMr *//
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define niv vector<int>
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define ff fflush(stdout)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
map<char,int> tot; 
int duo[26],shao[26],tot2[26],OK[200000+10];
vector<int> ab,ba;
int tota,totb;
int main(){
	int n;
//	cin>>s;
	cin>>n;
	string s,t;
	cin>>s;
	cin>>t;
	rep(i,n){
		if(s[i]!=t[i]){
			if(s[i]=='a'){
//				tota++;
				ab.PB(i);
//				cout<<"-"<<i<<endl;
			}
			else{
//				totb++;
				ba.PB(i);
//				cout<<i<<endl;
			}
		}
		if(s[i]=='a') tota++;
		else totb++;
			if(t[i]=='a') tota++;
		else totb++;
	}
	if(tota&1||totb&1){
		puts("-1");
		return 0;
	}
	vector<mp> v;
		while(ab.size()>=2){
			int it=*(ab.end()-1);
			ab.pop_back();
			int it2=*(ab.end()-1);
			ab.pop_back();
			v.PB(II(it,it2));
		}
		while(ba.size()>=2){
			int it=*(ba.end()-1);
			ba.pop_back();
			int it2=*(ba.end()-1);
			ba.pop_back();
			v.PB(II(it,it2));
		}
	if(ba.size()){
		v.PB(II(ba[0],ba[0]));
		v.PB(II(ba[0],ab[0]));
	}
	cout<<v.size()<<endl;
	for(auto it:v){
		cout<<it.FIR+1<<" "<<it.SEC+1<<endl;
	}
	return 0;
}