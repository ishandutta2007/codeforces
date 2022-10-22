//* AuThOr GaRyMr *//
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define niv vector<int>
#define LL long long
#define IT iterator
#define PB(a) push_back(a)
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int n;
string s;
int z[1000000+10];
void calc(){
	rb(i,2,n){
		if(s[i]!=s[i-1]) break;
		z[2]++;
	}
	int l_bound=2,r_bound=2+z[2]-1;
	rb(i,3,n){
		if(i<=r_bound){
			z[i]=z[i-l_bound+1];
			z[i]=min(z[i],r_bound-i+1);
			if(z[i]+i-1==r_bound){
				int ite=z[i]+1;
				rb(j,r_bound+1,n){
					if(s[j]!=s[ite++]){
						break;
					}
					z[i]++;
				}
				l_bound=i;
				r_bound=z[i]+i-1;
			}
		}
		else{
			int ite=1;
			rb(j,i,n) {
				if(s[j]!=s[ite++]){
					break;
				}
				z[i]++;
			}
			l_bound=i;
			r_bound=i+z[i]-1;
		}
	}
}
int main(){
	cin>>s;
	n=s.length();
	s='$'+s;
	calc();
	int LEN1,LEN2;
	LEN1=0,LEN2=0;
//	int LEN3=0;
	rb(i,2,n){
//		cout<<z[i]<<" ";
		if(z[i]+i-1==n){
			if(z[i]>LEN2) {
				LEN2=z[i];
			}
		}
		else{
			LEN1=max(LEN1,z[i]);
		}
	}
	LEN1=max(LEN1,LEN2-1);
//	cout<<LEN2<<" "<<LEN3<<endl;
	if(LEN1==0||LEN2==0) {
		puts("Just a legend");
	}
	else{
		int res=min(LEN1,LEN2);
		int RES=-1;
		rl(i,res,1){
			if(z[n-i+1]==i){
				RES=i;
				break;
//				return 0;
			}
		}
		if(RES==-1){
			puts("Just a legend");
		}
		else{
			rb(i,1,RES) cout<<s[i];
		}
	} 
	return 0;
}