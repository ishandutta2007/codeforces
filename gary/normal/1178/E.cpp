//* AuThOr GaRyMr *//
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define niv vector<int>
#define LL long long
#define U unsigned
#define IT iterator
#define PB(a) push_back(a)
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
map<int,int> FIR_APP;
string L;
string M;
int main(){
	string s;
	cin>>s;
	int len=s.length();
	rb(i,0,len-1){
		FIR_APP[s[i]]=(FIR_APP[s[i]])? FIR_APP[s[i]]:i;
	}
	int l=0,r=len-1;
	while(l<=r){
		if(l==r){
			M+=s[l];
			break;
		}
		if(s[l]==s[r]){
			L+=s[l];
			l++;
			r--;
		}
		else{
			if(s[l]==s[r-1]){
				if(r-1!=l)
				L+=s[l];
				else{
					M+=s[l];
				}
				l++;
				r-=2;
			}
			else{
				if(s[l+1]==s[r]){
					if(l+1!=r)
					L+=s[r];
					else{
						M+=s[r];
					}
					l+=2;
					r--;
				}
				else{
					if(l+1!=r-1)
					L+=s[l+1];
					else{
						M+=s[l+1];
					}
					l+=2;
					r-=2;
				}
			}
		}
	}
	int LT=L.length();
	rb(i,0,LT-1){
		cout<<L[i];
	}
	cout<<M;
	rl(i,LT-1,0){
		cout<<L[i];
	}
	return 0;
}