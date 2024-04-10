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
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int X=1,Y=1;
map<char,int> M;
map<char,int> sum[200000+10];
int chah,chaz;
int _totr,_totl,_totu,_totd;
int n,x,y;
bool check(int l,int r){
	int tot=r-l+1;
	int totr,totl,totu,totd;
	totr=sum[r]['R'];if(l)totr-=sum[l-1]['R'];
	totl=sum[r]['L'];if(l)totl-=sum[l-1]['L'];
	totu=sum[r]['U'];if(l)totu-=sum[l-1]['U'];
	totd=sum[r]['D'];if(l)totd-=sum[l-1]['D'];
	totr=_totr-totr;
	totl=_totl-totl;
	totu=_totu-totu;
	totd=_totd-totd;
	if(x>0){
		tot-=abs(x-(totr-totl));
	}
	else{
		tot-=abs((-x)-(totl-totr));
	}
	if(y>0){
		tot-=abs(y-(totu-totd));
	}
	else{
		tot-=abs(-y-(totd-totu));
	}
	return (tot<0||tot&1)? 0:1;
}
int search(int l){
//	cout<<l<<"*"<<endl;
	int r=n-1;
	int fixed_l=l;
	while(l<r){
		int mid=(l+r)>>1;
//		cout<<l<<" "<<r<<endl;
		if(check(fixed_l,mid)){
			r=mid;
		}
		else{
			l=mid+1;
		}
	}
	return check(fixed_l,l)? l:INF;
}
int main(){
	string s;
	cin>>n>>s>>x>>y;
	rb(i,0,n-1){
		M[s[i]]++; 
		if(i)sum[i]=sum[i-1];
		sum[i][s[i]]++;
	}
	_totr=sum[n-1]['R'];
	_totl=sum[n-1]['L'];
	_totu=sum[n-1]['U'];
	_totd=sum[n-1]['D'];
	if(abs(x)+abs(y)>n){
		cout<<"-1";
		return 0;
	}
	chah=x-M['R']+M['L'];
	chaz=y-(M['U']-M['D']);
	if(chah==0&&chaz==0){
		cout<<0<<endl;
		return 0;
	}
	int res=INF;
	rb(i,0,n-1){
		int r=search(i);
		if(r==INF) break;
		res=min(res,r-i+1);
//		cout<<i<<" "<<i<<endl;
	}
	cout<<((res==INF)? -1:res) <<endl;
	return 0;
}