//* AuThOr GaRyMr *//
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
#define ff fflush(stdout)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int main(){
	int x1,x2,x3,x4,x5,x6,y1,y2,y3,y4,y5,y6;
	cin>>x1>>y1>>x2>>y2;
	cin>>x3>>y3>>x4>>y4;
	cin>>x5>>y5>>x6>>y6;
	int is=1;
	if(x1>=x3&&x2<=x4&&y1>=y3&&y2<=y4){
		is=0;
	}
	swap(x3,x5),swap(y3,y5),swap(x4,x6),swap(y4,y6);
	if(x1>=x3&&x2<=x4&&y1>=y3&&y2<=y4){
		is=0;
	}
//	cout<<y1<<" "<<y3<<" "<<y2<<" "<<y4<<endl;
	if((x1>=x3&&x2<=x4)||(y1>=y3&&y2<=y4)){
//		cout<<"s"<<endl;
		if((x1>=x3&&x2<=x4)){
			if(y1<y3&&y2<=y4){
				y2=y3;
			}
			else{
				if(y2>y4&&y1>=y3){
					y1=y4;
				}
			}
		}
		else{
//			cout<<"s";
			if(x1<x3&&x2<=x4){
				x2=x3;
//				cout<<"s";
			}
			else{
				if(x2>x4&&x1>=x3){
					x1=x4;
				}
			}
		}
//		cout<<"s"<<endl;
		swap(x3,x5),swap(y3,y5),swap(x4,x6),swap(y4,y6);
//		cout<<x1<<" "<<y1<<" "<<x2<<" "<<.y2<<endl;
//		cout<<x3<<" "<<y3<<" "<<x4<<" "<<y4<<endl;
		if(x1>=x3&&x2<=x4&&y1>=y3&&y2<=y4){
			is=0;
		}
	}
	if(is) cout<<"YES";
	else cout<<"NO";
	return 0;
}