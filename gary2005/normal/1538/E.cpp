/*
{
######################
#       Author       #
#        Gary        #
#        2021        #
######################
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
//inline int read(){
//    int x=0;
//    char ch=getchar();
//    while(ch<'0'||ch>'9'){
//        ch=getchar();
//    }
//    while(ch>='0'&&ch<='9'){
//        x=(x<<1)+(x<<3)+(ch^48);
//        ch=getchar();
//    }
//    return x;
//}
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
int n;
map<string,pair<LL,string> > m;
int cnt(string s){
	int ret=0;
	rep(i,s.length()){
		if(i+4-1<s.length()){
			if(s[i]=='h'&&s[i]==s[i+2]&&s[i+1]=='a'&&s[i+1]==s[i+3]) ret++;
		}
	}
	return ret;
}
void gao(string & s){
	if(s.length()>10){
		string ss;
		rep(i,4) ss.PB(s[i]);
		rep(i,4) ss.PB(s[s.length()-(4-i)]);
		s=ss;
	}
}
void solve(){
	m.clear();
	scanf("%d",&n);
	string las;
	rb(i,1,n){
		string nam;
		cin>>nam;
		string ope;
		cin>>ope;
		if(ope==":="){
			string val;
			cin>>val;
			m[nam]=II(cnt(val),val);
		}
		else{
			string A,B;
			cin>>A>>B>>B;
			pair<LL,string> AA,BB;
			AA=m[A];
			BB=m[B];
			gao(AA.SEC);
			gao(BB.SEC);
			string val=AA.SEC+BB.SEC;
			int tmp=0;
			rb(i,1,3){
				if(AA.second.length()>=i&&BB.second.length()>=4-i){
					string ttmp;
					rep(j,i){
						ttmp.PB(AA.SEC[AA.SEC.length()-(i-j)]);
					}
					rep(j,4-i){
						ttmp.PB(BB.second[j]);
					}
					tmp+=ttmp=="haha";
				}
			}
			m[nam]=II(AA.FIR+BB.FIR+tmp,val);
		}
		las=nam;
	}
	cout<<m[las].FIR<<endl;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		solve();
	}
	return 0;
}