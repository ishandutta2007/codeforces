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
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
vector<int> z;
const int MAXN=300000+20;
void z_function(string S){
	int len=S.length();
	S='$'+S;
	int l,r;
	z=vector<int> (MAXN+10,0);
	rb(i,2,len)
		if(S[i]!=S[i-1]) break;
		else z[2]++;
	l=2,r=z[2]+1;
	rb(i,3,len){
		if(i<=r){
			z[i]=z[i-(l)+1];
			z[i]=min(z[i],r-i+1);
			if(z[i]+i-1==r){
				int ite=z[i]+1;
				rb(j,r+1,len){
					if(S[j]!=S[ite++]) break;
					z[i]++;
				}
				l=i,r=i+z[i]-1;
			}
		}
		else{
			int ite=1;
			rb(j,i,len){
				if(S[j]!=S[ite++]) break;
				z[i]++;
			}
			l=i,r=i+z[i]-1;
		}
	}
}
string s[3],merge[3][3];
string best(string A,string B){
	z_function(B+'&'+A);
	rb(i,B.length()+2,A.length()+B.length()+1){
//		cout<<i<<" "<<z[i]<<endl;
		if(z[i]==B.length()||z[i]+i-1==A.length()+B.length()+1){
			string res;
			res=A;
			rb(j,z[i],B.length()-1){
				res+=B[j];
			}
			return res;
		}
	}
	return A+B;	
}
int main(){
	fastio;
	rep(i,3)
		cin>>s[i];
	int res=INF;
	rep(i,3)
		rep(j,3)
			if(i!=j){
				int k=3-i-j;
				res=min((int)(best(best(s[i],s[j]),s[k]).length()),(res));
			}
//	cout<<best("abcd","bc")
	cout<<res<<endl;
	return 0;
}