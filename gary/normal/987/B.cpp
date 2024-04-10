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
//#defind FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int main(){
	int y,x;
	cin>>y>>x;
	if(y<x){
		if(y==1){
			puts("<");
			return 0;
		}
		if(y==2&&x==3){
			puts("<");
			return 0;
		}
		if(y==2&&x==4){
			puts("=");
		}
		else{
			puts(">");
		}
	}
	else{
		if(y>x){
			if(x==1){
				puts(">");
				return 0;
			}
			if(x==2&&y==3)
			{
				puts(">");
				return 0;
			}
			if(y==4&&x==2){
				puts("=");
			}
			else{
				puts("<");
			}
		}
		else{
			puts("=");
		}
	}
	return 0;
}