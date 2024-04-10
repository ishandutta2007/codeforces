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
void noans(){
	puts("-1");
	exit(0) ;
}
string s;
int n;
bool chk(){
	if(s[0]=='_'||s[n-1]=='_') return false;
	rep(i,n-1){
		if(s[i]=='_'&&s[i+1]=='_') return false;
	}
	int cnt=0;
	vector<int> ret;
	rep(i,n){
		if(s[i]=='#'){
			++cnt;
		}
		else{
			ret.PB(cnt);
			cnt=0;
		}
	}
	ret.PB(cnt);
	cout<<ret.size()<<endl;
	for(auto it:ret){
		cout<<it<<" ";
	}
	cout<<endl;
	return true;
}
void Gao(vector<int> & V,int x){
	if(x==0) return ;
	if(x==2){
		V.PB(1);
		return;
	}
	if(x==3){
		V.PB(2);
		return ;
	}
	V.PB(1);
	Gao(V,x-2);
}
void gao(int x){
	int cnt=0,cnt2=0;
	vector<int> ret;
	rep(i,n){
		if(s[i]=='#'){
			if(i&&s[i-1]=='_'){
				if(cnt<x+(i!=cnt)) return ;
				int d=cnt-(x+(i!=cnt));
				if(d==1) return ;
				if(x==1&&d%2==1) return ;
				Gao(ret,d);
			}
			cnt=0;
			cnt2++;
		}
		else{
			if(cnt2) ret.PB(cnt2+x);
			cnt2=0;
			++cnt;
		}
	}
	if(cnt-x==1) return ;
	Gao(ret,cnt-x);
	cout<<ret.size()<<endl;
	for(auto it:ret){
		cout<<it<<" ";
	}
	cout<<endl;
	exit(0);
}
int main(){
	cin>>s;
	n=s.length();
	if(chk()) return 0;
	if(s[n-1]=='#'){
		noans();
	}
	int cnt=0;
	rep(i,n) cnt+=s[i]=='#';
	if(!cnt){
		cout<<"0\n";
		return 0;
	}
	int dis=0;
	rl(i,n-1,0){
		if(s[i]=='#'){
			dis=n-i-1;
			break;
		}
	}
//	cnt=0;
//	int t=INF;
//	rep(i,n){
//		if(s[i]=='_'){
//			++cnt;
//		}
//		else{
//			if(cnt!=-1){
//				check_min(t,cnt);
//			}
//			cnt=-1;
//		}
//	}
	rb(i,1,min(dis,10)){
		gao(i);
	}
	noans();
	return 0;
}