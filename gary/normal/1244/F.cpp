/*
AuThOr GaRyMr
:
1.&
2.Dp
3.long long ()
4.long long INF 
*/
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
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
string s;
int n,k;
vector<mp> v; 
int main(){
	cin>>n>>k>>s;
	s+=s[0];
	s=s[n-1]+s;
	int tmps=-1;
	rb(i,1,n){
		if(s[i]!=s[i-1]&&s[i]!=s[i+1]){
			if(tmps==-1) tmps=i;
		}
		else{
			if(tmps!=-1){
				v.PB(II(tmps,i-1));
				tmps=-1;
			}
		}
	}
	if(tmps!=-1){
			if(v.size()&&v[0].FIR==1){
				v.PB(II(tmps,v[0].SEC));
				v.erase(v.begin()); 
			}
			else{
				if(tmps==1){
					if((k&1)==0){
				rb(i,1,n) cout<<s[i];cout<<endl;
			}
			else{
				rb(i,1,n) {
					if(s[i]=='W') cout<<'B';
					else cout<<'W';
				}
				cout<<endl;
			}
			return 0;
				}
				v.PB(II(tmps,n));
			}
	}
	//bfs
	queue<mp> q;
//	cout<<v.size()<<endl;
//cout<<v[0].FIR<<"----"<<v[0].SEC<<endl;
	rep(i,v.size()) q.push(v[i]); 
	rb(i,1,k){
		queue<mp> next;
		if(q.empty()) break;
		while(!q.empty()){
			int s_=q.front().FIR,e_=q.front().SEC;
//			cout<<s_<<"------"<<e_<<endl;
			q.pop();
			if(s_>e_){
				s[s_]=s[s_-1];
				s[e_]=s[e_+1];
				s[n+1]=s[1];
				s[0]=s[n];
				s_++,e_--;
				if(s_>n) s_-=n;
				if(e_<1) e_+=n;
//				cout<<s_<<"--"<<e_<<endl;
				if(s_<=e_ or (s_<=n and e_>=1)){
					next.push(II(s_,e_));
				} 
			}
			else{
				s[s_]=s[s_-1];
				s[e_]=s[e_+1];
				s[n+1]=s[1];
				s[0]=s[n];
				s_++,e_--;
				if(s_<=e_) next.push(II(s_,e_));
			}
		}
		q=next;
	}
	if(k&1)
	while(!q.empty()){
		int s_=q.front().FIR,e_=q.front().SEC;
//		cout<<"s"<<endl;
		q.pop();
		if(s_>e_){
			rb(i,s_,n){
				if(s[i]=='W') s[i]='B';
				else s[i]='W';
			}
			rb(i,1,e_){
				if(s[i]=='W') s[i]='B';
				else s[i]='W';
			}
		}
		else{
			rb(i,s_,e_){
				if(s[i]=='W') s[i]='B';
				else s[i]='W';
			}
		}
	}
	rb(i,1,n) cout<<s[i];
	return 0;
}
/*
7 3
WBWWBWB
*/