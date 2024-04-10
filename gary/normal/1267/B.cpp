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
int tot=0;
int len;string s;
bool check(int now){
	int r=now,l;
	rl(i,r,0){
		if(s[r]==s[i]){
			l=i;
		} 
		else break;
	}
	l--;
	r++;
//	cout<<now<<" "<<l<<" "<<r<<endl;
	vector<pair<char,int > > V1,V2;
	char pev='1';
	int len1=0;
	rb(i,r,len-1){
		len1++;
		if(s[i]!=pev){
			if(pev!='1')
			V1.PB(II(pev,len1-1));
			len1=1;
			pev=s[i];
		}	
	}
	V1.PB(II(pev,len1));
	pev='1';
	len1=0;
	rl(i,l,0){
		len1++;
		if(s[i]!=pev){
			if(pev!='1')
			V2.PB(II(pev,len1-1));
			len1=1;
			pev=s[i];
		}	
	}
	
	V2.PB(II(pev,len1));
	if(V1.size()!=V2.size())
	return 0;
	int SZ=V1.size();	
	rep(i,SZ){
		if(V1[i].FIR!=V2[i].FIR){
			return 0;
		}
		if(V1[i].SEC+V2[i].SEC<3){
			return 0;
		}
	}
	return 1;
}
int main(){
	
	cin>>s;
	char prev='1';
	len=s.length();
	tot--;
	rep(i,len){
		if(s[i]!=prev){
			tot++;
			prev=s[i];
		}
	}
	tot++;
	if(tot%2==0){
		cout<<0<<endl;
	}
	else{
		int tmp=tot/2+1,len1=0;
		prev='1';
		tot=-1;	 
		rep(i,len){
			len1++;
			if(s[i]!=prev){
			tot++;
			if(tot==tmp){
				if(!check(i-1)){
					cout<<0<<endl;
					return 0;
				}
				len1--;
				if(len1<2){
					cout<<0<<endl;
				}
				else cout<<len1+1<<endl;
				return 0;
			}
			len1=1;
			prev=s[i];
			}
		}
		tot++;
		if(tot==tmp){
			if(len1<2){
					cout<<0<<endl;
			}
			else cout<<len1+1<<endl;
			return 0;
		}
	}
	return 0;
}