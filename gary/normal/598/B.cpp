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
pair<char,mp/*before&after index*/> each[10000+10];
string s; 
void Process(int l,int r,int k){
	string tmp_save=s;
	k%=(r-l+1);
	rb(i,l,r){
		int from=i-k;
		if(from<l){
			from=l-from;
			from=r-from;
			from++;
		}
		s[i-1]=tmp_save[from-1];
	}
}
int main(){
	cin>>s;
	int len=s.length();
	int m;
	cin>>m;
	while(m--){
		int li,ri,ki;
		scanf("%d %d %d",&li,&ri,&ki);
		Process(li,ri,ki);
//		cout<<s<<endl;
	}
	cout<<s;
	return 0;
}