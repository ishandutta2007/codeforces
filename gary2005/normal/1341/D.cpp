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
#define debug_pair(A) cerr<<A.FIR<<" "<<A.SEC<<endl;
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
string num[10]={"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
map<string,int> m;
int diff(string s1,string s2){
	//s2->s1
	int res=0;
	rep(i,7)
	{
		if(s2[i]=='1'&&s1[i]=='0') return -1;
		if(s1[i]=='1'&&s2[i]=='0') res++;
	}
	return res;
}
bool dp[2000+20][2000+2];
int n,k;
int main(){
	fastio;
		cin>>n>>k;
	rep(i,10)
		m[num[i]]=i;
	string s[2000+20];
	dp[n+1][0]=1;
	rb(i,1,n) cin>>s[i];
	rl(i,n,1){
//		cin>>s[i];
		rep(j,k+1)
		{
			rep(K,10){
				int difff=diff(num[K],s[i]);
				if(difff>=0&&j>=difff){
					dp[i][j]|=dp[i+1][j-difff];
				}
			}
		}
	}
	if(!dp[1][k]){
		cout<<-1<<endl;
	}
	else{
		int rest=k;
		rb(i,1,n){
			rl(K,9,0){
				int difff=diff(num[K],s[i]);
//				cout<<s[i]<<endl;
				if(difff>=0&&rest>=difff){
//					cout<<K<<endl;
					if(dp[i+1][rest-difff]){
						cout<<K;
						rest-=difff;
						break;	
					}
				}
			}
		}
	}
	return 0;
}