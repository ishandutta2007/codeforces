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
const int MAXLEN=1000000;
struct z_algorithm{
	int z[MAXLEN+10];
	void z_function(string S){
	int len=S.length();
	S='$'+S;
	int l,r;
	memset(z,0,sizeof(z));
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
}Z;
int s1,s2,t1,t2;
int main(){
	fastio;
	string s,t;
	cin>>s>>t;
	Z.z_function(string(t+'#'+t));
	int st=1;
	int n,m;
	n=s.length(),m=t.length();
	rep(i,n)
		if(s[i]=='1') s1++;
		else s2++;
	rep(i,m)
		if(t[i]=='1') t1++;
		else t2++;
	if(s1<t1||s2<t2){
		cout<<s<<endl;
		return 0;
	}
	int it=2;
	rb(i,m+3,m+m+1){
		if(Z.z[i]+(it++)-1==m){
			st=Z.z[i]+1;
			break;
		}
	}
	int cnt=1;
	s1-=t1,s2-=t2;
	t1=t2=0;
	rb(i,st,m){
		if(t[i-1]=='1') t1++;
		else t2++;
	}
	while(s1>=t1&&s2>=t2){
		cnt++;
		s1-=t1;
		s2-=t2;
	} 
	cout<<t;
	rb(i,2,cnt){
		rb(j,st,m){
			cout<<t[j-1];
		}
	}
	rb(i,1,s1) cout<<'1';
	rb(i,1,s2) cout<<'0';
	return 0;
}