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
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
string s;
int suma[200000+10],sumd[200000+10],sums[200000+10],sumw[200000+10];
int main(){
	int T;
	cin>>T;
	while(T--){
		memset(suma,0,sizeof(suma));
		memset(sumd,0,sizeof(sumd));
		memset(sumw,0,sizeof(sumw));
		memset(sums,0,sizeof(sums));
		cin>>s;
		int mw,md,ms,ma;
		mw=md=ma=ms=0;
		int x,y;
		x=y=0;
		int len=s.length();
		rl(i,len-1,0) {
			suma[i]=suma[i+1];
			sumd[i]=sumd[i+1];
			sums[i]=sums[i+1];
			sumw[i]=sumw[i+1];
			if(s[i]=='A') {
			suma[i]++;
			sumd[i]--;
			}
			if(s[i]=='D'){
			sumd[i]++;
			suma[i]--;
			}
			if(s[i]=='W') {
			sums[i]--;
			sumw[i]++;
			}
			if(s[i]=='S') {
			sumw[i]--;
			sums[i]++;
			}
			suma[i]=max(suma[i],0);
			sumw[i]=max(sumw[i],0);
			sums[i]=max(sums[i],0);
			sumd[i]=max(sumd[i],0);
		}
		rep(i,len)
		{
			if(s[i]=='W') y++;
			if(s[i]=='S') y--;
			if(s[i]=='D') x++;
			if(s[i]=='A') x--;
			mw=max(mw,y);
			ms=min(ms,y);
			ma=min(ma,x);
			md=max(md,x);
		}int ama,ams,amd,amw;
		ama=ma;
		ams=ms;
		amd=md;
		amw=mw;
		LL CHANG=mw-ms+1;
		LL KUAN=md-ma+1;
		LL res=CHANG*KUAN;
		bool OK=0;
		//W
		OK=0;
		x=y=0;
		mw=md=ma=ms=0;
		rep(i,len)
		{
			if(s[i]=='W') y++;
			if(s[i]=='S') y--;
			if(s[i]=='D') x++;
			if(s[i]=='A') x--;
			mw=max(mw,y);
			ms=min(ms,y);
			ma=min(ma,x);
			md=max(md,x);
//			cout<<x<<" "<<y<<"amw:"<<amw<<" "<<y+sumw[i+1]-1<<endl;
			if(y+sumw[i+1]<amw&&y<amw&&!OK){
				OK=1;
//				cout<<"DONE"<<endl;
				y++;
			}
			mw=max(mw,y);
			ms=min(ms,y);
			ma=min(ma,x);
			md=max(md,x);
		}
		
		CHANG=mw-ms+1;
		KUAN=md-ma+1;
//		cout<<CHANG*KUAN<<endl;
		res=min(res,CHANG*KUAN);
		//S
		OK=0;
		x=y=0;
		mw=md=ma=ms=0;
		rep(i,len)
		{
			if(s[i]=='W') y++;
			if(s[i]=='S') y--;
			if(s[i]=='D') x++;
			if(s[i]=='A') x--;
			mw=max(mw,y);
			ms=min(ms,y);
			ma=min(ma,x);
			md=max(md,x);
			if(y-sums[i+1]>ams&&y>ams&&!OK){
			y--;
			OK=1; 
//			cout<<"S"<<endl;
			}
			mw=max(mw,y);
			ms=min(ms,y);
			ma=min(ma,x);
			md=max(md,x);
		}
		CHANG=mw-ms+1;
		KUAN=md-ma+1;
//		cout<<CHANG*KUAN<<endl;
//		cout<<ama<<endl;
		res=min(res,CHANG*KUAN);
		//A
		OK=0;
		x=y=0;
		mw=md=ma=ms=0;
		rep(i,len)
		{
			if(s[i]=='W') y++;
			if(s[i]=='S') y--;
			if(s[i]=='D') x++;
			if(s[i]=='A') x--;
			mw=max(mw,y);
			ms=min(ms,y);
			ma=min(ma,x);
			md=max(md,x);
//			cout<<i<<" "<<x<<" "<<y<<" "<<ama<<" "<<suma[i+1]<<endl;
			if(x-suma[i+1]>ama&&x>ama&&!OK){
				OK=1;
			    x--;
//			    cout<<"A"<<endl;
			}
			mw=max(mw,y);
			ms=min(ms,y);
			ma=min(ma,x);
			md=max(md,x);
		}
		CHANG=mw-ms+1;
		KUAN=md-ma+1;
//		cout<<CHANG*KUAN<<endl;
		res=min(res,CHANG*KUAN);
		//D 
		OK=0;
		x=y=0;
		mw=md=ma=ms=0;
		rep(i,len)
		{
			if(s[i]=='W') y++;
			if(s[i]=='S') y--;
			if(s[i]=='D') x++;
			if(s[i]=='A') x--;
			mw=max(mw,y);
			ms=min(ms,y);
			ma=min(ma,x);
			md=max(md,x);
//			cout<<x<<" "<<y<<endl;
			if(x+sumd[i+1]<amd&&x<amd&&!OK) {
			x++;
			OK=1;
//			cout<<"done"<<endl;
			}
			mw=max(mw,y);
			ms=min(ms,y);
			ma=min(ma,x);
			md=max(md,x);
		}
		CHANG=mw-ms+1;
		KUAN=md-ma+1;
		res=min(res,CHANG*KUAN);
//		cout<<CHANG*KUAN<<endl;
		cout<<res<<endl;
	}
	return 0;
}