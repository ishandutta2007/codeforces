//#include<bits/stdc++.h>
//#define rb(a,b,c) for(int a=b;a<=c;++a)
//#define rl(a,b,c) for(int a=b;a>=c;--a)
//#define rep(a,b) for(int a=0;a<b;++a)
//#define LL long long
//#define PB push_back
//#define POB pop_back
//#define II(a,b) make_pair(a,b)
//#define FIR first
//#define SEC second
//#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
//#define random(a) rng()%a
//#define ALL(a) a.begin(),a.end()
//#define check_min(a,b) a=min(a,b)
//#define check_max(a,b) a=max(a,b)
//#define ff fflush(stdout)
//using namespace std;
//const int INF=0x3f3f3f3f;
//typedef pair<int,int> mp;
//int A,B,C,D;
//bool dig(int r,int c){
//	cout<<"DIG"<<' '<<r<<' '<<c<<endl;ff;
//	return II(A,B)==II(r,c)||II(C,D)==II(r,c);
//	bool ok;
//	cin>>ok;
//	return ok;
//}
//int scan(int r,int c){
//	cout<<"SCAN"<<' '<<r<<' '<<c<<endl;ff;
//	return abs(A-r)+abs(C-r)+abs(B-c)+abs(D-c);
//	int ok;
//	cin>>ok;
//	return ok;
//}
//int calc(pair<mp,mp> x,mp y){
//	return abs(x.FIR.FIR-y.FIR)+abs(x.FIR.SEC-y.SEC)+abs(x.SEC.FIR-y.FIR)+abs(x.SEC.SEC-y.SEC);
//}
//int calc(vector<pair<mp,mp> > tmp,mp y){
//	map<int,int> oo;
//	for(auto it:tmp) oo[calc(it,y)]++;
//	int rest=0;
//	for(auto it:oo) check_max(rest,it.SEC);
//	return rest;
//}
//SRAND;
//void solve(){
//	int n,m;
//	cin>>n>>m;
//	cin>>A>>B>>C>>D;
//	vector<pair<mp,mp> > ans;
//	rb(i,1,n) rb(j,1,m) rb(i2,1,n) rb(j2,1,m) if(II(i2,j2)>II(i,j)) ans.PB(II(II(i,j),II(i2,j2)));
//	set<mp> have;
//	rl(i,7,1){
////		cout<<ans.size()<<endl;
//		set<mp> ooo;
//		for(auto it:ans){
//		if(have.find(it.FIR)==have.end())
//		ooo.insert(it.FIR);
//		if(have.find(it.SEC)==have.end())
//		ooo.insert(it.SEC);
//		}
//		if(ooo.size()<=i){
//			for(auto it:ooo) dig(it.FIR,it.SEC);
//			return ;
//		}
//		int rest=INF;
//		mp rest3;
//		rb(T,1,20){
//			int x,y;
//			x=random(n)+1;
//			y=random(m)+1;
//			auto rest2=II(x,y);
//			int temp=calc(ans,II(x,y));
//			if(temp<abs(rest)){
//				rest=temp;
//				rest3=rest2;
//			}
//			temp=0;
//			for(auto it:ans) temp+=(it.FIR==rest2||it.SEC==rest2);
//			temp=max(temp,(int)(ans.size()-temp));
//			if(temp<abs(rest)){
//				rest=-temp;
//				rest3=rest2;
//			}
//		}
//		if(rest>0){
//			int temp=scan(rest3.FIR,rest3.SEC);
//			vector<pair<mp,mp> > newans;
//			for(auto it:ans) if(calc(it,rest3)==temp) newans.PB(it);
//			ans=newans;
//		}
//		else{
//			int temp=dig(rest3.FIR,rest3.SEC);
//			vector<pair<mp,mp> > newans;
//			have.insert(rest3);
//			for(auto it:ans) if((it.FIR==rest3||it.SEC==rest3)==temp) newans.PB(it);
//			ans=newans;
//		}
//	}
//	assert(0);
//}
//int main(){
//	int t;
//	cin>>t;
//	while(t--) solve();
//    return 0;
//}

