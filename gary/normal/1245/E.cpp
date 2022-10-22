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
double dp[101];
vector<int> from[101];int mark[101],arr[101];
int translate_(int x,int y){
	return (10-x)*10+((x&1)? 10-y+1:y);
}
int main(){
	rb(i,1,10){
		rb(j,1,10){
			int labber;
			cin>>labber;
			if(labber){
				arr[translate_(i,j)]=translate_(i-labber,j);
			}
		}
	}
	rb(i,95,100) dp[i]=6.0;
	dp[100]=0.0;
	rl(i,94,1){
//		cout<<i<<endl;
		rb(j,1,6){
			if(arr[i+j])
			dp[i]+=min(dp[i+j],dp[arr[i+j]]);
			else 
			dp[i]+=dp[i+j];
		}
		dp[i]/=6.0;
		dp[i]+=1.0;
	}
	printf("%.10f\n",dp[1]);
	return 0;
}