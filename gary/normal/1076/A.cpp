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
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
string s;
int main(){
	int n;
	scanf("%d",&n);
	cin>>s;
	int posi=n-1;
	rb(i,0,n-2){
		if(s[i]>s[i+1])
		{
			posi=i;
			break;
		}
	}
	rb(i,0,n-1){
		if(i==posi){
			continue;
		}
		cout<<s[i];
	}
	return 0;
	
}