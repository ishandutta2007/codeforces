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
#define CS char(1)
/*
KEY IDEA:
zrb+a
mosti
zra+b
best[i]->ia
zb+a
finalz[i]=z[i+len1]
string a 1mosti
int tmpj=len1-best[len1-i]+1
if(finalz[i+1]+i>=tmpj-1) if(tmpj<RES.SEC||!RES.SEC) RES={i,tmpj}
cout<<RES.FIR-1<<" "<<RES>SEC-1<<endl;
*/
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int best[1000000+10];
string a,b;
string ra="",rb="";
string s;
int mosti;
int len1,len2;
int z[2000000+10];
int flag[1000000+10]; 
int finalz[1000000+10]; 
void calc(){
	memset(z,0,sizeof(z));
	int n=s.length();
	s=' '+s;
	int l_bound,r_bound;
	rb(i,2,n){
		if(s[i]!=s[i-1]){
			 break;
		}
		z[2]++; 
	}
	l_bound=2,r_bound=z[2]+1;
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
				l_bound=i,r_bound=z[i]+i-1;
			}
		}
		else{
			int ite=1;
			rb(j,i,n){
				if(s[j]!=s[ite++]) break;
				z[i]++;
			}
			l_bound=i;
			r_bound=i+z[i]-1;
		}
	}
}
int main(){
	getline(cin,a);
	getline(cin,b);
	len1=a.length(),len2=b.length();
	if(len1!=len2) {
		puts("-1 -1");
		return 0;
	}
	rl(i,len1-1,0) ra+=a[i];
	rl(i,len1-1,0) rb+=b[i];
	s=rb+a;
	calc();
	mosti=z[len1+1];
	s=ra+b;
	calc();
	rb(i,1,len1){
		int is=i+len1;
		flag[i]=z[is];
	}
	int go_to=0;
	rb(i,1,len1){
		if(flag[i]){
			rb(j,max(go_to+1,i),i+flag[i]-1){
				go_to=j;
				best[j]=j-i+1;
			}
		}
	}
	s=b+a;
	calc();
	rb(i,1,len1){
		finalz[i]=z[i+len1];
	}
	mp RES={0,0};
	rb(i,1,mosti){
		if(i==len1) break;
		int tmpj=len1-best[len1-i]+1;
		if(finalz[i+1]+i>=tmpj-1) RES={i,tmpj};
	}
	cout<<RES.FIR-1<<" "<<RES.SEC-1<<endl;
	return 0;
}