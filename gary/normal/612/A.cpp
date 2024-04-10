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
int main(){
	int n,q,p;
	cin>>n>>q>>p;
	int OK=-INF;
	string s;
	cin>>s;
	rb(i,0,n){
		if(i*q>n) break;
		if((n-i*q)%p==0){
			OK=i;
			break;
		}
	}
	if(OK==-INF){
		cout<<-1<<endl;
		return 0;
	}
	printf("%d\n",OK+(n-OK*q)/p);
	int now=0;
	rb(i,1,OK){
		rb(i,1,q){
			cout<<s[now+i-1];
		}
		cout<<endl;
		now+=q;
	}
	rb(i,1,(n-OK*q)/p){
		rb(i,1,p){
			cout<<s[now+i-1];
		}
		cout<<endl;
		now+=p;
	}
	return 0;
}//