/*
AuThOr GaRyMr
:
1.&
2.Dp
3.long long ()
4.long long INF 
5.Dp on trees: 
6.long double | 
7.!(prince and princess)
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
int calc2(int x){
	int tmp=1;
	while(x>=tmp){
		x-=tmp;
		tmp<<=1;
	}
	return x;
}
int n,rest,tot;mp save[1000000];
void run(int index,int now,int flg){
	save[index]=II(now,flg);
	if((index<<1)>tot) return;
	if(now){
		if(flg){
			run(index<<1,0,0),run((index<<1)+1,0,0);
		}
		else{
			run(index<<1,1,1),run((index<<1)+1,1,0);
		}
	}
	else{
		if(flg){
			run(index<<1,0,0),run((index<<1)+1,1,0);
		}
		else{
			run(index<<1,1,1),run((index<<1)+1,0,0);
		}
	}
}
bool check(){
	int tmp=0;
	for(int i=tot;i*2>tot;i--){
		if(save[i].FIR){
			if(!save[i].SEC) return 0;
		}
		else{
			tmp++;
			if(save[i].SEC==1) return 0;
		}
	}
	return (tmp==rest);
}
int main(){
	cin>>n;
	rest=calc2(n),tot=n-rest;
	int res=0;
	run(1,n&1,1),res+=check();
	run(1,n&1,0),res+=check(); 
	cout<<res<<endl;
	return 0;
}