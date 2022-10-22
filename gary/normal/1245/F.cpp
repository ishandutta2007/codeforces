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
LL dp[35][2][2][2][2],dp2[35][2][2][2][2];//equal,bigger
LL process(string s){
	memset(dp,0,sizeof(dp));
	dp[0][0][0][0][0]=1;
	LL res=0;
	rb(i,1,s.length()-1){
		rb(j,0,1)
			rb(k,0,1)
			if(k+j<=1)
				rb(n,0,1)
					rb(m,0,1)
					{
						if(s[i]-'0'==j&&j==k)
							dp[i][j][k][0][0]+=dp[i-1][n][m][0][0];
						dp[i][j][k][1][1]+=dp[i-1][n][m][1][1];
						if(s[i]-'0'<j&&j==k)
							dp[i][j][k][1][1]+=dp[i-1][n][m][0][0];
						if(s[i]-'0'<j)
							dp[i][j][k][1][1]+=dp[i-1][n][m][0][1];
						if(s[i]-'0'<k)
							dp[i][j][k][1][1]+=dp[i-1][n][m][1][0];
						if(s[i]-'0'==j){
							dp[i][j][k][0][1]+=dp[i-1][n][m][0][1];
							if(k>j)
								dp[i][j][k][0][1]+=dp[i-1][n][m][0][0];
						}
						if(s[i]-'0'==k){
							dp[i][j][k][1][0]+=dp[i-1][n][m][1][0];
							if(j>k)
								dp[i][j][k][1][0]+=dp[i-1][n][m][0][0];
						}
					}
	}
	rb(i,0,1)
		rb(j,0,1)
			if(i+j<=1){
				res+=dp[s.length()-1][i][j][0][0]+dp[s.length()-1][i][j][0][1]+dp[s.length()-1][i][j][1][0]+dp[s.length()-1][i][j][1][1];
			}
			
//	cout<<res<<endl;
	return res;
}
LL process2(string s){
	memset(dp2,0,sizeof(dp2));
	dp2[0][0][0][0][0]=1;
	LL res=0;
	rb(i,1,s.length()-1){
		rb(j,0,1)
			rb(k,0,1)
			if(k+j<=1)
				rb(n,0,1)
					rb(m,0,1)
					{
						if(s[i]-'0'==j&&j==k)
							dp2[i][j][k][0][0]+=dp2[i-1][n][m][0][0];
						dp2[i][j][k][1][1]+=dp2[i-1][n][m][1][1];
						if(s[i]-'0'>j&&j==k)
							dp2[i][j][k][1][1]+=dp2[i-1][n][m][0][0];
						if(s[i]-'0'>j)
							dp2[i][j][k][1][1]+=dp2[i-1][n][m][0][1];
						if(s[i]-'0'>k)
							dp2[i][j][k][1][1]+=dp2[i-1][n][m][1][0];
						if(s[i]-'0'==j){
							dp2[i][j][k][0][1]+=dp2[i-1][n][m][0][1];
							if(k<j)
								dp2[i][j][k][0][1]+=dp2[i-1][n][m][0][0];
						}
						if(s[i]-'0'==k){
							dp2[i][j][k][1][0]+=dp2[i-1][n][m][1][0];
							if(j<k)
								dp2[i][j][k][1][0]+=dp2[i-1][n][m][0][0];
						}
					}
	}
//	cout<<s<<endl;
	rb(i,0,1)
		rb(j,0,1)
			if(i+j<=1){
				res+=dp2[s.length()-1][i][j][0][0]+dp2[s.length()-1][i][j][0][1]+dp2[s.length()-1][i][j][1][0]+dp2[s.length()-1][i][j][1][1];
			}
//	cout<<res<<endl;
	return res;
}
LL dp3[35][2][2][2][2]; 
LL process3(string s,string s2){
	memset(dp3,0,sizeof(dp3));
	dp3[0][0][0][0][0]=1;
	LL res=0;
	rb(i,1,s.length()-1){
		rb(j,0,1)
			rb(k,0,1)
			if(k+j<=1)
				rb(n,0,1)
					rb(m,0,1)
					{
						if(s[i]-'0'==j&&s2[i]-'0'==k)
							dp3[i][j][k][0][0]+=dp3[i-1][n][m][0][0];
						dp3[i][j][k][1][1]+=dp3[i-1][n][m][1][1];
						if(s[i]-'0'>j&&s2[i]-'0'<k)
							dp3[i][j][k][1][1]+=dp3[i-1][n][m][0][0];
						if(s[i]-'0'>j)
							dp3[i][j][k][1][1]+=dp3[i-1][n][m][0][1];
						if(s2[i]-'0'<k)
							dp3[i][j][k][1][1]+=dp3[i-1][n][m][1][0];
						if(s[i]-'0'==j){
							dp3[i][j][k][0][1]+=dp3[i-1][n][m][0][1];
							if(k>s2[i]-'0')
								dp3[i][j][k][0][1]+=dp3[i-1][n][m][0][0];
						}
						if(s2[i]-'0'==k){
							dp3[i][j][k][1][0]+=dp3[i-1][n][m][1][0];
							if(j<s[i]-'0')
								dp3[i][j][k][1][0]+=dp3[i-1][n][m][0][0];
						}
					}
	}
//	cout<<s<<endl;
	rb(i,0,1)
		rb(j,0,1)
			if(i+j<=1){
				res+=dp3[s.length()-1][i][j][0][0]+dp3[s.length()-1][i][j][0][1]+dp3[s.length()-1][i][j][1][0]+dp3[s.length()-1][i][j][1][1];
			}
//	cout<<res<<endl;
	return res;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int l,r;
		cin>>l>>r;
		int save1,save2;
		save1=l,save2=r;
		string s1,s2;
		s1=s2="";
		while(l){
			s1=((l&1)? '1':'0')+s1;
			l>>=1; 
		} 
		while(r){
			s2=((r&1)? '1':'0')+s2;
			r>>=1;
		}
		l=save1,r=save2;
		if(s2.length()>s1.length())
		rb(i,s1.length(),s2.length()-1){
			s1='0'+s1;
		}
//		cout<<s1<<endl;
		s1='0'+s1;
		s2='0'+s2;
//		cout<<"s"<<endl;
		string s3="";
		LL res=0;
		rep(i,s1.length()) s3+='0';
//		cout<<s1<<" "<<s2<<" "<<s3<<endl;
//		cout<<process(s1)<<" "<<process2(s2)<<" "<<process3(s1,s2)<<endl;
		res=process(s1)+process2(s2)-process(s3);
//		cout<<(1<<(int(ceil(log2(double(r+1))))))<<endl;
		if(1<<(int(ceil(log2(double(r+1)))))==r+1||l==0);
		else {
//		cout<<"s"<<endl;.
		l--,r++;
		s1=s2="";
		while(l){
			s1=((l&1)? '1':'0')+s1;
			l>>=1; 
		} 
		while(r){
			s2=((r&1)? '1':'0')+s2;
			r>>=1;
		}
		if(s2.length()>s1.length())
		rb(i,s1.length(),s2.length()-1){
			s1='0'+s1;
		}
//		cout<<s1<<endl;
		s1='0'+s1;
		s2='0'+s2;
//		cout<<"s"<<" "<<s1<<" "<<s2<<endl;
		res+=process3(s1,s2)*2;
		}	
		printf("%I64d\n",res); 
	}
	return 0;
}