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
int n;
bool cmp(mp A,mp B){
	return A.SEC<B.SEC;
}
int main(){
	int a[100000+20];
	cin>>n;
	rb(i,1,n) scanf("%d",&a[i]);
	vector<mp> v;
	int row=n;
	stack<mp> pos;
	vector<mp> pos2;
	rl(i,n,1){
		if(a[i]==1){
			pos.push(II(row,i));
			v.PB(II(row--,i));
		}
	}
	rb(i,1,n){
		if(a[i]==2){
			while(pos.size()&&pos.top().SEC<i) pos.pop();
			if(pos.empty()){
				cout<<-1<<endl;
				return 0;
			}
			v.PB(II(pos.top().FIR,i));
			pos2.PB(II(pos.top().FIR,i));
			pos.pop();
		}
	}
	while(!pos.empty())
		pos2.PB(pos.top()),pos.pop();
	sort(ALL(pos2),cmp);
	reverse(ALL(pos2));
	for(auto it:pos2)
		pos.push(it);
	rl(i,n,1){
		if(a[i]==3){
			while(!pos.empty()&&pos.top().SEC<i) pos.pop();
			if(pos.empty()){
				cout<<-1<<endl;
				return 0;
			}
			v.PB(II(row--,i));
			v.PB(II(row+1,pos.top().SEC));
			int las=i;
			rl(j,i-1,1){
				if(a[j]==3){
					v.PB(II(row--,j));
					v.PB(II(row+1,las));
					las=j;
				}
			}
			break;
		}
	}
	cout<<v.size()<<endl;
	for(auto it:v){
		cout<<it.FIR<<' '<<it.SEC<<endl;
	}
	return 0;
}
/** 
  *
  *
  *
  *
  **/