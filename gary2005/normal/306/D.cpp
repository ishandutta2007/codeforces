/*
{
######################
#       Author       #
#        Gary        #
#        2021        #
######################
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
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
//inline int read(){
//    int x=0;
//    char ch=getchar();
//    while(ch<'0'||ch>'9'){
//        ch=getchar();
//    }
//    while(ch>='0'&&ch<='9'){
//        x=(x<<1)+(x<<3)+(ch^48);
//        ch=getchar();
//    }
//    return x;
//}
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
#define double long double
int n;
double len[101];
double ran(){
	double Tmp=rand()%50000+10000;
	return Tmp/1000;
}
int main(){
	scanf("%d",&n);
	srand(time(0));
	if(n<=4){
		puts("No solution");
		return 0;
	}
	rb(i,1,n) len[i]=500;
	double deg=3.1415926535897932384626433832795-(n-2)*3.1415926535897932384626433832795/n;
	rb(T,1,INF){
		bool bad=0;
		rb(i,1,n) rb(j,i+1,n) bad|=abs(len[i]-len[j])<0.002;
		if(bad){
			rb(i,1,n){
				double tmp=ran();
				len[i]+=tmp;
				len[(i+1)%n+1]+=tmp;
				len[i%n+1]-=2.0*cos(deg)*tmp;
			}
		}
		else break;
	}
	double x=0,y=0;
	vector<pair<double,double > >  ans;
	double d=0;
	rb(i,1,n){
		ans.PB(II(x,y));
		y+=sin(d)*len[i];
		x+=cos(d)*len[i];
		d+=deg;
	}
	for(auto it:ans){
		printf("%.3Lf %.3Lf\n",it.FIR,it.SEC);
	}
	return 0;
}