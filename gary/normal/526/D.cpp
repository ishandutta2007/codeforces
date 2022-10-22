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
int n,k;
string s;
int z[1000000+10];
void calc(){
	rb(i,2,n)
	{
		if(s[i]!=s[i-1]) break;
		z[2]++;
	}
	int l_bound,r_bound;
	l_bound=2;
	r_bound=2+z[2]-1;
	rb(i,3,n){
		if(i<=r_bound){
			z[i]=z[i-l_bound+1];
			z[i]=min(z[i],r_bound-i+1);
			if(z[i]+i-1==r_bound){
				int ite=z[i]+1;
				rb(j,r_bound+1,n){
					if(s[j]!=s[ite++]) break;
					z[i]++;
				}
				l_bound=i;
				r_bound=i+z[i]-1;
			}
		}
		else{
			int ite=1;
			rb(j,i,n){
				if(s[j]!=s[ite++]) break;
				z[i]++;
			}
			l_bound=i;
			r_bound=z[i]+i-1;
		}
	}
}
int start[1000000+10],end[1000000+10];
int main(){
	cin>>n>>k;
	cin>>s;
	s='@'+s;
	calc();
	z[1]=n;
	rb(i,1,n){
		if((LL)(i)*k<=n){
			if(z[i+1]>=(k-1)*i){
//				cout<<i*k-1<<" "<<min(i*(k+1),z[i+1]+i)<<endl;
				start[i*k]++;
//				cout<<i*(k+1)<<endl;
				start[min(i*(k+1)+1,z[i+1]+i+1)]--;
			}
//			int cnt=1;
//			for(int j=1;j<=n&&cnt<=k;j+=i,cnt++){
//				if(z[j]<i) break;
//				if(cnt==k){
//					start[j+i-1]++;
//					start[min(n+1,j+i+min(z[j+i],i))]--;
//				}
//			}
		}
	}
	rb(i,1,n){
		start[i]+=start[i-1];
		if(start[i]>0) cout<<"1";
		else cout<<"0";
	}
	return 0;
}