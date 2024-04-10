/*
AuThOr GaRyMr
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
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int n;
int number[1000000+10],number2[1000000+10],max_[100000+10],min_[100000+10],flag[100000+10];
int main(){
	int cnt=0;
	fastio;
	cin>>n;
	rb(i,1,n){
		max_[i]=-1;
		min_[i]=INF;
		int l;
		cin>>l;
		int MINI=INF;
		rb(j,1,l){
			int ai;
			cin>>ai;
			max_[i]=max(max_[i],ai);
			MINI=min(ai,MINI);
			if(ai>MINI){
				flag[i]=1;
			}
		}
		cnt+=flag[i];
		min_[i]=MINI;
		if(flag[i]==0){
				number[max_[i]]++;
		}
	}
	rl(i,1000000,0){
		number[i]+=number[i+1];
	}
	LL res=0;
	rb(i,1,n)
		if(flag[i])
			res+=n;
		else{
//			cout<<i<<" "<<res<<endl;  
			res+=cnt;
			res+=number[min_[i]+1];
		}
	cout<<res<<endl;
	return 0;
}