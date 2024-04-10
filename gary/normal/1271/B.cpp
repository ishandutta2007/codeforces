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
8. CSPday2 meal
9.-or
10.
11.
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
#define POB pop_back
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
vector<int> res;
int main(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	int A,B;
	rep(i,s.length()){
		if(s[i]=='W'){
			A++;
		}
		else{
			B++;
		}
	} 
	if((A&1)&&(B&1)){
		puts("-1");
		return 0;
	}
	else{
		if(A&1){
			rep(i,s.length()){
				if(s[i]=='B'){
					res.PB(i);
					for(i=i+1;i<s.length();i++){
						if(s[i]=='B'){
							break;
						}
						res.PB(i);
					}
				}
			}
		} 
		else{
			rep(i,s.length()){
				if(s[i]=='W'){
					res.PB(i);
					for(i=i+1;i<s.length();i++){
						if(s[i]=='W'){
							break;
						}
						res.PB(i);
					}
				}
			}
		}
	}
	cout<<res.size()<<endl;
	for(auto it:res){
		cout<<it+1<<" ";
	}
	return 0;
}