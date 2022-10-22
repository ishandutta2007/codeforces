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
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int main(){
	int n;
	int look=3;
	cin>>n;
	rb(i,1,n){
		int win;
		cin>>win;
		if(win==look){
			puts("NO");
			return 0;
		}
		if(win==1){
			if(look==2){
				look=3;
			}
			else{
				look=2;
			}
		} 
		else{
			if(win==2){
				if(look==1){
					look=3;
				}
				else{
				look=1;
				}
			}
			else{
				if(look==1){
					look=2;
				}
				else{
					look=1;
				}
			}
		}
	}
	puts("YES");
	return 0;
}