#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define rep(a,b) for(int a=0;a<b;++a)
#define LL long long
#define PB push_back
#define POB pop_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
#define ff fflush(stdout)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
set<mp> haveans;
int A,B,C,D;
bool dig(int r,int c){
	if(haveans.size()==2) return 0;
	cout<<"DIG"<<' '<<r<<' '<<c<<endl;ff;
//	return II(A,B)==II(r,c)||II(C,D)==II(r,c);
	bool ok;
	cin>>ok;
	if(ok){
		haveans.insert(II(r,c));
	}
	return ok;
}
int scan(int r,int c){
	if(haveans.size()==2) return 0;
	cout<<"SCAN"<<' '<<r<<' '<<c<<endl;ff;
//	return abs(A-r)+abs(C-r)+abs(B-c)+abs(D-c);
	int ok;
	cin>>ok;
	return ok;
}
int calc(pair<mp,mp> x,mp y){
	return abs(x.FIR.FIR-y.FIR)+abs(x.FIR.SEC-y.SEC)+abs(x.SEC.FIR-y.FIR)+abs(x.SEC.SEC-y.SEC);
}
int calc(vector<pair<mp,mp> > tmp,mp y){
	int oo[60]={0};
	for(auto it:tmp) oo[calc(it,y)]++;
	return *max_element(oo,oo+60);
}
SRAND;
void solve(){
	haveans.clear();
	int n,m;
	cin>>n>>m;
//	cin>>A>>B>>C>>D;
	vector<pair<mp,mp> > ans;
	rb(i,1,n) rb(j,1,m) rb(i2,1,n) rb(j2,1,m) if(II(i2,j2)>II(i,j)) ans.PB(II(II(i,j),II(i2,j2)));
	set<mp> have;
	rl(i,7,1){
		if(haveans.size()==2) return ;
//		cout<<ans.size()<<endl;
		set<mp> ooo;
		for(auto it:ans){
		if(have.find(it.FIR)==have.end())
		ooo.insert(it.FIR);
		if(have.find(it.SEC)==have.end())
		ooo.insert(it.SEC);
		}
//		cout<<ooo.size()<<" "<<i<<endl;
//		if(ans.size()==2){
//			for(auto it:ans) cout<<it.FIR.FIR<<" "<<it.FIR.SEC<<' '<<it.SEC.FIR<<" "<<it.SEC.SEC<<' '<<endl;
//		}
		if(ooo.size()<=i){
			for(auto it:ooo) dig(it.FIR,it.SEC);
			return ;
		}
		int rest=INF;
		mp rest3;
		set<mp> app;
		vector<int> X,Y;
		for(auto it:ans) X.PB(it.FIR.FIR),Y.PB(it.FIR.SEC),X.PB(it.SEC.FIR),Y.PB(it.SEC.SEC);
		sort(ALL(X)),X.erase(unique(ALL(X)),X.end());
		sort(ALL(Y)),Y.erase(unique(ALL(Y)),Y.end());
		rb(T,1,300){
			int x,y;
			x=X[random(X.size())];
			y=Y[random(Y.size())];
			if(app.find(II(x,y))!=app.end()) continue;
			app.insert(II(x,y));
			auto rest2=II(x,y);
			int temp=calc(ans,II(x,y));
			if(temp<abs(rest)){
				rest=temp;
				rest3=rest2;
			}
			temp=0;
			for(auto it:ans) temp+=(it.FIR==rest2||it.SEC==rest2);
			temp=max(temp,(int)(ans.size()-temp));
			if(temp<abs(rest)){
				rest=-temp;
				rest3=rest2;
			}
		}
//		if(ans.size()<100)
//		for(auto it:ans){
//			int x,y;
//			x=it.FIR.FIR;
//			y=it.FIR.SEC;
//			mp rest2=II(x,y);
//			int temp=0;
//			for(auto it:ans) temp+=(it.FIR==rest2||it.SEC==rest2);
//			temp=max(temp,(int)(ans.size()-temp));
//			if(temp<abs(rest)){
//				rest=-temp;
//				rest3=rest2;
//			}
//			temp=calc(ans,II(x,y));
//			if(temp<abs(rest)){
//				rest=temp;
//				rest3=rest2;
//			}
//			x=it.SEC.FIR;
//			y=it.SEC.SEC;
//			rest2=II(x,y);
//			temp=0;
//			for(auto it:ans) temp+=(it.FIR==rest2||it.SEC==rest2);
//			temp=max(temp,(int)(ans.size()-temp));
//			if(temp<abs(rest)){
//				rest=-temp;
//				rest3=rest2;
//			}
//			temp=calc(ans,II(x,y));
//			if(temp<abs(rest)){
//				rest=temp;
//				rest3=rest2;
//			}
//		}
		if(rest>0){
		int temp=scan(rest3.FIR,rest3.SEC);
		vector<pair<mp,mp> > newans;
		for(auto it:ans) if(calc(it,rest3)==temp) newans.PB(it);
		ans=newans;
		}
		else{
			int temp=dig(rest3.FIR,rest3.SEC);
			vector<pair<mp,mp> > newans;
			have.insert(rest3);
			for(auto it:ans) if((it.FIR==rest3||it.SEC==rest3)==temp) newans.PB(it);
			ans=newans;
		}
	}
//	cout<<A<<' '<<B<<" "<<C<<' '<<D<<endl;
	assert(0);
}
int main(){
	//freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	int t;
	cin>>t;
	while(t--) solve();
    return 0;
}