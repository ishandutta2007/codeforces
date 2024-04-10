/*
{
######################
#       Author       #
#        Gary        #
#        2020        #
######################
*/
//#pragma GCC target ("avx2")
//#pragma GCC optimization ("O3")
//#pragma GCC optimization ("unroll-loops")
#pragma GCC optimize(2)
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
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
int rest=-1;
void update(int x){
	if(rest==-1||rest>x) rest=x;
}
int a[6];
int n;
deque<int> each[100000+20];
int main(){
	fastio;
	rep(i,6)
		cin>>a[i];
	cin>>n;
	vector<int> all;
	set<mp> s;
	rb(i,1,n){
		int bi;
		cin>>bi;
		rep(j,6){
			if(a[j]<bi){
				each[i].PB(bi-a[j]);
				all.PB(bi-a[j]);
			}
		}
		sort(ALL(each[i]));
		s.insert(II(each[i][0],i));
	}
	sort(ALL(all));
	for(auto it:all){
		bool b=0;
		while((*s.begin()).FIR<it){
			int index=(*s.begin()).SEC;
			each[index].pop_front();
			s.erase(s.begin());
			if(each[index].empty()) {
				b=1;
				break;	
			}
			s.insert(II(each[index][0],index));
		}
		if(b) break;
		auto itt=s.end();
		itt--;
		update((*itt).FIR-it);
	}
	cout<<rest<<endl;
	return 0;
}
/** 
  *
  *
  *
  *
  **/