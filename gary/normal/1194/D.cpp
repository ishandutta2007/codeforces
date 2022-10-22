//* AuThOr GaRyMr *//
//AFT ST
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
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		
		if(n==0){
			cout<<"Bob"<<endl;
			continue;
		}
		if(n==1||n==2||n==k){
			cout<<"Alice"<<endl;
			continue;
		}
		if(k%3==0){
			int res=n%(k+1);
			if(res%3==0&&res!=k){
				cout<<"Bob"<<endl;
			}
			else{
				cout<<"Alice"<<endl;
			}
		}
		else{
			if(n%3==0){
				cout<<"Bob"<<endl;
			}
			else{
				cout<<"Alice"<<endl;
			}
		}
	}
	return 0;
}