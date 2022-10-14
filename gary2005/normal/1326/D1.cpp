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
int z[2000000+20];
void z_function(string S){
	int len=S.length();
	S='$'+S;
	int l,r;
	rb(i,0,len+10)
		z[i]=0;
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

string solve(string s){
	string tmp="";
	tmp+=s;
	tmp+='*';
	reverse(ALL(s));
	tmp+=s;
	reverse(ALL(s));
	z_function(tmp);
	int n=s.length();
	string res="";
	rb(i,1,n){
		if(i+i>n){
			tmp=s;
			s="";
			rb(j,i,n-(i-1)){
				s+=tmp[j-1];
			}
			tmp=s;
			reverse(ALL(tmp));
			z_function(s+'*'+tmp);
			break;
		}
		if(z[n+2]>=i){
			res+=s[i-1];
		}
		else{
			tmp=s;
			s="";
			rb(j,i,n-(i-1)){
				s+=tmp[j-1];
			}
			tmp=s;
			reverse(ALL(tmp));
			z_function(s+'*'+tmp);
			break;
		}
	}
	tmp=res;
	reverse(ALL(tmp));
	rl(i,s.length(),1){
		if(z[s.length()*2+1-i+1]==i){
			rb(j,1,i){
				res+=s[j-1];
			}
			break;
		}
	}
	res+=tmp;
	return res;
}
int main(){
	fastio;
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		string res1=solve(s);
		reverse(ALL(s));
		string res2=solve(s);
		if(res2.length()>res1.length()){
			res1=res2;
		}
		cout<<res1<<endl;
	}
	return 0;
}