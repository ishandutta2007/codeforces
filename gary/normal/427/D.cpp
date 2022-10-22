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
string s1,s2;
int z[20000+10];
string s;
string tmp;
void calc(){
	memset(z,0,sizeof(z));
	int len=s.length()-1;
	int l_bound=2,r_bound;
	rb(i,2,len){
		if(s[i]!=s[i-1]) break;
		z[2]++;
	}
//	cout<<z[2];
	r_bound=2+z[2]-1;
	rb(i,3,len){
		if(i>r_bound){
			int ite=1;
			rb(j,i,len){
				if(s[j]!=s[ite++]) break;
				z[i]++;
			}
			l_bound=i;
			r_bound=z[i]+i-1;
		}
		else{
			z[i]=z[i-l_bound+1];
			z[i]=min(z[i],r_bound-z[i]+1);
			if(z[i]+i-1==r_bound){
				int ite=z[i]+1;
				rb(j,r_bound+1,len){
					if(s[j]!=s[ite++]) break;
					z[i]++;
				}
				l_bound=i;
				r_bound=i+z[i]-1;
			}
		}
//		cout<<z[i];
	}
}
int len1,len2;
int main(){
	cin>>s1>>s2;
	len1=s1.length(),len2=s2.length();
	s='%'+s1+'&'+s2;
	s1=" "+s1;
	s2=" "+s2; 
	int Start1,Start2;
	Start1=2;
	Start2=3+len1;
	int res=-1;
	rl(i,len1,1){
		Start1++;
		Start2++;
		s=s1[i]+s;
//		cout<<s<<endl; 
		tmp=s;
		s=" "+s;
//		cout<<"#";
		calc();
//		cout<<endl;
		int TMP=0;
		int MAXI=0;
		int OK=1;
		rb(j,Start1,Start1+len1-1){
			if(z[j]>TMP) {
				MAXI=TMP;
				TMP=z[j];
			}
			else MAXI=max(MAXI,z[j]);
		}
		rb(j,Start1,Start1+len1-1){
			if(z[j]==TMP) OK--;
		}
		if(OK==0){
				int TMP1=0;
				int OK1=1;
				int MAXI1=0;
//				cout<<Start2<<" "<<Start2+len2-1<<endl;
				rb(j,Start2,Start2+len2-1){
					if(z[j]>TMP1) {
						MAXI1=TMP1;
						TMP1=z[j];
					
					}
					else MAXI1=max(MAXI1,z[j]);
				}	
				rb(j,Start2,Start2+len2-1){
					if(z[j]==TMP1) OK1--;
				}
//				cout<<"FIRI"<<OK1<<" "<<TMP<<" "<<MAXI<<"--"<<TMP1<<" "<<MAXI1<<endl; 
				if(OK1==0){
					if(TMP1<TMP){
						if(MAXI>=TMP1) OK1=1; 
						TMP=TMP1;
					}
					else{
						if(TMP1>TMP){
							if(MAXI1>=TMP) OK1=1;
							TMP1=TMP;	
						}
					}
				}
//				cout<<OK1<<" "<<TMP<<" "<<MAXI<<"--"<<TMP1<<" "<<MAXI1<<endl; 
				if(OK1==0&&TMP1==TMP){
					TMP1=min(TMP1,max(MAXI+1,MAXI1+1));
					if(res==-1) res=TMP1;
					else res=min(res,TMP1);
				}
//				cout<<"RES:"<<res<<endl;
		}
		s=tmp;
	}
	cout<<res<<endl;
	return 0;
}