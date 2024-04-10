/*
AuThOr Gwj
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
#define debug_pair(A) cerr<<A.FIR<<" "<<A.SEC<<endl;
#define biggest(A,B) A=max(A,B)
#define smallest(A,B) A=min(A,B)
#define get(a) cin>>a
#define get2(a,b) cin>>a>>b
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int n,h,m,k;
vector<int> v;
vector<mp> v2;
int mod(int a){
	return a%m? a%m : m;
}
bool cover(int x,int X){
	if(x+k<=m){
		return (x+k>X)&(x<X);
	}
	return (X>x)|(mod(x+k)>X);
}
int save[100000+20];
int main(){
	fastio;
	get2(n,h);
	get2(m,k);
	m>>=1;
	rb(i,1,n){
		int hi,mi;
		get2(hi,mi);
		v.PB(mod(mi));
		save[i]=mod(mi);
	}
	sort(ALL(v));
	int last=-1;
	int cnt=0;
	for(auto it:v){
		if(last>=0){
			if(last!=it){
				v2.PB(II(last,cnt));
				cnt=0;	
			}
		}
		cnt++;
		last=it;
	}
	v2.PB(II(last,cnt));
//	for(auto it:v2)
//	{
//		cout<<"#"<<it.FIR<<" "<<it.SEC<<endl;
//	}
	mp res;
	res=II(INF,0);
	int del=0;
	int las=v2[0].FIR;
	int r=0;
	rep(i,v2.size()){
		mp it=v2[i];
		if(it.FIR!=v2[0].FIR){
			if(cover(las,it.FIR)){
				del+=it.SEC;
			}
			else{
				r=i;
				break;
			}
		}
	}
//	cout<<r<<'.'<<del<<endl;
	res=min(res,II(del,v2[0].FIR%m));
	rep(i,v2.size()){
		if(!i) continue;
		if(r>i||r<=i-1){
			del-=v2[i].SEC;
		}
		if(r==i){
			r=i+1;
		}
		las=v2[i].FIR;
		r%=v2.size();		
		while(cover(las,v2[r].FIR)){
//			cout<<"#"<<r<<","<<v2[r].SEC<<endl;
			del+=v2[r].SEC;
			r++;
			r%=v2.size();
		}
//		cout<<r<<'.'<<del<<endl;
		res=min(res,II(del,las%m));
	}
	cout<<res.FIR<<" "<<(k+res.SEC)%m<<endl;
	rb(i,1,n){
//		cout<<save[i]<<" "<<mod(mod(res.SEC))<<" "<<m<<endl;
		if(cover(mod(res.SEC),save[i])){
			cout<<i<<" ";	
		}
	}cout<<endl;
	return 0;
}